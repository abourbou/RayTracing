/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   surface_normal_vect.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 10:40:30 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

static void	normal_triangle(t_tr *tr, t_vect result)
{
	t_vect	d1;
	t_vect	d2;

	minusvec(tr->points[1], tr->points[0], d1);
	minusvec(tr->points[2], tr->points[0], d2);
	cross_prod(d1, d2, result);
	norme_vec(result);
}

static void	normal_cyl(t_cy *cyl, t_vect intersect, t_vect result)
{
	float	height;
	t_vect	center_to_inters;

	init_vec(result, 0, 0, 0);
	minusvec(intersect, cyl->pos, center_to_inters);
	height = scal_prod(center_to_inters, cyl->normal);
	if (fabsf(height) < cyl->height / 2.0 - EPSILON)
	{
		multvec(scal_prod(center_to_inters, cyl->normal), cyl->normal, result);
		minusvec(center_to_inters, result, result);
		norme_vec(result);
	}
	else
		vec_copy(result, cyl->normal);
}

/*
**  calcul le vecteur normal a la surface au niveau de l'intersection
*/

void		surface_normal_vect(t_obj *l_obj, t_vect intersect,
			t_vect direct, t_vect result)
{
	if (l_obj->type == _sphere)
		vec_of_2_points(((t_sp *)l_obj->carac)->pos, intersect, result);
	else if (l_obj->type == _plane)
		vec_copy(result, ((t_pl *)l_obj->carac)->normal);
	else if (l_obj->type == _triangle)
		normal_triangle(l_obj->carac, result);
	else if (l_obj->type == _square)
		vec_copy(result, ((t_sq *)l_obj->carac)->normal);
	else if (l_obj->type == _cylinder)
		normal_cyl(l_obj->carac, intersect, result);
	if (scal_prod(result, direct) > 0)
		multvec(-1.0, result, result);
}
