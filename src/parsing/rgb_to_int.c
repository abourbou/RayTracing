/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rgb_to_int.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 18:26:04 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void		color_not_in_range_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid color, ", 2);
	if (str[0] == 'A')
		ft_putstr_fd("found in Ambiant Light", 2);
	if (str[0] == 'l')
		ft_putstr_fd("found in one of the Light", 2);
	if (str[0] == 's' && str[1] == 'p')
		ft_putstr_fd("found in a Sphere", 2);
	if (str[0] == 'p')
		ft_putstr_fd("found in a Plane", 2);
	if (str[0] == 's' && str[1] == 'q')
		ft_putstr_fd("found in a Square", 2);
	if (str[0] == 'c')
		ft_putstr_fd("found in a Cylinder", 2);
	if (str[0] == 't')
		ft_putstr_fd("found in a Triangle", 2);
	ft_putstr_fd("\n\n", 2);
}

/*
** To check rgb values before conversion to a single int
** printf("\nrgb_proc ~\n res = %d\n", res);
** before the return in rgbprocess
*/

static int	rgb_process(char *str, int *i)
{
	int	res;

	res = 0;
	if (!(str[*i] && str[*i] >= '0' && str[*i] <= '9'))
		return (-1);
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + str[*i] - '0';
		*i = *i + 1;
	}
	return ((res >= 0 && res <= 255) ? res : -1);
}

/*
** Also takes the index to make it evolve accordingly
** Should be 2 distinct functions
*/

int			rgb_to_int(char *str, int *i, t_vect color)
{
	int	check;
	int	j;

	j = 0;
	while (j < 3)
	{
		check = rgb_process(str, i);
		if (check == -1)
		{
			color_not_in_range_error(str);
			return (0);
		}
		color[j] = check;
		if (str[*i] != ',' && j != 2)
		{
			ft_putstr_fd("Error\nWrong format for color\n", 2);
			return (0);
		}
		if (j != 2)
			*i = *i + 1;
		j++;
	}
	return (1);
}
