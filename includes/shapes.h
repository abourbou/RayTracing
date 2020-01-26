/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shapes.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 11:39:51 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include <math.h>

enum			e_type
{
	_sphere = 0,
	_plane,
	_square,
	_cylinder,
	_triangle,
	_size
};

typedef	float	t_vect[3];

typedef	struct	s_ref
{
	t_vect	fst_pix;
	t_vect	u;
	t_vect	v;
}				t_ref;

typedef struct	s_r
{
	float		x;
	float		y;
}				t_r;

/*
** ratio goes from 0 to 1;
** Color is in RGB;
*/

typedef struct	s_al
{
	float	ratio;
	t_vect	color;
}				t_al;

/*
** pos is the coordinates of the view point;
** vect is the 3d normalized orientation vector. Range [-1, 1] for each axis;
*/

typedef struct	s_c
{
	t_vect			pos;
	t_vect			vec;
	float			fov;
	unsigned int	*image;
	struct s_c		*prev;
	struct s_c		*next;
}				t_c;

/*
** ratio == [0, 1];
*/

typedef struct	s_l
{
	t_vect		pos;
	t_vect		color;
	float		ratio;
	struct s_l	*next;
}				t_l;

typedef	struct	s_obj
{
	int				type;
	t_vect			color;
	void			*carac;
	struct s_obj	*next;
}				t_obj;

/*
** Shapes
*/

typedef struct	s_sp
{
	t_vect	pos;
	float	radius;
}				t_sp;

typedef struct	s_pl
{
	t_vect	pos;
	t_vect	normal;
}				t_pl;

typedef struct	s_tr
{
	t_vect	points[3];
}				t_tr;

typedef struct	s_sq
{
	t_vect	pos;
	t_vect	normal;
	float	side;
	float	angle;
	t_tr	triangle[2];
}				t_sq;

typedef struct	s_cy
{
	t_vect	pos;
	t_vect	normal;
	float	radius;
	float	height;
	t_ref	ref;
}				t_cy;

/*
** !Shapes
*/

typedef struct	s_param
{
	t_r		res;
	t_al	al;
	t_c		*cam;
	t_l		*l;
	t_obj	*lst_obj;
	t_ref	ref;
	int		save;
}				t_param;

typedef	int	(*t_shape_func)(char *, t_obj *, t_vect);

#endif
