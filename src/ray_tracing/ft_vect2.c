/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vect2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 17:20:57 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

void	init_vec(t_vect v, float a, float b, float c)
{
	v[0] = a;
	v[1] = b;
	v[2] = c;
}

void	minusvec(t_vect u, t_vect v, t_vect result)
{
	result[0] = u[0] - v[0];
	result[1] = u[1] - v[1];
	result[2] = u[2] - v[2];
}

float	length_vec(t_vect v)
{
	float result;

	result = sqrtf(powf(v[0], 2.0) + powf(v[1], 2.0) + powf(v[2], 2.0));
	return (result);
}

float	sq_len_vec(t_vect v)
{
	float result;

	result = powf(v[0], 2) + powf(v[1], 2) + powf(v[2], 2);
	return (result);
}

int		norme_vec(t_vect v)
{
	float len;

	len = length_vec(v);
	if (is_null(len))
		return (0);
	multvec(1 / len, v, v);
	return (1);
}
