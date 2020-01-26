/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cal_coord.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 09:15:20 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

/*
** PIX_COORD
** calcul des coordonnes du pixel
** avec P = first_pixel - i * v + j * u
*/

void		pix_coord(t_vect pos_pix, float i, float j, t_ref *ref)
{
	t_vect	buffer;

	multvec(-i * PIXELHEIGHT, ref->v, buffer);
	addvec(ref->fst_pix, buffer, pos_pix);
	multvec(j * PIXELWIDTH, ref->u, buffer);
	addvec(pos_pix, buffer, pos_pix);
}

/*
**  INIT_UV_REF
**  initialise les vecteurs u et v a partir d'un vecteur normal
**  afin de former un referenciel
*/

void		init_uv_ref(t_vect normal, t_vect u, t_vect v)
{
	t_vect	buffer;

	if (is_null(normal[0]) && is_null(normal[2]))
		init_vec(buffer, 0, 0, (normal[1] > 0 ? -1 : 1));
	else
		init_vec(buffer, 0, 1, 0);
	cross_prod(buffer, normal, u);
	cross_prod(normal, u, v);
	norme_vec(u);
	norme_vec(v);
}

/*
**  SQUARE_COORD
**  calcul des coordonnes du triangle 1 ou 2 qui forme le carré
**  tq : tr1(O, O + H * u, O + H * u + H * v)
**       tr2(O, O + H * v, O + H * u + H * v)
*/

static void	init_square_coord(t_sq *sq, t_ref *ref, float side)
{
	t_vect	buffer;
	t_tr	*tr1;
	t_tr	*tr2;

	tr1 = &sq->triangle[0];
	tr2 = &sq->triangle[1];
	vec_copy(tr1->points[0], ref->fst_pix);
	vec_copy(tr2->points[0], ref->fst_pix);
	multvec(side, ref->v, buffer);
	addvec(tr1->points[0], buffer, tr1->points[1]);
	multvec(side, ref->u, buffer);
	addvec(tr1->points[1], buffer, tr1->points[2]);
	multvec(side, ref->u, buffer);
	addvec(tr2->points[0], buffer, tr2->points[1]);
	multvec(side, ref->v, buffer);
	addvec(tr2->points[1], buffer, tr2->points[2]);
}

/*
**  INIT_REF_SQUARE
**  Calcul du referenciel du carré, ce réferenciel nous donnera ensuite
**  la position des 4 cotes du carre que l'on decoupera en deux triangle
**  le point d'origine du referenciel est en bas a gauche
*/

void		init_ref_square(t_obj *l_obj)
{
	t_sq	*sq;
	t_vect	buffer;
	t_ref	ref;

	while (l_obj)
	{
		if (l_obj->type == _square)
		{
			sq = l_obj->carac;
			init_uv_ref(sq->normal, ref.u, ref.v);
			if (sq->angle > EPSILON && sq->angle < 90.0)
				rotation(sq->normal, sq->angle, ref.u, ref.u);
			if (sq->angle > EPSILON && sq->angle < 90.0)
				rotation(sq->normal, sq->angle, ref.v, ref.v);
			multvec(sq->side * 0.5, ref.u, buffer);
			minusvec(sq->pos, buffer, ref.fst_pix);
			multvec(sq->side * 0.5, ref.v, buffer);
			minusvec(ref.fst_pix, buffer, ref.fst_pix);
			init_square_coord(sq, &ref, sq->side);
		}
		l_obj = l_obj->next;
	}
}

/*
**  INIT_REF_CYLINDER
**  calcul du referenciel du cylindre
**  (rend les calculs des intersections
**  plus rapide)
*/

void		init_ref_cylinder(t_obj *l_obj)
{
	t_cy	*cyl;

	while (l_obj)
	{
		if (l_obj->type == _cylinder)
		{
			cyl = l_obj->carac;
			init_uv_ref(cyl->normal, cyl->ref.u, cyl->ref.v);
		}
		l_obj = l_obj->next;
	}
}
