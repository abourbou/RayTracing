// Takes __func__ as param
//! DO NOT PUSH

#include "../../../includes/raytracing.h"
#include "../../../includes/parsing.h"
#include "../../../includes/shapes.h"
#include "../../../includes/tests.h"
#include <stdio.h>

void    lookatme(char *funcname)
{
    printf("HEY LOOK AT MEEE I'M IN %s\n", funcname);
}

void    print_vect(char *part, char *param_name, t_vect color)
{
    printf("%s %s 1 : %f\n", part, param_name, color[0]);
    printf("%s %s 2 : %f\n", part, param_name, color[1]);
    printf("%s %s 3 : %f\n", part, param_name, color[2]);
}

void    print_sphere(t_sp *sp)
{
    print_vect("sp", "pos", sp->pos);
    printf("sp radius : %f\n", sp->radius);
}

void    print_plane(t_pl *pl)
{
    print_vect("pl", "pos", pl->pos);
    print_vect("pl", "normal", pl->normal);
}

void    print_square(t_sq *sq)
{
    print_vect("sq", "pos", sq->pos);
    print_vect("sq", "normal", sq->normal);
    printf("sq side : %f\n", sq->side);
    printf("sq angle : %f\n", sq->angle);
    printf("TODO : print triangle[2]\n");
}

void    print_cylinder(t_cy *cy)
{
    print_vect("cy", "pos", cy->pos);
    print_vect("cy", "normal", cy->normal);
    printf("cy radius : %f\n", cy->radius);
    printf("cy height : %f\n", cy->height);
    printf("TODO : print t_ref\n");
}

void    print_triangle(t_tr *tr)
{
    print_vect("tr", "point 1", tr->points[0]);
    print_vect("tr", "point 2", tr->points[1]);
    print_vect("tr", "point 3", tr->points[2]);
}

void    print_all_param(t_param *param)
{
    printf("R : %lf %lf\n", param->res.x, param->res.y);

    printf("A : %lf\n", param->al.ratio);
    print_vect("A", "color", param->al.color);

    t_c *tc;
    int i = 0;

    tc = param->cam;
    while (tc)
    {
        i++;
        printf("\nl%d\n", i);
        print_vect("c", "pos", param->cam->pos);
        print_vect("c", "vec", param->cam->vec);
        printf("c->fov : %lf\n", param->cam->fov);
        tc = tc->next;
    }

    t_l *tl;
    i = 0;

    tl = param->l;
    while (tl)
    {
        i++;
        printf("\nl%d\n", i);
        print_vect("l", "pos", tl->pos);
        print_vect("l", "color", tl->color);
        printf("l ratio : %lf\n", tl->ratio);
        tl = tl->next;
    }

    printf("\n");

    t_obj *current;

    current = param->lst_obj;
    while (current)
    {
        if (current)
        {
            printf("obj type %d\n", current->type);
            ft_print_vec("obj color ", current->color);
            if (current->type == _sphere)
                print_sphere((t_sp*)current->carac);
            if (current->type == _plane)
                print_plane((t_pl*)current->carac);
            if (current->type == _square)
                print_square((t_sq*)current->carac);
            if (current->type == _cylinder)
                print_cylinder((t_cy*)current->carac);
            if (current->type == _triangle)
                printf("TR : Function to rework\n");
            //     print_triangle((t_tr*)current->carac);
        }
        current = current->next;
        printf("\n");
    }
    printf("\n");
}

void    print_line_and_retval(char *line, int retval)
{
	printf("|%d| => ", retval);
	printf("%s\n", line);
}
