/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:22:28 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 15:56:28 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char			*strcpy;
	unsigned int	i;

	strcpy = (char *)str;
	i = 0;
	while (i < n)
	{
		if (strcpy[i] == c)
			return (strcpy + i);
		i++;
	}
	return (0);
}
