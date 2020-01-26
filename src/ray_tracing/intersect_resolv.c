/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   intersect_resolv.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 20:27:32 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:59:36 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

void	setup_resolv(void)
{
	g_resolv[_sphere] = resolv_circle;
	g_resolv[_plane] = resolv_plane;
	g_resolv[_triangle] = resolv_triangle;
	g_resolv[_square] = resolv_square;
	g_resolv[_cylinder] = resolv_cylinder;
}

/*
**  RESOLV_POLYN_CIRC
**  resolution d'un polynome du second degre normé
**  afin de trouver une solution strictement positive
**  (utilisé pr l'équation du cercle)
**  afin de contrer les erreurs de calculs, on arrondie
**  a EPSILON
*/

float	resolv_polyn_circ(float b, float c)
{
	float	delta;
	float	t1;
	float	t2;

	delta = powf(b, 2.0) - 4.0 * c;
	if (delta < EPSILON)
		return (-1.0);
	t2 = (-b - sqrtf(delta)) * 0.5;
	if (t2 > EPSILON)
		return (t2);
	t1 = (-b + sqrtf(delta)) * 0.5;
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
**  le symbole || || est la norme du vecteur, qui correspond a la longueur
**	du vecteur w.CO est le produit scalaire de w et CO
**  R est le rayon de la sphere
** on envoie ensuite la fonction t^2 + b ^t + c = 0 dans resolv polynome
**  ATTENTION CE POLYNOME DOIT ABSOLUMENT ETRE NORME (CAD a = 1)!
*/

float	resolv_circle(void *obj, t_vect pos, t_vect direction)
{
	float	b;
	float	c;
	t_sp	*sp;
	t_vect	vec_co;

	sp = obj;
	minusvec(pos, sp->pos, vec_co);
	b = 2.0 * scal_prod(direction, vec_co);
	c = sq_len_vec(vec_co) - powf(sp->radius, 2.0);
	return (resolv_polyn_circ(b, c));
}

/*
**  RESOLV_PLANE
**  resolution algebrique de l'equation :
**  ax + by + cz + D = Ro + Rd * t
**  avec a gauche l'equation du plan et a droite l'equation d'une droite
**  le resultat est :
**  t = -(N.Ro - N.M) / (N.Rd)
**  avec N la normale du plan et M un point appartenant au plan
**  Ro l'origine de la droite et Rd la direction de la droite
*/

float	resolv_plane(void *obj, t_vect pos, t_vect direction)
{
	t_pl	*pl;
	float	buffer;
	float	result;

	pl = obj;
	buffer = scal_prod(pl->normal, direction);
	if (is_very_null(buffer))
		return (0);
	result = -(scal_prod(pl->normal, pos) -
	scal_prod(pl->normal, pl->pos)) / buffer;
	return (result);
}

/*
**  RESOLV_TRIANGLE
**  resolution selon l'algorithne de Moller–Trumbore
**  f == 0 signifie que le triangle est parallele a la droite
**  (u, v) sont les coordonnées d'un point dans le triangle
**  avec u,v entre 0 et 1.
**  si u v > 1 || < 0 alors cela veut dire
*/

float	resolv_triangle(void *obj, t_vect pos, t_vect direction)
{
	t_tr	*tr;
	float	fuv[3];
	t_vect	d1;
	t_vect	d2;
	t_vect	hsq[3];

	tr = obj;
	minusvec(tr->points[1], tr->points[0], d1);
	minusvec(tr->points[2], tr->points[0], d2);
	cross_prod(direction, d2, hsq[0]);
	fuv[0] = scal_prod(d1, hsq[0]);
	if (is_null(fuv[0]))
		return (0);
	fuv[0] = 1 / fuv[0];
	minusvec(pos, tr->points[0], hsq[1]);
	fuv[1] = fuv[0] * scal_prod(hsq[1], hsq[0]);
	if (fuv[1] < 0 || fuv[1] > 1.0)
		return (0);
	cross_prod(hsq[1], d1, hsq[2]);
	fuv[2] = fuv[0] * scal_prod(direction, hsq[2]);
	if (fuv[2] < 0 || fuv[1] + fuv[2] > 1.0)
		return (0);
	return (fuv[0] * scal_prod(d2, hsq[2]));
}
