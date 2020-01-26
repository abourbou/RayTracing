/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raytracing.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:13:44 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:08:47 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H
# define PIXELWIDTH 0.1
# define PIXELHEIGHT 0.1

/*
** ALPHA for speculaire, EPSILON for precision
*/
# define ALPHA 50.0
# define EPSILON 0.05

/*
** Mac binding
*/
# define ESC 53
# define P 35
# define LEFT 123
# define RIGHT 124
# define D 2
# define A 0
# define T 17

/*
**	Max resolution
*/
# define MAX_X 1600
# define MAX_Y 1200

# include "shapes.h"
# include "intersect_resolv.h"
# include "parsing.h"
# include "../libx/minilibx_opengl/mlx.h"
# include "../libft/libft.h"

typedef struct	s_fimg
{
	int bpp;
	int size_l;
	int endian;
}				t_fimg;

typedef	struct	s_renderer
{
	int				r_wid;
	int				r_hei;
	int				r_size;
	void			*win;
	void			*mlx;
	void			*img_ptr;
	t_param			*param;
	unsigned int	*data;
	t_fimg			img;
}				t_renderer;

typedef	struct	s_line
{
	t_vect			orig;
	t_vect			ray;
}				t_line;

typedef	struct	s_inters
{
	float			dist;
	t_vect			point;
	t_vect			normal;
	t_vect			color;
	t_obj			*obj_inters;
}				t_inters;

/*
**FT_VECT
*/
void			cross_prod(t_vect u, t_vect v, t_vect result);
float			scal_prod(t_vect u, t_vect v);
void			multvec(float a, t_vect v, t_vect result);
void			addvec(t_vect u, t_vect v, t_vect result);
void			vec_copy(t_vect dest, t_vect src);

/*
** FT_VEC2
*/
void			init_vec(t_vect v, float a, float b, float c);
void			minusvec(t_vect u, t_vect v, t_vect result);
float			length_vec(t_vect v);
float			sq_len_vec(t_vect v);
int				norme_vec(t_vect u);

/*
**  FT_VEC3
*/
void			vec_to_point(t_vect origin, t_vect vect_direct, float dist,
					t_vect result);
float			vec_of_2_points(t_vect start_pos, t_vect end_pos,
					t_vect result);
void			mult2vec(t_vect u, t_vect v, t_vect result);
int				vec_cmp(t_vect u, t_vect v);
void			rotation(t_vect axis, float angle, t_vect u, t_vect result);

/*
**  CAL_COORD
*/
void			pix_coord(t_vect pos_pix, float i, float j, t_ref *ref);
void			init_uv_ref(t_vect normal, t_vect u, t_vect v);
void			init_ref_square(t_obj *l_obj);
void			init_ref_cylinder(t_obj *l_obj);

/*
**  CAL_COLOR
*/
void			color_limit(t_vect u, float min, float max);
void			add_al(t_al *al, t_inters *inters_obj, t_vect final_color);
void			add_val_diffus(t_inters *obj, t_inters *light,
					t_vect final_color);
void			add_val_specul(t_inters *obj, t_inters *light,
					t_vect final_color, t_vect view);
unsigned int	conv_color(t_vect final_color);

/*
**  OPEN_WINDOW
*/
int				open_window(t_param *param);
int				exit_program(t_renderer *rdr);
int				error_window(t_renderer *rdr, int nb);

/*
**  OPEN_WINDOW2
*/

t_renderer		*init_rdr(void *mlx, int width, int height, t_param *param);
int				free_window(void *mlx_ptr, void *win, t_renderer *rdr,
															t_param *param);
int				set_up_mlx(t_param *param, void **mlx_ptr, void **win,
														t_renderer **rdr);
void			show_distance(t_renderer *rdr, float dist);

/*
**  RAY_TRACING
*/

float			ft_pix_coord(t_c *cam, t_r *res, t_ref *ref);
void			ray_tracing(t_param *param, float width,
					float height, unsigned int *tab_img);
void			search_inters(t_line *line, t_obj *lst_obj,
					t_inters *inters, int is_light);
void			calc_inters_obj(t_line *line, t_param *param,
					t_inters *inters, t_vect coord);

/*
** SURFACE_NORMAL_VECT
*/
void			surface_normal_vect(t_obj *l_obj, t_vect intersect,
					t_vect direct, t_vect result);

/*
**  IS_NULL
*/
int				is_null(float u);
int				is_very_null(float u);

/*
**  print_image.c
*/
int				print_image(t_renderer *rdr);

#endif
