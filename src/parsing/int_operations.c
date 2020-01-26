/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int_operations.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 10:04:43 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** Similar to ft_atod_index, but only for int
*/

int	int_len(int nbr)
{
	int	nb;
	int	ret;

	ret = nbr < 0 ? 2 : 1;
	nb = nbr < 0 ? -nbr : nbr;
	while (nb >= 10)
	{
		nb = nb / 10;
		ret++;
	}
	return (ret);
}
