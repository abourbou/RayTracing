/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_pix_coord.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 10:08:48 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"
#include <stdio.h>

void	ft_print_vec(char *str, t_vect vec)
{
	printf("%s", str);
	printf("(%lf, %lf, %lf)\n", vec[0], vec[1], vec[2]);
}

int		main(void)
{
	t_param	param;
	t_vect		fst_pix;
	t_vect		u;
	t_vect		v;
	float		dist;

	ft_bzero(&param, sizeof(t_param));
	param.res.x = 1920.0;
	param.res.y = 1080.0;
	init_vec(param.cam->pos, -50, 0, 20);
    param.cam->fov = 70.0;
	init_vec(param.cam->vec, 0, 0, 1);
	printf("\n\n------------------INTERN--------------------\n\n");
	ft_pix_coord(&param, fst_pix, u, v);

	printf("\n\n------------------param---------------------\n\n");
	ft_print_vec("position cam : ", param.cam->pos);
	printf("res x : %lf res y : %lf\nPIXELWIDTH/PIXELHEIGHT : %lf/%lf\nFOV : %lf\n",
	param.res.x, param.res.y, PIXELWIDTH, PIXELHEIGHT, param.cam->fov);
	dist = param.res.x * PIXELWIDTH / (2.0 * tan(param.cam->fov / 360.0 * (float)M_PI));
	printf("dist : %lf\n\n", dist);

	printf("------------------TEST---------------------\n\n");
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	float		n = 1 / sqrtf(2);
	
	init_vec(param.cam->vec, n, n, 0);
	ft_pix_coord(&param, fst_pix, u, v);
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(param.cam->vec, 0, n, n);
	ft_pix_coord(&param, fst_pix, u, v);
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");
	
	init_vec(param.cam->vec, 0, -n, n);
	ft_pix_coord(&param, fst_pix, u, v);
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(param.cam->vec, n, 0, n);
	ft_pix_coord(&param, fst_pix, u, v);
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(param.cam->vec, n, n, 0);
	ft_pix_coord(&param, fst_pix, u, v);
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");

	init_vec(param.cam->vec, 0, n, n);
	ft_pix_coord(&param, fst_pix, u, v);
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");
	
	init_vec(param.cam->vec, 0, -n, n);
	ft_pix_coord(&param, fst_pix, u, v);
	ft_print_vec("cam vect : ", param.cam->vec);
	ft_print_vec("fst_pix : ", fst_pix);
	ft_print_vec("v : ", v);
	ft_print_vec("u : ", u);
	printf("\n\n");
	
	return (0);
}