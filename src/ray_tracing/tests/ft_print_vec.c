/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_vec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 14:04:57 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 13:43:13 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/shapes.h"
#include "../../../includes/tests.h"

void	ft_print_vec(char *str, t_vect vec)
{
	printf("%s", str);
	printf("(%lf, %lf, %lf)\n", vec[0], vec[1], vec[2]);
}
