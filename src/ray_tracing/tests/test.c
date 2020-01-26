/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 10:41:04 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../libx/minilibx_opengl/mlx.h"
#include <stdio.h>

int main(void)
{
	void *mlx;
	void *window;

	if (!(mlx = mlx_init()))
	{
		printf("erreur initiation\n");
		return (0);
	}
	window = mlx_new_window(mlx, 1500 , 1500, "So");
	int i;
	int j;
	int xc;
	int yc;
	int r;
	int color;
	int bole;
	int color_display;

	xc = 750;
	yc = 750;
	r = 500;
	int r_mod = 1000;
	color = 255;
	int color2 = 500 * 65555;
	i = xc - r;
	bole = 0;
	

	while (i < r + xc)
	{
		j = yc - r;
		if (i % 50 == 0)
			bole = bole == 1 ? 0 : 1;
		while (j < r + yc)
		{
			if (j % 50 == 0)
				bole = bole == 1 ? 0 : 1;
			color_display = !bole ? color++ : color2++;
			if (r_mod * r_mod > ((i - xc) * (i - xc) + (j - yc) * (j - yc)))
			{
				mlx_pixel_put(mlx, window, i, j, color_display);
				r_mod -= 10;
			}
			j++;	
		}
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
