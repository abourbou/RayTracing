/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:09:13 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/intersect_resolv.h"

int		get_needed_param(char *line, t_param *param)
{
	if (line[0] == 'R')
	{
		if (param->res.x != -2.0)
			ft_putstr_fd("Error\n1 and only one ", 2);
		if (param->res.x != -2.0)
			ft_putstr_fd("Resolution should be present\n", 2);
		return (param->res.x != -2.0 ? -1 : get_res(line, &param->res));
	}
	if (line[0] == 'A')
	{
		if (param->al.ratio != -2.0)
			ft_putstr_fd("Error\n1 and only one ", 2);
		if (param->al.ratio != -2.0)
			ft_putstr_fd("Ambiant Light should be present\n", 2);
		return (param->al.ratio != -2.0 ? -1 : get_al(line, &param->al));
	}
	if (line[0] == 'c')
		return (get_c(line, &param->cam));
	return (0);
}

void	init_get_shape_function_tab(t_shape_func *shafun)
{
	shafun[_sphere] = get_sp;
	shafun[_plane] = get_pl;
	shafun[_square] = get_sq;
	shafun[_cylinder] = get_cy;
	shafun[_triangle] = get_tr;
}

/*
** TODO
** Creer un nouvel elem de la liste, l'ajouter a la liste
** Si elle n'existe pas, la creer.
*/

int		get_shape_param(char *line, t_param *param)
{
	t_obj			*new_elem;
	t_shape_func	shafun[_size];
	int				type;

	init_get_shape_function_tab(shafun);
	type = shape_type(line);
	if (!(new_elem = malloc(sizeof(t_obj))))
		return (-1);
	if (type != -1)
	{
		obj_init(new_elem, type);
		add_back_obj(&param->lst_obj, new_elem);
		return (shafun[type](line, new_elem, new_elem->color));
	}
	return (-1);
}

int		process_param(char *line, t_param *param)
{
	int retval;

	retval = -1;
	if (is_in(line[0], "RAc") && line[1] != 'y')
		retval = get_needed_param(line, param);
	else if (line[0] == 'l')
		retval = get_l(line, &param->l);
	else if ((shape_type(line) != -1))
		retval = get_shape_param(line, param);
	else if (line[0] == '#')
		retval = 1;
	else
		ft_putstr_fd("Error\nLine is neither empty nor valid\n", 2);
	return (retval < 0 ? 1 : 0);
}

int		parsing(char *config_rt_path, t_param *param)
{
	int		fd;
	char	*line;
	int		break_value;
	int		error;

	param_lsts_init(param, &error);
	fd = open(config_rt_path, O_RDONLY);
	while ((break_value = get_next_line(fd, &line)) > -1)
	{
		if (line[0] != '\0')
			error = process_param(line, param);
		free(line);
		if (error)
			return (free_params(param));
		if (break_value == 0)
			break ;
	}
	close(fd);
	if (param->res.x == -2.0 || param->al.ratio == -2.0 || !param->cam)
		return (needed_param_missing_error(param));
	if (break_value == -1)
		ft_putstr_fd("Error\nGNL Failure - Couldn't read further\n", 2);
	if (break_value == -1)
		return (free_params(param));
	return (1);
}
