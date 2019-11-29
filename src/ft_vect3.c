/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vect3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 11:59:35 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 12:38:26 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ray_tracing.h"
#include "../include/shapes.h"

/*
**      calcule la position d'un point a partir d'un point d'origine, d'une direction 
**      caracterise par un vecteur norme ainsi que d'une distance par rapport 
**      au point d'origine
*/

void    vec_to_point(double origin[3], double vect_direct[3], double dist, double result[3])
{
    double  buffer[3];

    multvec(dist, vect_direct, buffer);
    addvec(origin, buffer, result);
}

/*
**      permet de trouver le vecteur norme entre deux points 
**      et renvoie la distance entre les deux points
*/
double  vec_of_2_points(double start_pos[3], double end_pos[3], double result[3])
{
    double  dist;
    double  buffer[3];

    minusvec(end_pos, start_pos, buffer);
    dist = length_vec(buffer);
    norme_vec(buffer);
    vec_copy(result, buffer);
    return (dist);
}

/*
**  multiplie les valeurs de chaque vecteurs une par une
*/
void    mult2vec(double u[3], double v[3], double result[3])
{
    result[0] = u[0] * v[0];
    result[1] = u[1] * v[1];
    result[2] = u[2] * v[2];
}

int    vec_cmp(double u[3], double v[3])
{
    if (u[0] - v[0] > 0.01 || u[0] - v[0] < -0.01)
        return (0);
    if (u[1] - v[1] > 0.01 || u[1] - v[1] < -0.01)
        return (0);
    if (u[2] - v[2] > 0.01 || u[2] - v[2] < -0.01)
        return (0);
    return (1);
}