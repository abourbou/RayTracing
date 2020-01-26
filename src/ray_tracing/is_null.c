/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_null.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 13:49:47 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 17:27:10 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

int	is_null(float u)
{
	if (u < EPSILON && u > -EPSILON)
		return (1);
	return (0);
}

int	is_very_null(float u)
{
	if (u < EPSILON / 10.0 && u > -EPSILON / 10.0)
		return (1);
	return (0);
}
