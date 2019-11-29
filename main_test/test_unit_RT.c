/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_unit_RT.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 09:23:29 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 09:28:56 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/shapes.h"
#include "../include/ray_tracing.h"

void    test_vect(void);
void    test_search_inter(void);

void ft_print_vec(char *str, double vec[3]);

int main(void)
{
    // INITIATION

    t_info info;
    t_sp sphere;
    setup_resolv();
    info.res.x = 1;
    info.res.y = 1;
    init_vec(info.cam.pos, -50, 0, 20);
    info.cam.fov = 70;
    init_vec(info.cam.vect, 0, 0, 1);
    double *fst_pix = info.ref.fst_pix;
    double *u = info.ref.u;
    double *v = info.ref.v;
    ft_pix_coord(&info, fst_pix, u, v);

    init_vec(sphere.pos, -45, 0, 35);
    sphere.radius = 25;
    sphere.color = 0xff0000; //sphere rouge

    if (!(info.lst_obj = malloc(sizeof(t_obj))))
        return (0);
    info.lst_obj->type = 0;
    info.lst_obj->obj = &sphere;
    info.lst_obj->next = 0;
    //ray_tracing(&info, info.res.x, info.res.y);
    //***************************************************************

    test_vect(); //test sur les operations de vecteurs
    test_search_inter();
    return (0);
}

void test_vect(void)
{
    double a = 10;
    double u[3] = {-1, -1, -1};
    double v[3] = {1, 1, 1};
    double buff;
    double buffer[3];
    printf("\n\n-----------TEST------------------\n\n");

    ft_print_vec("u :", u);
    ft_print_vec("v :", v);
    printf("\n");

    cross_prod(u, v, buffer);
    ft_print_vec("prod vect : ", buffer);

    printf("prod scal : %lf\n", scal_prod(u, v));

    multvec(a, u, buffer);
    ft_print_vec("mult de u par 10 : ", buffer);

    addvec(u, v, buffer);
    ft_print_vec("addition : ", buffer);

    vec_copy(buffer, u);
    ft_print_vec("copie de u : ", buffer);

    init_vec(buffer, -1, 0, 55);
    ft_print_vec("initialisation d'un vect à (-1, 0, 55) : ", buffer);

    minusvec(u, v, buffer);
    ft_print_vec("soustraction : ", buffer);
    printf("\n");

    buff = length_vec(u);
    printf("norme de u : %lf\n", buff);

    buff = length_vec_2(v);
    printf("norme au carre de v : %lf\n", buff);

    vec_copy(buffer, v);
    if (!norme_vec(buffer))
        printf("norme impossible, vecteur nul\n");
    ft_print_vec("vecteur normalisé a parti de v : ", buffer);
    printf("norme du vecteur normalisé : %lf\n", length_vec(buffer));
    printf("\n");

    vec_to_point(u, v, 5, buffer);
    ft_print_vec("point qui part de u et parcourt une distance de 5 dans la direction de v : ", buffer);
    
    buff = vec_of_2_points(u, v, buffer);
    printf("distance entre u et v : %lf\n", buff);
    ft_print_vec("vecteur de u vers v (normalise): ", buffer);

    printf("\n--------------------------------\n\n");
}

void    test_search_inter(void)
{
    
}