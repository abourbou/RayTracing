/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   intersect_resolv.h                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 10:46:47 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef INTERSECT_RESOLV_H
# define INTERSECT_RESOLV_H

# include "raytracing.h"

typedef float	(*t_resolv)(void *, t_vect, t_vect);

t_resolv	g_resolv[_size];

/*
**  INTERSECT_RESOLV.C
*/
void	setup_resolv(void);
float	resol_polyn_circ(float b, float c);
float	resolv_circle(void *carac, t_vect pos, t_vect direction);
float	resolv_plane(void *carac, t_vect pos, t_vect direction);
float	resolv_triangle(void *carac, t_vect pos, t_vect direction);

/*
**  INTERSECT_RESOLV2.C
*/
float	resolv_square(void *carac, t_vect pos, t_vect direction);
float	resolv_cylinder(void *carac, t_vect pos, t_vect direction);

/*
**	INTERSECT_CYL.C
*/
int		resolv_polyn_cyl(float a, float b, float c, float sol[2]);
void	coeff_polyn_cyl(t_cy *cyl, t_vect direction, t_vect ray_to_cyl,
			t_vect coeff_polyn);

#endif
