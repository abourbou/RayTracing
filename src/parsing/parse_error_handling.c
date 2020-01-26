/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_error_handling.c                           .::    .:/ .      .::   */
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

int		parse_error(const char *funcname)
{
	ft_putstr_fd("Error\n", 2);
	if (funcname[4] == 'r')
		ft_putstr_fd("Resolution ", 2);
	else if (funcname[4] == 'a')
		ft_putstr_fd("Ambiant light ", 2);
	else if (funcname[4] == 'c' && funcname[5] != 'y')
		ft_putstr_fd("One of the Camera ", 2);
	else if (funcname[4] == 'l')
		ft_putstr_fd("One of the Light ", 2);
	else if (funcname[4] == 's' && funcname[5] == 'p')
		ft_putstr_fd("One of the Sphere ", 2);
	else if (funcname[4] == 'p' && funcname[5] == 'l')
		ft_putstr_fd("One of the Plane ", 2);
	else if (funcname[4] == 's' && funcname[5] == 'q')
		ft_putstr_fd("One of the Square ", 2);
	else if (funcname[4] == 'c' && funcname[5] == 'y')
		ft_putstr_fd("One of the Cylinder ", 2);
	else if (funcname[4] == 't' && funcname[5] == 'r')
		ft_putstr_fd("One of the Triangle ", 2);
	else
		ft_putstr_fd("/!\\ not recognized /!\\\n", 2);
	ft_putstr_fd("parameter is incorrect\n\n", 2);
	return (-1);
}

int		skip_space_error(const char *funcname)
{
	ft_putstr_fd("Error\nIncorrect spacing : random character in ", 2);
	if (funcname[4] == 'r')
		ft_putstr_fd("Resolution", 2);
	else if (funcname[4] == 'a')
		ft_putstr_fd("Ambiant light", 2);
	else if (funcname[4] == 'c' && funcname[5] != 'y')
		ft_putstr_fd("one of the Camera", 2);
	else if (funcname[4] == 'l')
		ft_putstr_fd("one of the Light", 2);
	else if (funcname[4] == 's' && funcname[5] == 'p')
		ft_putstr_fd("one of the Sphere", 2);
	else if (funcname[4] == 'p' && funcname[5] == 'l')
		ft_putstr_fd("one of the Plane", 2);
	else if (funcname[4] == 's' && funcname[5] == 'q')
		ft_putstr_fd("one of the Square", 2);
	else if (funcname[4] == 'c' && funcname[5] == 'y')
		ft_putstr_fd("one of the Cylinder", 2);
	else if (funcname[4] == 't' && funcname[5] == 'r')
		ft_putstr_fd("one of the Triangle", 2);
	else
		ft_putstr_fd("/!\\ not recognized /!\\\n", 2);
	ft_putstr_fd("\n\n", 2);
	return (-1);
}

int		wrong_arg_count_error(const char *funcname)
{
	ft_putstr_fd("Error\nWrong number of arguments for ", 2);
	if (funcname[4] == 'r')
		ft_putstr_fd("the Resolution", 2);
	else if (funcname[4] == 'a')
		ft_putstr_fd("the Ambiant light", 2);
	else if (funcname[4] == 'c' && funcname[5] != 'y')
		ft_putstr_fd("one of the Camera", 2);
	else if (funcname[4] == 'l')
		ft_putstr_fd("one of the Light", 2);
	else if (funcname[4] == 's' && funcname[5] == 'p')
		ft_putstr_fd("one of the Sphere", 2);
	else if (funcname[4] == 'p' && funcname[5] == 'l')
		ft_putstr_fd("one of the Plane", 2);
	else if (funcname[4] == 's' && funcname[5] == 'q')
		ft_putstr_fd("one of the Square", 2);
	else if (funcname[4] == 'c' && funcname[5] == 'y')
		ft_putstr_fd("one of the Cylinder", 2);
	else if (funcname[4] == 't' && funcname[5] == 'r')
		ft_putstr_fd("one of the Triangle", 2);
	else
		ft_putstr_fd("/!\\ not recognized /!\\\n", 2);
	ft_putstr_fd(" parameters\n\n", 2);
	return (-1);
}

int		malloc_error(const char *funcname)
{
	ft_putstr_fd("Error\nMemory allocation failed in ", 2);
	if (funcname[4] == 'r')
		ft_putstr_fd("Resolution", 2);
	else if (funcname[4] == 'a')
		ft_putstr_fd("Ambiant light", 2);
	else if (funcname[4] == 'c' && funcname[5] != 'y')
		ft_putstr_fd("one of the Camera", 2);
	else if (funcname[4] == 'l')
		ft_putstr_fd("one of the Light", 2);
	else if (funcname[4] == 's' && funcname[5] == 'p')
		ft_putstr_fd("one of the Sphere", 2);
	else if (funcname[4] == 'p' && funcname[5] == 'l')
		ft_putstr_fd("one of the Plane", 2);
	else if (funcname[4] == 's' && funcname[5] == 'q')
		ft_putstr_fd("one of the Square", 2);
	else if (funcname[4] == 'c' && funcname[5] == 'y')
		ft_putstr_fd("one of the Cylinder", 2);
	else if (funcname[4] == 't' && funcname[5] == 'r')
		ft_putstr_fd("one of the Triangle", 2);
	else
		ft_putstr_fd("/!\\ not recognized /!\\\n", 2);
	ft_putstr_fd(" parameters\n\n", 2);
	return (-1);
}

int		format_error(const char *funcname)
{
	ft_putstr_fd("Error\nFormat error in ", 2);
	if (funcname[4] == 'r')
		ft_putstr_fd("Resolution", 2);
	else if (funcname[4] == 'a')
		ft_putstr_fd("Ambiant light", 2);
	else if (funcname[4] == 'c' && funcname[5] != 'y')
		ft_putstr_fd("one of the Camera", 2);
	else if (funcname[4] == 'l')
		ft_putstr_fd("one of the Light", 2);
	else if (funcname[4] == 's' && funcname[5] == 'p')
		ft_putstr_fd("one of the Sphere", 2);
	else if (funcname[4] == 'p' && funcname[5] == 'l')
		ft_putstr_fd("one of the Plane", 2);
	else if (funcname[4] == 's' && funcname[5] == 'q')
		ft_putstr_fd("one of the Square", 2);
	else if (funcname[4] == 'c' && funcname[5] == 'y')
		ft_putstr_fd("one of the Cylinder", 2);
	else if (funcname[4] == 't' && funcname[5] == 'r')
		ft_putstr_fd("one of the Triangle", 2);
	else
		ft_putstr_fd("/!\\ not recognized /!\\\n", 2);
	ft_putstr_fd(" parameters, check the range\n\n", 2);
	return (-1);
}
