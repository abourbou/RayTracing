/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   intersect_resolv2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/23 12:36:54 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

/*
**  RESOLV_SQUARE
*/

float			resolv_square(void *obj, t_vect pos, t_vect direction)
{
	float	result;
	t_sq	*sq;

	sq = obj;
	if ((result = resolv_triangle(sq->triangle, pos, direction)) > EPSILON)
		return (result);
	return (resolv_triangle(&(sq->triangle[1]), pos, direction));
}

/*
**  FINAL_SOL
**  solution final au probleme de notre societe, tel a ete ordonne par le Furher
**  //! Ca fleure le desespoir d'avant les vacances tout ca
**  nan sans dec, sert a choisir parmi les 4 solutions possibles du cylindre
**  (les deux sur les cotes du cylindre + les deux capuchons)
*/

static float	choose_sol_cyl(float sol[4])
{
	int		i;
	float	final_sol;

	i = 0;
	final_sol = HUGE_VALF;
	while (i < 4)
	{
		if (sol[i] > 0 && sol[i] < final_sol)
			final_sol = sol[i];
		i++;
	}
	if (final_sol == HUGE_VALF)
		final_sol = 0;
	return (final_sol);
}

static void		is_valid_side_cyl(t_vect pos, t_vect direction, float *sol,
																t_cy *cyl)
{
	int		nbr_sol;
	t_vect	buffer;

	nbr_sol = 0;
	nbr_sol += (sol[1] > 0) ? 1 : 0;
	nbr_sol += (sol[0] > 0) ? 1 : 0;
	if (nbr_sol == 2)
	{
		vec_to_point(pos, direction, sol[1], buffer);
		minusvec(cyl->pos, buffer, buffer);
		if (fabsf(scal_prod(buffer, cyl->normal)) > cyl->height / 2)
			sol[1] = -1.0;
	}
	if (nbr_sol >= 1)
	{
		vec_to_point(pos, direction, sol[0], buffer);
		minusvec(cyl->pos, buffer, buffer);
		if (fabsf(scal_prod(buffer, cyl->normal)) > cyl->height / 2)
			sol[0] = -1.0;
	}
}

static void		verif_sol_caps(t_vect sol, t_vect pos, t_vect direction,
																t_cy *cyl)
{
	float	buff;
	t_vect	buffer;

	vec_to_point(pos, direction, sol[2], buffer);
	minusvec(buffer, cyl->pos, buffer);
	buff = powf(scal_prod(buffer, cyl->ref.u), 2.0) +
	powf(scal_prod(buffer, cyl->ref.v), 2.0);
	if (buff > powf(cyl->radius, 2.0))
		sol[2] = -1.0;
	vec_to_point(pos, direction, sol[3], buffer);
	minusvec(buffer, cyl->pos, buffer);
	buff = powf(scal_prod(buffer, cyl->ref.u), 2.0) +
	powf(scal_prod(buffer, cyl->ref.v), 2.0);
	if (buff > powf(cyl->radius, 2.0))
		sol[3] = -1.0;
}

/*
**	  RESOLV_CYLINDER
**	Partie 1 : calcule coeff polynome pour les cotes du cylindre
**	Partie 2 : exploitation des solutions polyn pr voir si c des
**	solutions potentielles
**	Partie 3 : recherche des solutions pr les deux capuchons du cylindre
*/

float			resolv_cylinder(void *obj, t_vect pos, t_vect direction)
{
	t_cy	*cyl;
	t_vect	coeff_polyn;
	float	sol[4];
	t_vect	ray_to_cyl;
	float	buff;

	cyl = obj;
	init_vec(sol, 0, 0, 0);
	sol[3] = 0;
	minusvec(pos, cyl->pos, ray_to_cyl);
	coeff_polyn_cyl(cyl, direction, ray_to_cyl, coeff_polyn);
	resolv_polyn_cyl(coeff_polyn[0], coeff_polyn[1], coeff_polyn[2], sol);
	is_valid_side_cyl(pos, direction, sol, cyl);
	if (is_null(buff = scal_prod(direction, cyl->normal)))
		return (choose_sol_cyl(sol));
	sol[2] = (-cyl->height * 0.5 - scal_prod(ray_to_cyl, cyl->normal)) / buff;
	sol[3] = (cyl->height * 0.5 - scal_prod(ray_to_cyl, cyl->normal)) / buff;
	verif_sol_caps(sol, pos, direction, cyl);
	return (choose_sol_cyl(sol));
}
