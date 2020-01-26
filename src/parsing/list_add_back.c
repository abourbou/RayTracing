/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_add_back.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 09:37:07 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	add_back_obj(t_obj **lst, t_obj *t_obj_new)
{
	t_obj *current;

	if (*lst == 0)
	{
		*lst = t_obj_new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = t_obj_new;
}

void	add_back_light(t_l **lst, t_l *light_new)
{
	t_l *current;

	if (*lst == 0)
	{
		*lst = light_new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = light_new;
}

void	add_back_cam(t_c **lst, t_c *cam_new)
{
	t_c *current;

	if (*lst == 0)
	{
		cam_new->prev = 0;
		*lst = cam_new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	cam_new->prev = current;
	current->next = cam_new;
}
