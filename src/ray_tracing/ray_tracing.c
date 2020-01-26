/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_tracing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 15:16:24 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:39:53 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

/*
** CALCUL DU BORD DE L'ECRAN ET DES DEUX VECTEURS COORDONNES
**
**  pos centre ecran
**  E = C + dist * vec_view
**  avec                dist = L * PIXELWIDTH / (2 * tan(theta / 2))
**                      theta est la FOV largueur
**                      vec_view est le vecteur direction de la vue
**                      C est la position de l'oeil
**                      E position du centre de l'ecran
**
**  calcul des deux vecteurs u et v qui serviront de transformer
**  la position des pixels dans notre espace 3D
**
**  v = [0,1,0] (le vecteur y) par defaut
**  sauf si w est parallele a y, v =[0, 0, +/-1] (le vecteur z positif si tu
**  regarde en bas et negatif si tu regardes en haut)
**  u = w ^ up_vec   avec up_vec = y ou si w est parallele a y, up_vec = x
**  v = u ^ w
**
**  calcul du pixel en haut a gauche de l'ecran
**  first_pixel = C - L/2 * u * PIXELWIDTH + H / 2 * v * PIXELHEIGHT
**	+ PIXELWIDTH / 2 * u - PIXELHEIGHT / 2 * v
*/

float	ft_pix_coord(t_c *cam, t_r *res, t_ref *ref)
{
	t_vect	w;
	t_vect	buffer;
	float	dist;

	dist = res->x * PIXELWIDTH / (2.0 * tan(cam->fov / 360 * (float)M_PI));
	vec_copy(w, cam->vec);
	multvec(dist, w, buffer);
	addvec(cam->pos, buffer, ref->fst_pix);
	init_uv_ref(w, ref->u, ref->v);
	multvec(res->x * 0.5 * PIXELWIDTH, ref->u, buffer);
	minusvec(ref->fst_pix, buffer, ref->fst_pix);
	multvec(res->y * 0.5 * PIXELHEIGHT, ref->v, buffer);
	addvec(ref->fst_pix, buffer, ref->fst_pix);
	multvec(PIXELWIDTH * 0.5, ref->u, buffer);
	addvec(ref->fst_pix, buffer, ref->fst_pix);
	multvec(PIXELHEIGHT * 0.5, ref->v, buffer);
	minusvec(ref->fst_pix, buffer, ref->fst_pix);
	return (dist);
}

/*
**  INTERSECT
**  grosse fonction qui sert a calculer l'intersections la plus proche
**  avec les objets, ce calcul depends de l'objet
**  si l'intersection est la plus proche, on change les valeurs de inters
**  point_of_vec sert a trouver le point d'intersection a partir de la distance
*/

void	search_inters(t_line *line, t_obj *lst_obj, t_inters *inters,
														int is_light)
{
	float	dist;

	while (lst_obj)
	{
		dist = g_resolv[lst_obj->type](lst_obj->carac, line->orig, line->ray);
		if (dist > EPSILON && dist < inters->dist)
		{
			inters->dist = dist;
			inters->obj_inters = lst_obj;
		}
		lst_obj = lst_obj->next;
	}
	if (inters->dist != HUGE_VALF)
	{
		vec_to_point(line->orig, line->ray, inters->dist, inters->point);
		if (!is_light)
		{
			surface_normal_vect(inters->obj_inters, inters->point,
									line->ray, inters->normal);
			vec_copy(inters->color, inters->obj_inters->color);
		}
	}
}

/*
**  CALCUL INTERSECTION OBJET
**  calcul d'abord les coordonnees du pixel puis le rayon qui va de l'oeil au
**	pixel et enfin trouve l'intersectin la plus proche avec un objet
**	(ou l'intersection reste nulle si pas trouve)
*/

void	calc_inters_obj(t_line *line, t_param *param, t_inters *inters,
															t_vect coord)
{
	inters->dist = HUGE_VALF;
	pix_coord(line->orig, coord[0], coord[1], &param->ref);
	vec_of_2_points(param->cam->pos, line->orig, line->ray);
	search_inters(line, param->lst_obj, inters, 0);
}

/*
**  LET_THERE_BE_LIGHT
**  algo pour ajouter les lumieres
**  inters_l->normal contient le rayon de l'objet vers
**  la source de lumiere
**  inters_l->couleur contient la couleur de la lumiere
**  line_l est le rayon de lumiere
*/

void	let_there_be_light(t_param *param, t_line *line, t_vect final_color,
													t_inters *inters_obj)
{
	t_inters	inters_l;
	t_l			*light;
	t_line		line_l;

	add_al(&param->al, inters_obj, final_color);
	light = param->l;
	while (light)
	{
		inters_l.dist = HUGE_VALF;
		multvec(-1.0, line->ray, line->ray);
		vec_copy(line_l.orig, light->pos);
		vec_of_2_points(light->pos, inters_obj->point, line_l.ray);
		search_inters(&line_l, param->lst_obj, &inters_l, 1);
		if (inters_l.dist != HUGE_VALF && vec_cmp(inters_l.point,
												inters_obj->point))
		{
			multvec(light->ratio, light->color, inters_l.color);
			multvec(-1.0, line_l.ray, inters_l.normal);
			add_val_diffus(inters_obj, &inters_l, final_color);
			add_val_specul(inters_obj, &inters_l, final_color, line->ray);
		}
		light = light->next;
	}
}

/*
**  RAY_TRACING
**  algo principale
**  etape 1 : calculer la position du pixel dans l'espace 3D avec le referenciel
**  ref grace a pix_coord et en deduire la vecteur rayon avec calc_view
**  vecteur qui est normé
**  etape 2 : on calcule l'intersections avec les objets et trouver la plus
**	courte sinon intersection est egale a infinie
**  etape 3 : si l'on a trouvé une intersection, on calcule la couleur
*/

void	ray_tracing(t_param *param, float width, float height,
										unsigned int *tab_img)
{
	float		ij[2];
	t_vect		pixel;
	t_vect		color;
	t_line		line;
	t_inters	inters_obj;

	ij[0] = 0;
	init_ref_square(param->lst_obj);
	init_ref_cylinder(param->lst_obj);
	while (ij[0] < height)
	{
		ij[1] = 0;
		while (ij[1] < width)
		{
			init_vec(color, 0, 0, 0);
			init_vec(pixel, ij[0], ij[1], 0);
			calc_inters_obj(&line, param, &inters_obj, pixel);
			if (inters_obj.dist != HUGE_VALF)
				let_there_be_light(param, &line, color, &inters_obj);
			tab_img[(unsigned int)ij[0] * (unsigned int)width +
			(unsigned int)ij[1]] = conv_color(color);
			ij[1] += 1;
		}
		ij[0] += 1;
	}
}
