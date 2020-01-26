/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   norme_all.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 10:56:36 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 15:00:42 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"
#include "../../libft/libft.h"

int			is_valable_triangle(t_tr *triangle)
{
	t_vect	d1;
	t_vect	d2;
	t_vect	d3;
	t_vect	vect_null;

	init_vec(vect_null, 0, 0, 0);
	vec_of_2_points(triangle->points[0], triangle->points[1], d1);
	vec_of_2_points(triangle->points[0], triangle->points[2], d2);
	cross_prod(d1, d2, d3);
	if (vec_cmp(vect_null, d3) == 1)
	{
		ft_putstr_fd("Error\nTriangle invalid : ", 2);
		ft_putstr_fd("Either 2 points or more are at the same spot ", 2);
		ft_putstr_fd("or the 3 points line up\n", 2);
		return (0);
	}
	return (1);
}

static int	norme_error(int type)
{
	ft_putstr_fd("Error\nVector has void values (0,0,0) in a ", 2);
	if (type == -1)
		ft_putstr_fd("Camera", 2);
	else if (type == _plane)
		ft_putstr_fd("Plane", 2);
	else if (type == _square)
		ft_putstr_fd("Square", 2);
	else if (type == _cylinder)
		ft_putstr_fd("Cylinder", 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}

static int	norme_all2(t_obj *obj, int test)
{
	while (obj)
	{
		if (obj->type == _plane)
			test = norme_vec(((t_pl*)obj->carac)->normal);
		else if (obj->type == _square)
			test = norme_vec(((t_sq*)obj->carac)->normal);
		else if (obj->type == _triangle)
			test = is_valable_triangle((t_tr*)obj->carac);
		else if (obj->type == _cylinder)
			test = norme_vec(((t_cy*)obj->carac)->normal);
		if (test != 1)
		{
			if (obj->type != _triangle)
				return (norme_error(obj->type));
			return (-1);
		}
		obj = obj->next;
	}
	return (0);
}

int			norme_all(t_param *param)
{
	t_obj	*obj;
	int		test;
	t_c		*cam;

	obj = param->lst_obj;
	cam = param->cam;
	test = 1;
	while (cam)
	{
		if (!norme_vec(cam->vec))
			return (norme_error(-1));
		cam = cam->next;
	}
	return (norme_all2(obj, test));
}
