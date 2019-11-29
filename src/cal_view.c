/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cal_view.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:58:46 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 10:34:03 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ray_tracing.h"
#include "../include/shapes.h"

/*
** PIX_COORD
** calcules des coordonnes du pixel 
** avec P = first_pixel - i * v + j * u
*/

void    pix_coord(double pos_pix[3], double i, double j, t_ref *ref)
{
    double  buffer[3];

    vec_copy(pos_pix, ref->fst_pix);
    multvec(-i * pixelHeight, ref->v, buffer);
    addvec(pos_pix, buffer, pos_pix);
    multvec(j * pixelWidth, ref->u, buffer);
    addvec(pos_pix, buffer, pos_pix);
}