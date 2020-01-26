/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct_de_test.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 09:27:20 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/raytracing.h"

void ft_print_vec(char *str, t_vect vec)
{
    printf("%s", str);
    printf("(%.3lf, %.3lf, %.3lf)\n", vec[0], vec[1], vec[2]);
}