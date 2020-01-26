/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_clear.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 09:36:30 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	lst_light_clear(t_l **lst)
{
	t_l	*current;
	t_l	*next;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = 0;
}

void	lst_cam_clear(t_c **lst)
{
	t_c	*current;
	t_c	*next;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current->prev)
		current = current->prev;
	while (current)
	{
		next = current->next;
		if (current->image)
			free(current->image);
		free(current);
		current = next;
	}
	*lst = 0;
}

void	lst_obj_clear(t_obj **lst)
{
	t_obj	*current;
	t_obj	*next;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = 0;
}
