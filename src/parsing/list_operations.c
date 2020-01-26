/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_operations.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 09:36:49 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	obj_init(t_obj *l_obj, int type)
{
	l_obj->type = type;
	l_obj->color[0] = -1;
	l_obj->color[1] = -1;
	l_obj->color[2] = -1;
	l_obj->carac = 0;
	l_obj->next = 0;
}

void	param_lsts_init(t_param *param, int *error)
{
	param->cam = 0;
	param->l = 0;
	param->lst_obj = 0;
	*error = 0;
}
