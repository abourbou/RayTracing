/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 10:21:29 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 15:12:13 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"
#include "../../includes/tests.h"

static int		change_cam(int key, t_renderer *rdr, t_param *param)
{
	float	dist;

	if ((key == LEFT && !param->cam->prev) ||
	(key == RIGHT && !param->cam->next))
		return (0);
	param->cam = (key == LEFT) ? param->cam->prev
							: param->cam->next;
	dist = ft_pix_coord(param->cam, &param->res, &param->ref);
	if (!param->cam->image)
	{
		ray_tracing(param, param->res.x, param->res.y, rdr->data);
		if (!(param->cam->image = malloc(sizeof(unsigned int) * rdr->r_size)))
			error_window(rdr, 4);
		ft_memcpy(param->cam->image, rdr->data,
			sizeof(unsigned int) * rdr->r_size);
	}
	else
		ft_memcpy(rdr->data, param->cam->image,
			sizeof(unsigned int) * rdr->r_size);
	if (!(mlx_clear_window(rdr->mlx, rdr->win)))
		error_window(rdr, 5);
	if (!(mlx_put_image_to_window(rdr->mlx, rdr->win, rdr->img_ptr, 0, 0)))
		error_window(rdr, 6);
	show_distance(rdr, dist);
	return (0);
}

int				error_window(t_renderer *rdr, int nb)
{
	if (nb == 0)
		ft_putstr_fd("Error\nFirst cam->image failed\n", 2);
	else if (nb == 1)
		ft_putstr_fd("Error\nprint_image failed\n", 2);
	else if (nb == 2)
		ft_putstr_fd("Error\nmlx_put_image_to_window failed\n", 2);
	else if (nb == 3)
		ft_putstr_fd("Error\nP key : print_image failed\n", 2);
	else if (nb == 4)
		ft_putstr_fd("Error\nMalloc failed in change_cam\n", 2);
	else if (nb == 5)
		ft_putstr_fd("Error\nmxl_clear_window failed in change_cam\n", 2);
	else if (nb == 6)
		ft_putstr_fd("Error\nmlx_put_image_to_window failed in change_cam\n",
																		2);
	free_window(rdr->mlx, rdr->win, rdr, rdr->param);
	exit(-1);
}

static int		key_pressed(int key, t_renderer *rdr)
{
	if (rdr->param->save == 1)
	{
		if (print_image(rdr) == -1)
			error_window(rdr, 3);
		rdr->param->save = 0;
	}
	if (key == ESC)
		exit_program(rdr);
	else if (key == T)
		ft_putstr_fd("test\n", 1);
	else if (key == P)
	{
		if (print_image(rdr) == -1)
			error_window(rdr, 3);
	}
	else if (key == LEFT || key == RIGHT)
		return (change_cam(key, rdr, rdr->param));
	return (0);
}

int				exit_program(t_renderer *rdr)
{
	free_window(rdr->mlx, rdr->win, rdr, rdr->param);
	exit(0);
}

/*
**	OPEN_WINDOW
**	dist : display eye->screen distance on screen
*/

int				open_window(t_param *param)
{
	void		*mlx_ptr;
	void		*win;
	t_renderer	*rdr;
	float		dist;

	if (set_up_mlx(param, &mlx_ptr, &win, &rdr) == -1)
	{
		ft_putstr_fd("Error\nSet_up_mlx failed\n", 2);
		return (free_params(param));
	}
	setup_resolv();
	dist = ft_pix_coord(param->cam, &param->res, &param->ref);
	ray_tracing(param, param->res.x, param->res.y, rdr->data);
	if (!(param->cam->image = malloc(sizeof(unsigned int) * rdr->r_size)))
		return (error_window(rdr, 0));
	ft_memcpy(param->cam->image, rdr->data, sizeof(unsigned int) * rdr->r_size);
	if (!mlx_put_image_to_window(mlx_ptr, win, rdr->img_ptr, 0, 0))
		return (error_window(rdr, 2));
	show_distance(rdr, dist);
	mlx_key_hook(win, key_pressed, rdr);
	mlx_hook(win, 17, (1L << 17), exit_program, rdr);
	mlx_loop(mlx_ptr);
	return (0);
}
