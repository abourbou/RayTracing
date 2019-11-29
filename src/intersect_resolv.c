/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   intersect_resolv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 20:27:32 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 09:03:13 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/shapes.h"
#include "../include/ray_tracing.h"

void    setup_resolv(void)
{
    g_resolv[_sphere] = resolv_circ;
}

/*
**  RESOL_POLYN
**  resolution d'un polynome du second degre norme
**  pour trouver une solution strictement positive
**  pour contrer les erreurs de calculs, on arrondie
*/

double  resol_polyn(double b, double c)
{
    double delta;
    double  t1;
    double  t2;

    delta = pow(b, 2.0) - 4.0 * c;
    delta = round(delta);
    if (delta < 0.01)
        return  (-1.0);
    t2 = (-b - sqrt(delta)) * 0.5;
    if (t2 > 0.01)
        return (t2);
    t1 = (-b + sqrt(delta)) * 0.5;
    if (t1 <= 0.01)
        return (-1.0);
    return (t1);
}

/*
**  RESOLV_CIRC
**  permet de trouver l'intersection entre une droite et une sphere
**  resolution de l'equation d'un polynome du second degre
**  ||w||^2 * t^2 + 2 * t * (w.CO) + ||CO||^2 - R^2 = 0
**  t est la distance de l'intersection par rapport a la position du pixel
**  avec C0 le vecteur qui part du centre de la sphere 
**  vers la position du pixel
**  le symbole || || est la norme du vecteur, qui correspond a la longueur du vecteur
**  w.CO est le produit scalaire de w et CO
**  R est le rayon de la sphere
** on envoie ensuite la fonction t^2 + b ^t + c = 0 dans resolv polynome
**  ATTENTION CE POLYNOME DOIT ABSOLUMENT ETRE NORME (CAD a = 1)!
*/

double  resolv_circ(void *obj, double pos_screen[3], double ray[3])
{
    double b;
    double c;
    t_sp    *sp;
    double vec_CO[3];

    sp = obj;
    minusvec(pos_screen, sp->pos, vec_CO);
    b = 2.0 * scal_prod(ray, vec_CO);
    c = length_vec_2(vec_CO) - pow(sp->radius, 2.0);
    return (resol_polyn(b, c));
}