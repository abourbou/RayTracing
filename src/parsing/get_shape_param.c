/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_shape_param.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 10:22:53 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	get_sp(char *line, t_obj *l_obj, t_vect color)
{
	int		i;
	int		temp;
	t_sp	*sp;

	if (!(sp = malloc(sizeof(t_sp))))
		return (malloc_error(__func__));
	l_obj->carac = sp;
	i = 2;
	if (skip_vect(line, &i, sp->pos, __func__))
		return (-1);
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (ft_atod(line + i, &sp->radius) == -1)
		return (parse_error(__func__));
	if ((sp->radius = sp->radius / 2) <= 0)
		return (format_error(__func__));
	if ((temp = ft_atod_index(line + i)) == -1)
		return (parse_error(__func__));
	i += temp;
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (rgb_to_int(line, &i, color) == 0)
		return (-1);
	skip_space(line, &i);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}

int	get_pl(char *line, t_obj *l_obj, t_vect color)
{
	int		i;
	int		temp;
	t_pl	*pl;

	if (!(pl = malloc(sizeof(t_pl))))
		return (malloc_error(__func__));
	l_obj->carac = pl;
	i = 2;
	temp = 0;
	if (skip_vect(line, &i, pl->pos, __func__))
		return (-1);
	if (skip_vect(line, &i, pl->normal, __func__))
		return (-1);
	if (vect_is_valid(pl->normal) == -1)
		return (format_error(__func__));
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (rgb_to_int(line, &i, color) == 0)
		return (-1);
	skip_space(line, &i);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}

int	get_sq(char *line, t_obj *l_obj, t_vect color)
{
	int		i;
	t_sq	*sq;

	if (!(sq = malloc(sizeof(t_sq))))
		return (malloc_error(__func__));
	i = 2;
	sq->angle = 0;
	l_obj->carac = sq;
	if (skip_vect(line, &i, sq->pos, __func__))
		return (-1);
	if (skip_vect(line, &i, sq->normal, __func__))
		return (-1);
	if (vect_is_valid(sq->normal) == -1)
		return (format_error(__func__));
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if ((get_sq_end(line, &i, sq, color)) != 0)
		return (-1);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}

int	get_cy(char *line, t_obj *l_obj, t_vect color)
{
	int		i;
	int		temp;
	t_cy	*cy;

	if (!(cy = malloc(sizeof(t_cy))))
		return (malloc_error(__func__));
	l_obj->carac = cy;
	i = 2;
	if (skip_vect(line, &i, cy->pos, __func__))
		return (-1);
	if (skip_vect(line, &i, cy->normal, __func__))
		return (-1);
	if (vect_is_valid(cy->normal) == -1)
		return (format_error(__func__));
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (ft_atod(line + i, &cy->radius) == -1)
		return (parse_error(__func__));
	cy->radius = cy->radius / 2;
	temp = ft_atod_index(line + i);
	i = temp >= 0 ? i + temp : 0;
	if ((get_cy_end(line, &i, cy, color)) != 0)
		return (-1);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}

int	get_tr(char *line, t_obj *l_obj, t_vect color)
{
	int		i;
	int		j;
	int		temp;
	t_tr	*tr;

	if (!(tr = malloc(sizeof(t_tr))))
		return (malloc_error(__func__));
	l_obj->carac = tr;
	i = 2;
	j = -1;
	while (++j < 3)
	{
		if (skip_space(line, &i) != 1)
			return (skip_check(line[i], __func__));
		if ((temp = get_vect(line + i, tr->points[j])) == -1)
			return (parse_error(__func__));
		i += temp;
	}
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (rgb_to_int(line, &i, color) == 0)
		return (-1);
	skip_space(line, &i);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}
