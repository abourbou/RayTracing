/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vect3.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 18:49:38 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

/*
**  calcule la position d'un point a partir d'un point d'origine, d'une
**	direction caracterise par un vecteur norme ainsi que d'une distance par
**	rapport au point d'origine
*/

void	vec_to_point(t_vect origin, t_vect vect_direct, float dist,
														t_vect result)
{
	t_vect	buffer;

	multvec(dist, vect_direct, buffer);
	addvec(origin, buffer, result);
}

/*
**      permet de trouver le vecteur norme entre deux points
**      et renvoie la distance entre les deux points
*/

float	vec_of_2_points(t_vect start_pos, t_vect end_pos, t_vect result)
{
	float	dist;
	t_vect	buffer;

	minusvec(end_pos, start_pos, buffer);
	dist = length_vec(buffer);
	norme_vec(buffer);
	vec_copy(result, buffer);
	return (dist);
}

/*
**  multiplie les valeurs de chaque vecteur une par une
*/

void	mult2vec(t_vect u, t_vect v, t_vect result)
{
	result[0] = u[0] * v[0];
	result[1] = u[1] * v[1];
	result[2] = u[2] * v[2];
}

int		vec_cmp(t_vect u, t_vect v)
{
	if (!is_null(u[0] - v[0]) || !is_null(u[1] - v[1]) || !is_null(u[2] - v[2]))
		return (0);
	return (1);
}

/*
**  ROTATION
**  rotation d'un vecteur u selon un axe et selon un angle
**  d'apres la matrice de rotation en 3D:
**  [   ux**2*(1-c)+c,  ux*uy*(1-c)-uz*s,   ux*uz*(1-c)+uy*s]
**  [ux*uy*(1-c)+uz*s,     uy**2*(1-c)+c,  uy*uz*(1-c)-ux**2]
**  [ux*uz*(1-c)-uy*s,  uy*uz*(1-c)+ux*s,      uz**2*(1-c)+c]
*/

void	rotation(t_vect axis, float angle, t_vect u, t_vect result)
{
	t_vect	copy;
	float	c;
	float	s;

	c = cos(angle * 360 / (2 * M_PI));
	s = sin(angle * 360 / (2 * M_PI));
	vec_copy(copy, u);
	result[0] = (powf(axis[0], 2.0) * (1 - c) + c) * copy[0]
	+ (axis[0] * axis[1] * (1 - c) - axis[2] * s) * copy[1] +
	(axis[0] * axis[2] * (1 - c) + axis[1] * s) * copy[2];
	result[1] = (axis[0] * axis[1] * (1 - c) + axis[2] * s) * copy[0]
	+ (powf(axis[1], 2.0) * (1 - c) + c) * copy[1]
	+ (axis[1] * axis[2] * (1 - c) - axis[0] * s) * copy[2];
	result[2] = (axis[0] * axis[2] * (1 - c) - axis[1] * s) * copy[0]
	+ (axis[1] * axis[2] * (1 - c) + axis[0] * s) * copy[1]
	+ (powf(axis[2], 2.0) * (1 - c) + c) * copy[2];
}
