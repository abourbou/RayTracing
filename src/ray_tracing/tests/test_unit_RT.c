/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_unit_RT.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 09:23:29 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 09:38:07 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/raytracing.h"

void    test_vect(void);
void    test_search_inter(void);

void ft_print_vec(char *str, t_vect vec);

int main(void)
{
    // INITIALISATION

    t_param param;
    t_sp sphere;
    setup_resolv();
    param.res.x = 1;
    param.res.y = 1;
    init_vec(param.cam->pos, -50, 0, 20);
    param.cam->fov = 70;
    init_vec(param.cam->vec, 0, 0, 1);
    float *fst_pix = param.ref.fst_pix;
    float *u = param.ref.u;
    float *v = param.ref.v;
    ft_pix_coord(&param, fst_pix, u, v);

    init_vec(sphere.pos, -45, 0, 35);
    sphere.radius = 25;
    init_vec(sphere.color, 255.0, 0.0, 0.0); //sphere rouge

    if (!(param.lst_obj = malloc(sizeof(t_obj))))
        return (0);
    param.lst_obj->type = 0;
    param.lst_obj->obj = &sphere;
    param.lst_obj->next = 0;
    //ray_tracing(&param, param.res.x, param.res.y);

    test_vect(); //test sur les operations de vecteurs
    test_search_inter();
    return (0);
}

void test_vect(void)
{
    float a = 10;
    t_vect u = {-1, -1, -1};
    t_vect v = {1, 1, 1};
    float buff;
    t_vect buffer;
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

    buff = sq_len_vec(v);
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