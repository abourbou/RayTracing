/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_needed_param.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:08:19 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int			unique_param_appeared_twice_error(char c)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Only one parameter of type ", 2);
	ft_putstr_fd(&c, 2);
	ft_putstr_fd(" is possible, you tried to enter two of them\n", 2);
	return (-1);
}

int			get_res(char *line, t_r *res)
{
	int i;

	i = 1;
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	res->x = (float)ft_atoi(line + i);
	i += int_len(res->x);
	skip_space(line, &i);
	res->y = (float)ft_atoi(line + i);
	if (res->x <= 0 || res->y <= 0)
		return (format_error(__func__));
	i += int_len(res->y);
	skip_space(line, &i);
	if (line[i] != '\0')
		return (wrong_arg_count_error(__func__));
	return (1);
}

int			get_al(char *line, t_al *al)
{
	int i;

	i = 1;
	al->ratio = 0.0;
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (ft_atod(line + i, &al->ratio) == 0)
		return (parse_error(__func__));
	if (al->ratio < 0 || al->ratio > 1)
		return (format_error(__func__));
	i += ft_atod_index(line + i);
	if (skip_space(line, &i) != 1)
		return (wrong_arg_count_error(__func__));
	if (rgb_to_int(line, &i, al->color) == 0)
		return (-1);
	skip_space(line, &i);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}

static int	get_c2(int *i, t_c *c, char *line, const char *func)
{
	int temp;

	*i = 1;
	temp = 0;
	c->next = 0;
	c->image = 0;
	if (skip_space(line, i) != 1)
		return (skip_check(line[*i], func));
	if (line[*i] == '\0')
		return (wrong_arg_count_error(func));
	if ((temp = get_vect(line + *i, c->pos)) == -1)
		return (parse_error(func));
	*i += temp;
	if (skip_space(line, i) != 1)
		return (wrong_arg_count_error(func));
	return (0);
}

int			get_c(char *line, t_c **cam)
{
	int i;
	int temp;
	t_c *c;

	if (!(c = malloc(sizeof(t_c))))
		return (malloc_error(__func__));
	add_back_cam(cam, c);
	if (get_c2(&i, c, line, __func__) == -1)
		return (-1);
	if ((temp = get_vect(line + i, c->vec)) == -1)
		return (parse_error(__func__));
	i += temp;
	if (skip_space(line, &i) != 1)
		return (skip_check(line[i], __func__));
	if (ft_atod(line + i, &(c->fov)) != 1)
		return (parse_error(__func__));
	if (c->fov <= 0 || c->fov >= 180 || vect_is_valid(c->vec))
		return (format_error(__func__));
	i += ft_atod_index(line + i);
	skip_space(line, &i);
	return ((line[i] != '\0') ? wrong_arg_count_error(__func__) : 1);
}
