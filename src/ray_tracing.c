/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_tracing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 15:16:24 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 15:47:10 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ray_tracing.h"
#include "../include/shapes.h"

/*
** CALCUL DU BORD DE L'ECRAN ET DES DEUX VECTEURS COORDONNES 
**
**  pos centre ecran
**  E = C + dist * vec_view
**  avec                dist = L * pixelWidth / (2 * tan(theta / 2))
**                      theta est la FOV largueur
**                      vec_view est le vecteur direction de la vue
**                      C est la position de l'oeil
**                      E position du centre de l'ecran               
**
**  calcul des deux vecteurs u et v qui serviront de transformer 
**  la position des pixels dans notre espace 3D
**
**  v = [0,1,0] (le vecteur y) par defaut 
**  sauf si w est parallele a y, v =[0, 0, +/-1] (le vecteur z positif si tu 
**  regarde en bas et negatif si tu regardes en haut)
**  u = w ^ up_vec   avec up_vec = y ou si w est parallele a y, up_vec = x
**  v = u ^ w
**
**  calcul du pixel en haut a gauche de l'ecran
**  first_pixel = C - L/2 * u * pixelWidth + H / 2 * v * pixelHeight+ pixelWidth / 2 * u - pixelHeight / 2 * v
*/

void    ft_pix_coord(t_info *info, double fst_pix[3], double u[3], double v[3])
{
    double   w[3];
    double   buffer[3];
    double   dist;

    dist = info->res.x * pixelWidth / (2.0 * tan(info->cam.fov / 360 * (double)M_PI));
    vec_copy(w, info->cam.vect);
    multvec(dist, w, buffer);
    addvec(info->cam.pos, buffer, fst_pix);
    if (!w[0] && !w[2])
        init_vec(buffer, 0, 0, (w[1] > 0 ? -1 : 1));
    else
        init_vec(buffer, 0, 1, 0);
    cross_prod(buffer, w, u);
    norme_vec(u);
    cross_prod(w, u, v);
    norme_vec(v);
    multvec(info->res.x * 0.5 * pixelWidth, u, buffer);
    minusvec(fst_pix, buffer, fst_pix);
    multvec(info->res.y * 0.5 * pixelHeight, v, buffer);
    addvec(fst_pix, buffer, fst_pix);
    multvec(pixelWidth * 0.5, u, buffer);
    addvec(fst_pix, buffer, fst_pix);
    multvec(pixelHeight * 0.5, v, buffer);
    minusvec(fst_pix, buffer, fst_pix);
}

/*
**  INTERSECT
**  grosse fonction qui sert a calculer l'intersections la plus proche
**  avec les objets, ce calcul depends de l'objet
**  si l'intersection est la plus proche, on change les valeurs de inters
**  cad distance, point d'intersection et l'objet avec lequel il y a intersection
**  point_of_vec sert a trouver le point d'intersection a partir de la distance
**  
**    
*/
void   search_inters(t_line *line, t_obj *lst_obj, t_inters *inters, int is_light)
{
    double  dist;
    t_obj   *buffer;

    buffer = lst_obj;
    while (buffer)
    {
        dist = g_resolv[buffer->type](buffer->obj, line->orig, line->ray);
        if (dist > 0.0 && dist < inters->dist)
        {
            inters->dist = dist;
            inters->obj_inters = buffer;
        }
        buffer = buffer->next;
    }
    /*if (!inters->obj_inters)
    {
        printf("pas d'intersection\n");
        //return (0);
    }
    else*/
    if (inters->obj_inters)
    {
        vec_to_point(line->orig, line->ray, dist, inters->point);
        if (!is_light)
        {
            surface_normal_vect(inters->obj_inters, inters->point, inters->normal);
            find_color_obj(inters->color, inters->obj_inters);
        }
        else
            init_vec(inters->normal, 0, 0, 0);
        /*printf("vect normal (%.3lf, %.3lf, %.3lf)\n", inters->normal[0], inters->normal[1], inters->normal[2]);
        printf("color Obj : (%.3lf, %.3lf, %.3lf)\n", inters->color[0], inters->color[1], inters->color[2]);
        printf("point d'intersection (%.3lf, %.3lf, %.3lf)\n", inters->point[0], inters->point[1], inters->point[2]);*/
    }
    //return (1);
}

/*
**  CALCUL INTERSECTION OBJET
**  calcul d'abord les coordonnees du pixel puis le rayon qui va de l'oeil au pixel
**  et enfin trouve l'intersectin la plus proche avec un objet (ou l'intersection reste nulle si pas trouve)
*/

void    calc_inters_obj(t_line *line, t_info *info,  t_inters *inters, double coord[3])
{
   pix_coord(line->orig, coord[0], coord[1], &info->ref);
   //ft_print_vec("pix coord :", line->orig);
   vec_of_2_points(info->cam.pos, line->orig, line->ray);
   search_inters(line, info->lst_obj, inters, 0);
}

/*
**  RAY_TRACING
**  algo principale
**  etape 1 : calculer la position du pixel dans l'espace 3D avec le referenciel 
**  ref grace a pix_coord et en deduire la vecteur rayon avec calc_view
**  vecteur qui est normé
**  etape 2 : on calcule l'intersections avec les objets et trouver la plus courte
**  sinon intersection est egale a infinie
**  etape 3 : si l'on a trouvé une intersection, on calcule la couleur
*/

void        ray_tracing(t_info *info, double width, double height, unsigned int *tab_img)
{
    double  i;
    double  j;
    double  pos_pix[3];
    double  view[3];
    t_line  line;
    t_inters inters_obj;
    
    
    t_inters inters_l;
    t_list  *l_light;
    t_l     *light;

    double  final_color[3];

    i = 0;
    j = 0;
    //inters_obj.dist = INFINITY;

    /*
    inters_l.obj_inters = 0;
    init_vec(inters_l.color, 0, 0, 0);*/

    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            //printf("i : %lf, j : %lf\n", i, j);
            /*vec_copy(final_color, info->al.color); //peut importe le point, il y aura tjrs la luminosité de base
            multvec(info->al.ratio, final_color, final_color);*/
            init_vec(pos_pix, i, j, 0);
            //printf("buffer : (%.3lf, %.3lf, %.3lf)\n", buffer[0], buffer[1], buffer[2]);
            inters_obj.obj_inters = 0;
            inters_obj.dist = INFINITY;
            init_vec(inters_obj.color, 0, 0, 0);
            init_vec(final_color, 0, 0, 0);
            calc_inters_obj(&line, info, &inters_obj, pos_pix);
            
            /*

            if (i < 20 && j < 20)
                printf("dist : %lf\n", inters_obj.dist);
            // */ 
           
           if (inters_obj.dist != INFINITY)
            {
                //printf("obj inter : %p\n", inters_obj.obj_inters);
                add_al(&info->al, inters_obj.color, final_color);
                //printf("color Al + Obj : (%.3lf, %.3lf, %.3lf)\n", final_color[0], final_color[1], final_color[2]);
                
                
                l_light = info->l;
                while (l_light)
                {
                    light = l_light->content;
                    //on garde en memoire la vue pour la reflexion speculaire
                    vec_copy(view, line.ray);
                    multvec(-1.0, view, view);
                    //line devient le rayon de lumiere
                    vec_copy(line.orig, light->pos);
                    vec_of_2_points(light->pos, inters_obj.point, line.ray);
                    search_inters(&line, info->lst_obj, &inters_l, 1);
                    if (vec_cmp(inters_l.point, inters_obj.point))
                    {
                        //on a besoin de la couleur de la lumière
                        vec_copy(inters_l.color, light->color);
                        multvec(light->ratio, inters_l.color, inters_l.color);
                        // on a besoin de changer le sens de line.ray
                        multvec(-1.0, line.ray, line.ray);
                        vec_copy(inters_l.normal, line.ray);
                        /*
                        **  inters_l->normal contient le rayon de l'objet vers 
                        **  la source de lumiere
                        **  inters_l->couleur contient la couleur de la lumiere
                        */
                        //printf("normal : (%.3lf, %.3lf, %.3lf)\n", inters_obj.normal[0], inters_obj.normal[1], inters_obj.normal[2]);
                        add_val_diffus(&inters_obj, &inters_l, final_color);
                        add_val_specul(&inters_obj, &inters_l, final_color, view);
                    }
                    l_light = l_light->next;
                    
                }
                // */
                //printf("RT final_color : (%.3lf, %.3lf, %.3lf)\n", final_color[0], final_color[1], final_color[2]);
            }
            tab_img[(unsigned int)i * (unsigned int)width + (unsigned int)j] = conv_color(final_color); 
            //conv_col(inters.color);
            j++;
        }
        i++;
    }
    (void)inters_l;
    (void)l_light;
    (void)light;
}

