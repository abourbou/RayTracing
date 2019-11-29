/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_tracing.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 15:12:50 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 15:34:25 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H
# define pixelWidth (double)0.1
# define pixelHeight (double)0.1

//ration lumiere speculaire / lumiere diffuse
# ifndef RATIO
#  define RATIO 0.2
# endif

//  coefficient de brillance, 
//  plus il est grand, plus la tache blanche 
//  sera concentree, donc de petite taille. 
//  ce coefficient est tjrs plus grand que 1
# ifndef SHININESS
#  define  SHININESS 1.0
# endif

# include <math.h> 
# include "shapes.h"
# include "intersect_resolv.h"
# include "../minilibx_opengl/mlx.h"

// !   A ENLEVER FCT DE TEST
void ft_print_vec(char *str, double vec[3]);


/*
**FT_VECT
*/
void    cross_prod(double u[3], double v[3], double result[3]);
double   scal_prod(double u[3], double v[3]);
void    multvec(double a, double v[3], double result[3]);
void    addvec(double u[3], double v[3], double result[3]);
void    vec_copy(double dest[3], double src[3]);

/*
** FT_VEC2
*/
void    init_vec(double v[3], double a, double b, double c);
void    minusvec(double u[3], double v[3], double result[3]);
double  length_vec(double v[3]);
double  length_vec_2(double v[3]);
int     norme_vec(double u[3]);

/*
**  FT_VEC3
*/  
void    vec_to_point(double origin[3], double vect_direct[3], double dist, double result[3]);
double  vec_of_2_points(double start_pos[3], double end_pos[3], double result[3]);
void    mult2vec(double u[3], double v[3], double result[3]);
int    vec_cmp(double u[3], double v[3]);

/*
**  CAL_VIEW
*/
void    calc_view(t_line *line, double i, double j, t_info *info);
void    pix_coord(double pos_pix[3], double i, double j, t_ref *ref);

/*
**  CAL_COLOR
*/
void    add_al(t_al *al, double objet_color[3], double final_color[3]);
void    find_color_obj(double color[3], t_obj *t_obj);
void    add_val_diffus(t_inters *obj, t_inters *light, double final_color[3]);
void    add_val_specul(t_inters *obj, t_inters *light, double final_color[3], double view[3]);
unsigned int conv_color(double final_color[3]);
void    luminosity_standardization(t_info *info);

/*
**  RAY_TRACING
*/
void    ft_pix_coord(t_info *info, double fst_pix[3], double u[3], double v[3]);
void    ray_tracing(t_info *info, double width, double height, unsigned int *tab_img);
void    surface_normal_vect(t_obj *l_obj, double intersect[3], double result[3]);

#endif