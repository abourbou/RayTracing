/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 10:18:45 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:00:30 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

t_renderer	*init_rdr(void *mlx, int width, int height, t_param *param)
{
	t_renderer	*rdr;

	if (!(rdr = malloc(sizeof(t_renderer))))
	{
		ft_putstr_fd("Error\nrdr malloc allocation failed\n", 2);
		return (0);
	}
	*rdr = (t_renderer){.r_wid = width, .r_hei = height,
	.r_size = width * height, .mlx = mlx, .param = param};
	if (!(rdr->img_ptr = mlx_new_image(mlx, width, height)))
	{
		ft_putstr_fd("Error\nmlx_new_image failed\n", 2);
		free(rdr);
		return (0);
	}
	if (!(rdr->data = (unsigned int *)mlx_get_data_addr(rdr->img_ptr,
					&rdr->img.bpp, &rdr->img.size_l, &rdr->img.endian)))
	{
		ft_putstr_fd("Error\nmlx_get_data_addr failed\n", 2);
		mlx_destroy_image(mlx, rdr->img_ptr);
		free(rdr);
		return (0);
	}
	return (rdr);
}

int			free_window(void *mlx_ptr, void *win, t_renderer *rdr,
													t_param *param)
{
	if (rdr)
	{
		mlx_destroy_image(mlx_ptr, rdr->img_ptr);
		free(rdr);
	}
	if (win)
		mlx_destroy_window(mlx_ptr, win);
	return (free_params(param));
}

int			set_up_mlx(t_param *param, void **mlx_ptr, void **win,
													t_renderer **rdr)
{
	*mlx_ptr = mlx_init();
	if (param->res.x > MAX_X)
		param->res.x = MAX_X;
	if (param->res.y > MAX_Y)
		param->res.y = MAX_Y;
	if (!(*win = mlx_new_window(*mlx_ptr, 1600, 1200, "image")))
	{
		ft_putstr_fd("Error \nmlx_new_window failed\n", 2);
		return (free_params(param));
	}
	if (!(*rdr = init_rdr(*mlx_ptr, (int)param->res.x,
							(int)param->res.y, param)))
		return (free_window(*mlx_ptr, *win, *rdr, param));
	(*rdr)->win = *win;
	return (0);
}

void		show_distance(t_renderer *rdr, float dist)
{
	char *str1;
	char *str2;

	if (!(str1 = ft_itoa((int)dist)))
	{
		ft_putstr_fd("Error\nMalloc error in show_distance\n", 2);
		free_window(rdr->mlx, rdr->win, rdr, rdr->param);
		exit(-1);
	}
	if (!(str2 = ft_strjoin("eye->screen distance : ", str1)))
	{
		ft_putstr_fd("Error\nMalloc error in show_distance\n", 2);
		free_window(rdr->mlx, rdr->win, rdr, rdr->param);
		free(str1);
		exit(-1);
	}
	mlx_string_put(rdr->mlx, rdr->win, 5, 12, 0xffffff, str2);
	free(str1);
	free(str2);
}
