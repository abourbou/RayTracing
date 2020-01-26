/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:52:47 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/raytracing.h"

static int	check_rt(char *str)
{
	int	len;
	int	fd;

	len = ft_strlen(str) - 3;
	if (len < 1 || str[len - 1] == '/' || ft_memcmp(str + len, ".rt", 3))
	{
		ft_putstr_fd("Error\nWrong file format - must be *.rt\n", 2);
		return (1);
	}
	if ((fd = open(str, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\nFailed to open file\n", 2);
		return (1);
	}
	return (0);
}

int			main(int ac, char *av[])
{
	t_param param;

	param.res.x = -2.0;
	param.al.ratio = -2.0;
	if (ac == 1)
	{
		ft_putstr_fd("Error\nNo argument supplied\n", 2);
		return (-1);
	}
	if (check_rt(av[1]) || parsing(av[1], &param) == -1)
		return (-1);
	param.save = 0;
	if (ac == 3 && !ft_memcmp("--save", av[2], 7))
		param.save = 1;
	else if (ac > 3 || (ac == 3 && ft_memcmp("--save", av[1], 7)))
	{
		if (ac > 3)
			ft_putstr_fd("Error\nToo many arguments\n", 2);
		else
			ft_putstr_fd("Only 2nd argument allowed is --save\n", 2);
		return (free_params(&param));
	}
	if (norme_all(&param) == -1)
		return (free_params(&param));
	return (open_window(&param));
}
