/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vect2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 17:20:57 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 15:28:35 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ray_tracing.h"
#include "../include/shapes.h"

void    init_vec(double v[3], double a, double b, double c)
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
}

void    minusvec(double u[3], double v[3], double result[3])
{
    double   u_cpy[3];
    double   v_cpy[3];

    vec_copy(u_cpy, u);
    vec_copy(v_cpy, v);
    result[0] = u[0] - v[0];
    result[1] = u[1] - v[1];
    result[2] = u[2] - v[2];
}

double   length_vec(double v[3])
{
    double result;

    result = sqrt(powf(v[0], 2) + powf(v[1], 2) + powf(v[2], 2));
    return (result);
}

double   length_vec_2(double v[3])
{
    double result;

    result = pow(v[0], 2) + powf(v[1], 2) + powf(v[2], 2);
    return (result);
}

int    norme_vec(double v[3])
{
    double len;

    len = length_vec(v);
    if (!len)
        return(0);
    multvec(1 / len, v, v);
    return (1);
}