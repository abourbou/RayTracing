/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cal_color.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 14:15:23 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 16:01:57 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ray_tracing.h"
#include "../include/shapes.h"

void    color_limit(double u[3], double min, double max)
{
    if (u[0] < min || u[0] > max)
        u[0] = (u[0] > max) ? max : min;
    if (u[1] < min || u[1] > max)
        u[1] = (u[1] > max) ? max : min;
    if (u[2] < min || u[2] > max)
        u[2] = (u[2] > max) ? max : min;
}

void    add_al(t_al *al, double objet_color[3], double final_color[3])
{
    vec_copy(final_color, al->color);
    multvec(al->ratio / 255.0, final_color, final_color);
    mult2vec(objet_color, final_color, final_color);
    //printf("add_al final_color : (%.3lf, %.3lf, %.3lf)\n",
    //final_color[0], final_color[1], final_color[2]);
    color_limit(final_color, 0, 255.0);
}

void    find_color_obj(double color[3], t_obj *t_obj)
{
    t_sp    *sp;

    if (t_obj->type == _sphere)
    {
        sp = t_obj->obj;
        vec_copy(color, sp->color);
    }
}

/*
**  ADD_VAL_DIFFUS
**  ajout la composante de reflexion diffuse sur le rayon
**  color += C * I * max(I.N, 0)
**  avec C : couleur obj, I : couleur lumiere, 
**  I.N : prod scalaire entre I le rayon de l'intersection vers la lumiere et 
**  N le vecteur normal a la surface
*/

void    add_val_diffus(t_inters *obj, t_inters *light, double final_color[3])
{
    double  buffer[3];
    double  buff;

    mult2vec(obj->color, light->color, buffer);
    //vec_copy(buffer, light->color);
    buff = fmax(scal_prod(light->normal, obj->normal), 0);
    //printf("buff : %lf\n", buff);
    multvec(buff / 255.0, buffer, buffer);
    //printf("add_reflex buffer : (%.3lf, %.3lf, %.3lf)\n",
    //buffer[0], buffer[1], buffer[2]);
    addvec(final_color, buffer, final_color);
    color_limit(final_color, 0, 255.0);
}

/*
**  ADD_VAL_SPECUL
**  ajout de la composante de reflexion speculaire
**  color += C * I * RATIO * (max(R.V, 0)^alpha)
**  R = 2 * (L.N) * N - L
**  avec C : couleur obj, I : couleur lumiere
**  RATIO : coeff reflexion speculaire / reflexion diffuse
**  R.N prod scalaire entre R le vecteur d'une reflexion parfaite du rayon
**  N la vecteur normal a la surface
**  L est le vecteur direction de la surface vers la source de lumiere
*/

void    add_val_specul(t_inters *obj, t_inters *light, double final_color[3], double view[3])
{
    double  buffer[3];
    double  buff;

    //mult2vec(obj->color, light->color, buffer);
    buff = 2 * scal_prod(light->normal, obj->normal);
    multvec(buff, obj->normal, buffer);
    minusvec(buffer, obj->normal, buffer); 
    buff = fmax(scal_prod(buffer, view), 0);
    buff = pow(buff, SHININESS);
    //printf("buff : %lf\n", buff);
    //printf("add_reflex buffer : (%.3lf, %.3lf, %.3lf)\n",
    //buffer[0], buffer[1], buffer[2]);
    addvec(final_color, buffer, final_color);
    color_limit(final_color, 0, 255.0); 
}

unsigned int conv_color(double final_color[3])
{
    unsigned int buffer;

    final_color[0] = round(final_color[0]);
    buffer = (unsigned int)final_color[0] * 0x10000;
    final_color[1] = round(final_color[1]);
    buffer += (unsigned int)final_color[1] * 0x100; 
    final_color[2] = round(final_color[2]);
    buffer += (unsigned int)final_color[2];
    return buffer;
}    


void    luminosity_standardization(t_info *info)
{
    double  sum;
    double  inv_sum;
    t_list *l_light;
    t_l     *light;

    l_light = info->l;
    sum = info->al.ratio;
    while (l_light)
    {
        light = l_light->content;
        sum += light->ratio;
        l_light = l_light->next;
    }
    inv_sum = 1 / sum;
    info->al.ratio *= inv_sum;
    l_light = info->l;
    while (l_light)
    {
        ((t_l *)l_light->content)->ratio *= inv_sum;
        l_light = l_light->next;
    }
}