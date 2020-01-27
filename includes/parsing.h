/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 10:40:39 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 10:15:39 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*
** For GNL, which is only used in parsing section
*/
# include <fcntl.h>
# include <sys/uio.h>
# include "./shapes.h"
# include "../libft/get_next_line.h"

/*
** atod.c
*/
int		ft_atod_index(const char *str);
int		ft_atod(const char *str, float *ret);

/*
** char_operations.c
*/
int		start_with(char *str, char *starter);

/*
** get_needed_param.c
*/
int		get_res(char *line, t_r *res);
int		get_al(char *line, t_al *al);
int		get_c(char *line, t_c **cam);

/*
** get_param.c
*/
int		get_l(char *line, t_l **light);

/*
** get_shape_param.c
*/
int		get_sp(char *line, t_obj *l_obj, t_vect color);
int		get_pl(char *line, t_obj *l_obj, t_vect color);
int		get_sq(char *line, t_obj *l_obj, t_vect color);
int		get_cy(char *line, t_obj *l_obj, t_vect color);
int		get_tr(char *line, t_obj *l_obj, t_vect color);

/*
** get_vect.c
*/
int		get_vect(const char *line, t_vect vector);
int		vect_is_valid(t_vect vect);

/*
** int_operations.c
*/
int		int_len(int nbr);

/*
** list_add_back.c
*/
void	add_back_obj(t_obj **lst, t_obj *t_obj_new);
void	add_back_light(t_l **lst, t_l *light_new);
void	add_back_cam(t_c **lst, t_c *cam_new);

/*
** list_clear.c
*/
void	lst_cam_clear(t_c **lst);
void	lst_light_clear(t_l **lst);
void	lst_obj_clear(t_obj **lst);

/*
** list_operations.c
*/
void	obj_init(t_obj *obj, int type);
void	lst_obj_init(t_param *param);
void	param_lsts_init(t_param *param, int *error);

/*
** norme_all.c
*/
int		norme_all(t_param *param);

/*
** parse_error_handling.c
*/
int		format_error(const char *funcname);
int		malloc_error(const char *funcname);
int		parse_error(const char *funcname);
int		skip_space_error(const char *funcname);
int		wrong_arg_count_error(const char *funcname);

/*
** parse_error_handling2.c
*/
int		free_params(t_param *param);
int		needed_param_missing_error(t_param *param);

/*
** parsing.c
*/
int		parsing(char *config_rt_path, t_param *param);
int		shape_type(char *line);

/*
** rgb2int.c
*/
int		rgb_to_int(char *str, int *i, t_vect color);

/*
** skip.c
*/
int		skip_space(char *line, int *i);
int		skip_check(char c, const char *func);
int		skip_vect(char *line, int *i, t_vect vector, const char *func);
int		get_cy_end(char *line, int *i, t_cy *cy, t_vect color);
int		get_sq_end(char *line, int *i, t_sq *sq, t_vect color);

#endif
