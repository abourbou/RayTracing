/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vect.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 17:21:06 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

void	vec_copy(t_vect dest, t_vect src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}

void	cross_prod(t_vect u, t_vect v, t_vect result)
{
	t_vect	u_cpy;
	t_vect	v_cpy;

	vec_copy(u_cpy, u);
	vec_copy(v_cpy, v);
	result[0] = u_cpy[1] * v_cpy[2] - u_cpy[2] * v_cpy[1];
	result[1] = u_cpy[2] * v_cpy[0] - u_cpy[0] * v_cpy[2];
	result[2] = u_cpy[0] * v_cpy[1] - u_cpy[1] * v_cpy[0];
	return ;
}

/*
**  SCAL_PROD
**  formule du produit scalaire qui correspond a
**  "l'ombre" du vecteur u sur le vecteur v
**  (projection du vecteur u sur le vecteur v)
*/

float	scal_prod(t_vect u, t_vect v)
{
	float	result;

	result = u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
	return (result);
}

void	multvec(float a, t_vect v, t_vect result)
{
	result[0] = a * v[0];
	result[1] = a * v[1];
	result[2] = a * v[2];
}

void	addvec(t_vect u, t_vect v, t_vect result)
{
	result[0] = u[0] + v[0];
	result[1] = u[1] + v[1];
	result[2] = u[2] + v[2];
}
