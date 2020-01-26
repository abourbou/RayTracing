/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   atod.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 11:19:13 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/*
** Returns the i++ that atod does so that it points the next char
*/

int			ft_atod_index(const char *str)
{
	int i;

	i = 0;
	if (str[i] && str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] && str[i] == '.')
	{
		i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

static int	ft_atod_int(const char *str, float *nbr, float *sign)
{
	int i;

	i = 0;
	*sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == ',')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		*nbr = *nbr * 10 + str[i] - 48;
		i++;
	}
	return (i);
}

static int	forbidden_char(const char *str)
{
	if (str[0] >= '0' && str[0] <= '9')
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] && str[1] >= '0' && str[1] <= '9')
			return (0);
	}
	return (1);
}

float		ft_atod_bis(int j, float post, const char *str)
{
	int div;

	div = 0;
	{
		if (str[j] && !is_in(str[j], "0123456789"))
			return (-1);
		while (str[j] >= '0' && str[j] <= '9')
		{
			post = post * 10 + str[j++] - '0';
			div++;
		}
	}
	while (div--)
		post = post / 10;
	return (post);
}

/*
** Could return j to avoid atod_index()
*/

int			ft_atod(const char *str, float *ret)
{
	int		j;
	float	post;
	float	sign;

	post = 0;
	*ret = 0;
	if (!str)
		*ret = -1;
	if (!str || str[0] == '\0' || forbidden_char(str))
		return (-1);
	j = ft_atod_int(str, ret, &sign);
	if (str[j++] == '.')
		post = ft_atod_bis(j, post, str);
	*ret = *ret + floor(pow(10, 4) *
		(*ret < (float)0 ? -post : post)) / pow(10, 4);
	*ret *= sign == 1 ? 1 : -1;
	return (1);
}
