/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testRTglobal.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 12:12:02 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/raytracing.h"

t_renderer	*init_rdr(void *mlx, int width, int height)
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

#define ESC 53

int		key_pressed(int key)
{
	if (key == ESC)
		exit(1);
	return (0);
}

int	main(void)
{
	t_param param;
    t_sp sphere;

    void *mlx_ptr;
    void *win;
    t_renderer *rdr;

    int x = 10000; //LARGEUR FEN
    int y = 10000; //HAUTEUR FEN
    int xc = 10000; //LARGUEUR IMG
    int yc = 10000; //HAUTEUR IMG

    /*
     xc = 1;
     yc = 1;
    */

    //INITIALISATION FENETRE && IMAGE
    mlx_ptr = mlx_init();
    if (x > 1600)
        x = 1600;
    if (y > 1200)
        y = 1200;
    if (xc > 1600)
        xc = 1600;
    if (yc > 1200)
        yc = 1200;
    win = mlx_new_window(mlx_ptr, x, y, "image");
    rdr = init_rdr(mlx_ptr, xc, yc);

    setup_resolv();

    //  INTIALISATION param.REF & param.CAM
    param.res.x = xc;
    param.res.y = yc;
    init_vec(param.cam->pos, 0.0, 0, 0);
    //printf("\n\n ----------------rappel de pix_coord-----------------\n");
    //ft_print_vec("cam pos :", param.cam->pos);
    param.cam->fov = 70;
    init_vec(param.cam->vec, 0.0, 0.0, 1);
    norme_vec(param.cam->vec);
    //ft_print_vec("vecteur de vue ", param.cam->vec);
    float *fst_pix = param.ref.fst_pix;
    float *u = param.ref.u;
    float *v = param.ref.v;
    ft_pix_coord(&param, fst_pix, u, v);
    /*
    ft_print_vec("fst_pix :", fst_pix);
    ft_print_vec("u : ", u);
    ft_print_vec("v : ", v);
    ft_print_vec("w : ", param.cam->vec);
    */
    //vect buffer;
    //minusvec(fst_pix, param.cam->pos, buffer);
    //printf("distance 1er pixel-pos_cam : %lf\n", length_vec(buffer));
    //printf("\n----------------test du ray_tracing--------------------\n");

    //  INITIALISATION SPHERE

    init_vec(sphere.pos, -200.0, 200.0, 900.0);
    sphere.radius = 100;
    if (!(param.lst_obj = malloc(sizeof(t_obj))))
        return (0);
    init_vec(param.lst_obj->color, 150.0, 0, 75.0);

    t_obj   *obj2;
    t_sp sphere2;

    if (!(obj2 = malloc(sizeof(t_obj))))
        return (0);
    init_vec(sphere2.pos, 0.0, -155.0, 750.0);
    sphere2.radius = 75;
    init_vec(obj2->color, 255.0, 0, 0.0);
    param.lst_obj->type = 0;
    param.lst_obj->obj = &sphere;
    param.lst_obj->next = 0;

    obj2->type = _sphere;
    obj2->obj = &sphere2;
    obj2->next = 0;
    param.lst_obj->next = obj2;
    //obj2 = param.lst_obj;

    // INITIALISATION PLANE

    t_obj *obj3;
    t_pl pl1;
    obj3 = malloc(sizeof(t_obj));
    init_vec(pl1.pos, -100.0, 0.0, 1500.0);
    init_vec(pl1.normal, 0.0, 0.0, -1.0);
    init_vec(obj3->color, 122.0, 122.0, 122.0);
    obj3->type = 1;
    obj3->obj = &pl1;
    obj3->next = 0;
    obj2->next = obj3;


    t_obj   *obj4;

    obj4 = malloc(sizeof(t_obj));

    //INITIALISATION TRIANGLE

    t_tr    triangle;
    init_vec(triangle.points[0], -250.0, -300.0, 700.0);
    init_vec(triangle.points[1], 0, 25.0, 700.0);
    init_vec(triangle.points[2], 250.0, -300.0, 700.0);
    init_vec(obj4->color, 0.0, 175.0, 0.0);
    obj4->type = _triangle;
    obj4->obj = &triangle;
    obj4->next = 0;
    obj3->next = obj4;


    //INITIALISATION SQUARE

    t_obj   *obj5;

    obj5 = malloc(sizeof(t_obj));

    t_sq    square;
    init_vec(square.pos, 200.0, 200.0, 900.0);
    init_vec(square.normal, -0.0, 0.0, 1.0);
    norme_vec(square.normal);
    //init_vec(square.color, 10.0, 175.0, 10.0);
    init_vec(obj5->color, 155.0, 0.195, 10.0);
    square.side = 250.0;
    square.angle = 0.0;
    obj5->type = _square;
    obj5->obj = &square;
    obj5->next = 0;
    obj4->next = obj5;

  /*  // BULLES

    t_obj   *obj6;
    t_sp sphere3;

    if (!(obj6 = malloc(sizeof(t_obj))))
        return (0);
    init_vec(sphere3.pos, 0.0, 55.0, 750.0);
    sphere3.radius = 25;
    init_vec(obj6->color, 255.0, 0, 0.0);
    
    obj6->type = _sphere;
    obj6->obj = &sphere3;
    obj6->next = 0;
    obj5->next = obj6;

    t_obj   *obj7;
    t_sp sphere4;

    if (!(obj7 = malloc(sizeof(t_obj))))
        return (0);
    init_vec(sphere4.pos, 200.0, 25.0, 750.0);
    sphere4.radius = 25;
    init_vec(obj7->color, 255.0, 0, 0.0);
    
    obj7->type = _sphere;
    obj7->obj = &sphere4;
    obj7->next = 0;
    obj6->next = obj7;
*/

    //INITIALISATION CYLINDRE

    t_obj   *obj8;
    t_cy    cyl;

   if (!(obj8 = malloc(sizeof(t_obj))))
        return (0);
    cyl.height = 200;
    init_vec(cyl.normal, 0.50, 0.25, -1.0);
    norme_vec(cyl.normal);
    init_vec(cyl.pos, -200, 0, 700);
    cyl.radius = 25;
    init_vec(obj8->color, 0.0, 0.0, 255.0);
    obj8->obj = &cyl;
    obj8->type = _cylinder;
    obj8->next = 0;
    //obj7->next = obj8;
    obj5->next = obj8;
/*

    t_obj   *obj9;
    t_cy    cyl2;

   if (!(obj9 = malloc(sizeof(t_obj))))
        return (0);
    cyl2.height = 200;
    init_vec(cyl2.normal, 1.0, 0.0, 0.0);
    norme_vec(cyl2.normal);
    init_vec(cyl2.pos, 200, 0, 700);
    cyl2.radius = 25;
    init_vec(obj9->color, 0.0, 0.0, 255.0);
    obj9->obj = &cyl2;
    obj9->type = _cylinder;
    obj9->next = 0;
    obj8->next = obj9;
*/

    //INITIALISATION LUMIERE AMBIANTE

    init_vec(param.al.color, 255.0, 255.0, 255.0);
    param.al.ratio = 0.3;

    //INTIALISATION LUMIERES

    t_l l;
    init_vec(l.pos, 0.0, 500.0, 0.0);
    init_vec(l.color, 200.0, 200.0, 255.0);
    l.ratio = 0.6;
    param.l = &l;

    t_l l2;
    init_vec(l2.pos, -1000.0, 300.0, 0.0);
    init_vec(l2.color, 255.0, 255.0, 255.0);
    l2.ratio = 0.0;
    l.next = 0; //&lst_l2;

    // ! FONCTION TIME A RETIRER
    //  MESURE TEMPS RAYTRACING
    
    #include <time.h>

    time_t begin = time(NULL);
    ray_tracing(&param, param.res.x, param.res.y, rdr->data);
    time_t end = time( NULL);
    unsigned long secondes = (unsigned long) difftime(end, begin);
    printf("raytracing in %ld sec\n", secondes);
   //  FIN FCT TIME

    mlx_put_image_to_window(mlx_ptr, win, rdr->img_ptr, 0, 0);
    mlx_key_hook(win, key_pressed, NULL);
    //! UNCOMMENT THIS FOR THE WHOLE THING TO WORK
    mlx_loop(mlx_ptr);

    return (0);
}