/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cal_color.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 14:15:23 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:31:19 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

void			color_limit(t_vect u, float min, float max)
{
	if (u[0] < min || u[0] > max)
		u[0] = (u[0] > max) ? max : min;
	if (u[1] < min || u[1] > max)
		u[1] = (u[1] > max) ? max : min;
	if (u[2] < min || u[2] > max)
		u[2] = (u[2] > max) ? max : min;
}

/*
**  ADD_AL
**  ajoute de la lumière ambiante
**  color = Ka * Ia
**  avec Ka : coefficient de lumiere ambiante
**  Ia : intensité de la lumière ambiante (= couleur * intensité)
*/

void			add_al(t_al *al, t_inters *inters_obj, t_vect final_color)
{
	mult2vec(al->color, inters_obj->color, final_color);
	multvec(al->ratio / 255.0, final_color, final_color);
}

/*
**  ADD_VAL_DIFFUS
**  ajout la composante de reflexion diffuse sur le rayon
**  color += Ks * I * max(I.N, 0)
**  avec C : couleur obj, I : couleur lumiere, Ks : coeff de reflexion diffuse
**  I.N : prod scalaire entre I le rayon de l'intersection vers la lumiere et
**  N le vecteur normal a la surface
*/

void			add_val_diffus(t_inters *obj, t_inters *light,
											t_vect final_color)
{
	t_vect	buffer;
	float	buff;

	vec_copy(buffer, light->color);
	buff = fmax(scal_prod(light->normal, obj->normal), 0);
	mult2vec(obj->color, buffer, buffer);
	multvec(buff / 255.0, buffer, buffer);
	addvec(final_color, buffer, final_color);
	color_limit(final_color, 0, 255.0);
}

/*
**  ADD_VAL_SPECUL
**  ajout de la composante de reflexion speculaire
**  color += I * RATIO * (max(R.V, 0)^ALPHA)
**  R = 2 * (L.N) * N - L
**  avec C : couleur obj, I : couleur lumiere
**  RATIO : coeff reflexion speculaire / reflexion diffuse
**  R.N prod scalaire entre R le vecteur d'une reflexion parfaite du rayon
**  N la vecteur normal a la surface
**  L est le vecteur direction de la surface vers la source de lumiere
*/

void			add_val_specul(t_inters *obj, t_inters *light,
								t_vect final_color, t_vect view)
{
	t_vect	buffer;
	float	buff;

	buff = 2 * scal_prod(light->normal, obj->normal);
	multvec(buff, obj->normal, buffer);
	minusvec(buffer, light->normal, buffer);
	norme_vec(buffer);
	buff = scal_prod(buffer, view);
	buff = powf(buff, ALPHA);
	mult2vec(obj->color, light->color, buffer);
	multvec(1 / 255.0, buffer, buffer);
	multvec(buff, buffer, buffer);
	addvec(final_color, buffer, final_color);
	color_limit(final_color, 0, 255.0);
}

unsigned int	conv_color(t_vect final_color)
{
	unsigned int buffer;

	final_color[0] = round(final_color[0]);
	buffer = (unsigned int)final_color[0] * 0x10000;
	final_color[1] = round(final_color[1]);
	buffer += (unsigned int)final_color[1] * 0x100;
	final_color[2] = round(final_color[2]);
	buffer += (unsigned int)final_color[2];
	return (buffer);
}
