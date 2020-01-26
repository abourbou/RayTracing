/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shape_type.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 09:35:11 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	shape_type(char *line)
{
	if (start_with(line, "sp"))
		return (0);
	if (start_with(line, "pl"))
		return (1);
	if (start_with(line, "sq"))
		return (2);
	if (start_with(line, "cy"))
		return (3);
	if (start_with(line, "tr"))
		return (4);
	return (-1);
}
