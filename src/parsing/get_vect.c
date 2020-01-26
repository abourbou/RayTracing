/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_vect.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 14:04:49 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 14:51:17 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/raytracing.h"

/*
** Now returns the index
*/

int	get_vect(const char *line, t_vect vector)
{
	int			i;
	int			j;
	int			temp;
	const char	*str;

	i = 0;
	j = -1;
	temp = 0;
	while (++j < 3)
	{
		str = line + i;
		if (ft_atod(str, &vector[j]) == 0)
			return (-1);
		temp = ft_atod_index(str);
		i += temp;
		if (j == 2)
			break ;
		if (!(line[i] && line[i + 1]))
			return (-1);
		else if (is_in(line[i + 1], "0123456789-") && line[i] == ',')
			i++;
		else
			return (-1);
	}
	return (i);
}

int	vect_is_valid(t_vect vect)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (fabsf(vect[i]) > 1 + EPSILON)
			return (-1);
		i++;
	}
	return (0);
}
