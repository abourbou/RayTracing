/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_error_handling2.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 13:24:02 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/intersect_resolv.h"

int		free_params(t_param *param)
{
	if (param->cam)
		lst_cam_clear(&param->cam);
	if (param->l)
		lst_light_clear(&param->l);
	if (param->lst_obj)
		lst_obj_clear(&param->lst_obj);
	return (-1);
}

int		needed_param_missing_error(t_param *param)
{
	if (param->res.x == -2.0)
		ft_putstr_fd("Error\nNo Resolution parameter\n", 2);
	else if (param->al.ratio == -2.0)
		ft_putstr_fd("Error\nNo Ambiant Light parameter\n", 2);
	else if (!param->cam)
		ft_putstr_fd("Error\nNo Camera parameter\n", 2);
	return (free_params(param));
}
