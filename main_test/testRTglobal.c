/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testRTglobal.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 12:12:02 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 15:06:26 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/shapes.h"
#include "../include/ray_tracing.h"

typedef struct s_fimg
{
    int bpp;
    int size_l;
    int endian;
} t_fimg;

typedef struct s_renderer
{
    int r_wid;
    int r_hei;
    int r_size;
    void *img_ptr;
    unsigned int *data;
    t_fimg img;

} t_renderer;

t_renderer *init_rdr(void *mlx, int width, int height)
{
    t_renderer *rdr;

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

t_resolv g_resolv[_size];

int main(void)
{
    t_info info;
    t_sp sphere;
    int *buffer_color;

    //
    void *mlx_ptr;
    void *win;
    t_renderer *rdr;

    int x = 1500; //LARGEUR FEN
    int y = 1000; //HAUTEUR FEN
    int xc = 800; //LARGUEUR IMG
    int yc = 800; //HAUTEUR IMG

    //INITIALISATION FENETRE && IMAGE
    mlx_ptr = mlx_init();
    if (x > 1500)
        x = 1500;
    if (y > 1000)
        y = 1000;
    if (xc > 800)
        xc = 800;
    if (yc > 800)
        yc = 800;
    win = mlx_new_window(mlx_ptr, x, y, "image");
    rdr = init_rdr(mlx_ptr, xc, yc);

    setup_resolv();

    //  INTIALISATION INFO.REF & INFO.CAM
    info.res.x = xc;
    info.res.y = yc;
    init_vec(info.cam.pos, 0, 0, 0);
    printf("\n\n ----------------rappel de pix_coord-----------------\n");
    ft_print_vec("cam pos :", info.cam.pos);
    info.cam.fov = 70;
    init_vec(info.cam.vect, 0, 0, 1);
    norme_vec(info.cam.vect);
    ft_print_vec("vecteur de vue ", info.cam.vect);
    double *fst_pix = info.ref.fst_pix;
    double *u = info.ref.u;
    double *v = info.ref.v;
    ft_pix_coord(&info, fst_pix, u, v);
    ft_print_vec("fst_pix :", fst_pix);
    ft_print_vec("u : ", u);
    ft_print_vec("v : ", v);
    ft_print_vec("w : ", info.cam.vect);
    double buffer[3];
    minusvec(fst_pix, info.cam.pos, buffer);
    printf("distance 1er pixel-pos_cam : %lf\n", length_vec(buffer));
    printf("\n----------------test du ray_tracing--------------------\n");

    //  INITIALISATION SPHERE

    init_vec(sphere.pos, 0.0, 0, 100.0);
    sphere.radius = 25;
    init_vec(sphere.color, 100.0, 100.0, 100.0);
    if (!(info.lst_obj = malloc(sizeof(t_obj))))
        return (0);
    info.lst_obj->type = 0;
    info.lst_obj->obj = &sphere;
    info.lst_obj->next = 0;

    //INITIALISATION LUMIERE AMBIANTE

    init_vec(info.al.color, 255.0, 0.0, 255.0);
    info.al.ratio = 0.1;

    //INTIALISATION LUMIERES

    t_list lst_l;
    t_l l;
    init_vec(l.pos, 150.0, 150.0, -100);
    init_vec(l.color, 10.0, 0, 255.0);
    l.ratio = 0.4;
    info.l = &lst_l;
    lst_l.content = &l;

    t_list   lst_l2;
    t_l l2;
    init_vec(l2.pos, 150.0, -150.0, -100);
    init_vec(l2.color, 10.0, 0, 255.0);
    l2.ratio = 0.8;
    lst_l2.content = &l2;
    lst_l2.next = 0;
    lst_l.next = &lst_l2;
    

    //UNIFORMISATION DES INTENSITE LUMINEURSE

    luminosity_standardization(&info);

    //INITIALISATION INFO.BUFFER_COLOR

    if (!(buffer_color = malloc(info.res.x * info.res.y * sizeof(int))))
        return (0);
    info.buffer_color = buffer_color;

    //printf("ambiance et lumiere : %lf et %lf\n", info.al.ratio, ((t_l *)info.l->content)->ratio);
    
    ray_tracing(&info, info.res.x, info.res.y, rdr->data);
    mlx_put_image_to_window(mlx_ptr, win, rdr->img_ptr, 200, 200);
	mlx_loop(mlx_ptr);
    printf("\n\n");

    return (0);
}