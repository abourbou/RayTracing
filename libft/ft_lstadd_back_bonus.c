/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back_bonus.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 16:14:22 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 12:11:22 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current_elem;

	if (alst == 0)
		return ;
	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	current_elem = *alst;
	while (current_elem->next)
		current_elem = current_elem->next;
	current_elem->next = new;
}
