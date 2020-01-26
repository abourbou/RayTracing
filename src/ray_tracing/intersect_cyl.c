/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   intersect_cyl.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 11:42:11 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

/*
**  RESOLV_POLYN_CYL
**  resolution complete d'un polynome (utiliser pr le cylindre)
**  met les solutions des équations dans un tableau de float
**  (si il y en a)
**  et renvoie le nbr de solution
*/

int		resolv_polyn_cyl(float a, float b, float c, float sol[2])
{
	float	delta;

	if (is_null(a))
		return (0);
	delta = powf(b, 2.0) - 4 * a * c;
	if (delta > EPSILON)
	{
		sol[0] = (-b - sqrtf(delta)) / (2 * a);
		sol[1] = (-b + sqrtf(delta)) / (2 * a);
		return (2);
	}
	else if (is_null(delta))
	{
		sol[0] = -b / (2 * a);
		sol[1] = -1.0;
		return (1);
	}
	sol[0] = -1.0;
	sol[1] = -1.0;
	return (0);
}

void	coeff_polyn_cyl(t_cy *cyl, t_vect direction, t_vect ray_to_cyl,
													t_vect coeff_polyn)
{
	coeff_polyn[0] = powf(scal_prod(direction, cyl->ref.u), 2.0) +
		powf(scal_prod(direction, cyl->ref.v), 2.0);
	coeff_polyn[1] = 2 * scal_prod(ray_to_cyl, cyl->ref.u) *
		scal_prod(direction, cyl->ref.u)
		+ 2 * scal_prod(ray_to_cyl, cyl->ref.v) *
		scal_prod(direction, cyl->ref.v);
	coeff_polyn[2] = powf(scal_prod(ray_to_cyl, cyl->ref.u), 2.0) +
		powf(scal_prod(ray_to_cyl, cyl->ref.v), 2.0) -
		powf(cyl->radius, 2.0);
}
