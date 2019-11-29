/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vect.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 17:21:06 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 13:03:43 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/shapes.h"
#include "../include/ray_tracing.h"

void    cross_prod(double u[3], double v[3], double result[3])
{
    double   u_cpy[3];
    double   v_cpy[3];
 
    vec_copy(u_cpy, u);
    vec_copy(v_cpy, v);
    result[0] = u_cpy[1] * v_cpy[2] - u_cpy[2] * v_cpy[1];
    result[1] = u_cpy[2] * v_cpy[0] - u_cpy[0] * v_cpy[2];
    result[2] = u_cpy[0] * v_cpy[1] - u_cpy[1] * v_cpy[0];
    return ;
}

double   scal_prod(double u[3], double v[3])
{
    double   result;

    result = u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
    return (result);
}

void    multvec(double a, double v[3], double result[3])
{
    result[0] = a *v[0];
    result[1] = a *v[1];
    result[2] = a *v[2];
}

void    addvec(double u[3], double v[3], double result[3])
{
    result[0] = u[0] + v[0];
    result[1] = u[1] + v[1];
    result[2] = u[2] + v[2];
}

void   vec_copy(double dest[3],double src[3])
{
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
}

