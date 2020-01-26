/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_param.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:08:39 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void	init_get_l(int *i, int *j, int *temp, t_l *tl)
{
	*i = 1;
	*j = 0;
	*temp = 0;
	tl->next = 0;
}

/*
** Kinda same function as get_shape_param.c/get_sp
*/

static int	get_l2(char *line, int i, t_l *tl)
{
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (ft_atod(line + i, &tl->ratio) == -1)
		return (parse_error(__func__));
	if (tl->ratio < 0 || tl->ratio > 1)
		return (format_error(__func__));
	i += ft_atod_index(line + i);
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (rgb_to_int(line, &i, tl->color) == 0)
		return (-1);
	skip_space(line, &i);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}

int			get_l(char *line, t_l **light)
{
	int i;
	int j;
	int temp;
	t_l *tl;

	if (!(tl = malloc(sizeof(t_l))))
		return (malloc_error(__func__));
	add_back_light(light, tl);
	init_get_l(&i, &j, &temp, tl);
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if ((temp = get_vect(line + i, tl->pos)) == -1)
		return (parse_error(__func__));
	i += temp;
	return (get_l2(line, i, tl));
}
