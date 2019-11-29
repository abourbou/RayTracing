/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   surface_normal_vect.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 10:40:30 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 13:39:15 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ray_tracing.h"
#include "../include/shapes.h"

/*
**  SURFACE_NORMAL_VECT
**  calcul le vecteur normal a la surface au niveau de l'intersection
*/

static void    s_u_v_sphere(t_sp *sp, double intersect[3], double result[3])
{
    vec_of_2_points(sp->pos, intersect, result);
}

void    surface_normal_vect(t_obj *l_obj, double intersect[3], double result[3])
{
    if (l_obj->type == _sphere)
        s_u_v_sphere(l_obj->obj, intersect, result);    
}