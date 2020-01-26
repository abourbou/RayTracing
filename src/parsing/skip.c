/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   skip.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 15:31:58 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shapes.h"
#include "../../includes/parsing.h"
#include "../../includes/raytracing.h"

int	skip_space(char *line, int *i)
{
	if (line[*i] && line[*i] == ' ')
	{
		while (line[*i] && line[*i] == ' ')
			*i = *i + 1;
		if (line[*i] == '\0' || !is_in(line[*i], "0123456789-"))
			return (-1);
		return (1);
	}
	if (!line[*i])
		return (-1);
	return (0);
}

int	skip_check(char c, const char *func)
{
	if (c == '\0')
		return (wrong_arg_count_error(func));
	return (skip_space_error(func));
}

int	skip_vect(char *line, int *i, t_vect vector, const char *func)
{
	int temp;

	temp = 0;
	if (skip_space(line, i) != 1)
		return (skip_check(line[*i], func));
	if ((temp = get_vect(line + *i, vector)) == -1)
		return (parse_error(func));
	*i = *i + temp;
	return (0);
}

int	get_sq_end(char *line, int *i, t_sq *sq, t_vect color)
{
	int temp;

	temp = 0;
	if (ft_atod(line + *i, &sq->side) == -1)
		return (parse_error(__func__));
	if (sq->side <= 0)
		return (format_error(__func__));
	temp = ft_atod_index(line + *i);
	*i = temp >= 0 ? *i + temp : 0;
	if (skip_space(line, i) != 1)
		return (skip_check(line[*i], __func__));
	if (rgb_to_int(line, i, color) == 0)
		return (-1);
	skip_space(line, i);
	if (line[*i] != '\0')
	{
		if (ft_atod(line + *i, &sq->angle) == -1)
			return (parse_error(__func__));
		if (sq->angle < 0 - EPSILON || sq->angle >= 90 + EPSILON)
			return (format_error(__func__));
		temp = ft_atod_index(line + *i);
		*i = temp >= 0 ? *i + temp : 0;
		skip_space(line, i);
	}
	return (0);
}

int	get_cy_end(char *line, int *i, t_cy *cy, t_vect color)
{
	int temp;

	temp = 0;
	if (skip_space(line, i) != 1)
		return (skip_check(line[*i], __func__));
	if (ft_atod(line + *i, &cy->height) == -1)
		return (parse_error(__func__));
	if (cy->radius <= 0 || cy->height <= 0)
		return (format_error(__func__));
	temp = ft_atod_index(line + *i);
	*i = temp >= 0 ? *i + temp : 0;
	if (skip_space(line, i) != 1)
		return (skip_check(line[*i], __func__));
	if (rgb_to_int(line, i, color) == 0)
		return (-1);
	skip_space(line, i);
	return (0);
}
