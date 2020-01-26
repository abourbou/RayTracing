/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 16:21:29 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 11:03:49 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_elem;
	t_list	*next_elem;

	if (!lst || !(*lst) || !del)
		return ;
	current_elem = *lst;
	while (current_elem)
	{
		next_elem = current_elem->next;
		del(current_elem->content);
		free(current_elem);
		current_elem = next_elem;
	}
	*lst = 0;
}
