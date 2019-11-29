/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_img.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 16:08:05 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 01:30:20 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../minilibx_opengl/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_fimg
{
    int bpp;
    int size_l;
    int endian;
}               t_fimg;


typedef struct		s_renderer
{
	int				r_wid;
	int				r_hei;
	int				r_size;
	void			*img_ptr;
	unsigned int	*data;
	t_fimg			img;

}					t_renderer;

/*
** Initialising renderer to make easier display and have better
** perfs
*/

t_renderer		*init_rdr(void *mlx, int width, int height)
{
	t_renderer	*rdr;

	rdr = NULL;
	if (mlx == NULL)
		return (NULL);
	if (!(rdr = malloc(sizeof(t_renderer))))
		return (NULL);
	rdr->r_wid = width;
	rdr->r_hei = height;
	rdr->r_size = width * height;
	rdr->img.size_l = 0;
	rdr->img.bpp = 0;
	rdr->img.endian = 0;
	rdr->img_ptr = mlx_new_image(mlx, width, height);
	rdr->data = (unsigned int *)mlx_get_data_addr(rdr->img_ptr, &rdr->img.bpp,
		&rdr->img.size_l, &rdr->img.endian);
	return (rdr);
}


int     main(void)
{
    void *mlx_ptr;
    void *win;
    t_renderer *rdr;
    int xc = 500; //LARGEUR
	int yc = 500; //HAUTEUR

    mlx_ptr = mlx_init();
    win = mlx_new_window(mlx_ptr, 1500, 1500, "image");
    rdr = init_rdr(mlx_ptr, yc, xc);
    int i;
	int j;
	
	int r;
	int color;
	int bole;
	int color_display = 0x909000;
	

    i = 0;

	while (i < yc)
	{
        j = 0;
	    while (j < xc)
        {
            rdr->data[i * yc + j] = color_display;
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx_ptr, win, rdr->img_ptr, 250, 250);
	mlx_loop(mlx_ptr);
}