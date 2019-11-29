/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shapes.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 15:39:13 by jotrique     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 11:40:23 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef	SHAPES_H
# define SHAPES_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>

/*
** Color is RGB in a single int value;
*/

typedef	double vector[3];

typedef struct	s_r
{
	double		x;
	double	 	y;
}				t_r;

/*
** ratio goes from 0 to 1;
*/
typedef struct	s_al
{
	double 	ratio;
	double	color[3];
}				t_al;

/*
** pos is the coordinates of the view point;
** vect is the 3d normalized orientation vector. Range [-1, 1] for each axis;
*/
typedef struct	s_c
{
	double	pos[3];
	double	vect[3];
	double	fov;
}				t_c;

/*
** ratio == [0, 1];
*/
typedef struct s_l
{
	double	pos[3];
	double	ratio;
	double	color[3];
}				t_l;

typedef	struct s_obj
{
	int				type;
	void			*obj;
	struct s_obj	*next;
}				t_obj;

typedef struct s_sp
{
	double	pos[3];
	double	radius;
	double	color[3];
}				t_sp;

typedef	struct s_ref
{
	double	fst_pix[3];
	double	u[3];
	double	v[3];
}				t_ref;

typedef	struct s_line
{
	double	orig[3];
	double	ray[3];
}				t_line;

typedef	struct s_inters
{
	double	dist;
	double	point[3];
	double	normal[3];
	double	color[3];
	t_obj	*obj_inters;
}				t_inters;

typedef struct s_info
{
	t_r		res;
	t_al	al;
	t_c		cam;
	t_list	*l;
	t_obj	*lst_obj;
	t_ref 	ref;
	int		*buffer_color;
}				t_info;

#endif