/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_pix_coord.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 10:08:48 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 13:55:43 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/shapes.h"
#include "../include/ray_tracing.h"
#include <stdio.h>

void	ft_print_vec(char *str, double vec[3])
{
	printf("%s", str);
	printf("(%lf, %lf, %lf)\n", vec[0], vec[1], vec[2]);
}

int		main(void)
{
	t_info	info;
	double		fst_pix[3];
	double		u[3];
	double		v[3];
	double		dist;

	ft_bzero(&info, sizeof(t_info));
	info.res.x = 1920.0;
	info.res.y = 1080.0;
	init_vec(info.cam.pos, -50, 0, 20);
    info.cam.fov = 70.0;
	init_vec(info.cam.vect, 0, 0, 1);
	printf("\n\n------------------INTERN--------------------\n\n");	
	ft_pix_coord(&info, fst_pix, u, v);

	printf("\n\n------------------INFO---------------------\n\n");
	ft_print_vec("position cam : ", info.cam.pos);
	printf("res x : %lf res y : %lf\npixelWidth/pixelHeight : %lf/%lf\nFOV : %lf\n",
	info.res.x, info.res.y, pixelWidth, pixelHeight, info.cam.fov);
	dist = info.res.x * pixelWidth / (2.0 * tan(info.cam.fov / 360.0 * (double)M_PI));
	printf("dist : %lf\n\n", dist);

	printf("------------------TEST---------------------\n\n");
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	double		n = 1 / sqrt(2);
	
	init_vec(info.cam.vect, n, n, 0);
	ft_pix_coord(&info, fst_pix, u, v);
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(info.cam.vect, 0, n, n);
	ft_pix_coord(&info, fst_pix, u, v);
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");
	
	init_vec(info.cam.vect, 0, -n, n);
	ft_pix_coord(&info, fst_pix, u, v);
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(info.cam.vect, n, 0, n);
	ft_pix_coord(&info, fst_pix, u, v);
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(info.cam.vect, n, n, 0);
	ft_pix_coord(&info, fst_pix, u, v);
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(info.cam.vect, 0, n, n);
	ft_pix_coord(&info, fst_pix, u, v);
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");
	
	init_vec(info.cam.vect, 0, -n, n);
	ft_pix_coord(&info, fst_pix, u, v);
	ft_print_vec("cam vect : ", info.cam.vect);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");
	
	return (0);
}