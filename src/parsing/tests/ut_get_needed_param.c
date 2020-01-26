#include "../../includes/shapes.h"

//TODO

//* get res
    /*
    t_param info;
    t_r     *res_p;
    res_p = &(info.res);
    res_p->x = 0;
    res_p->y = 0;
    char *line = calloc(100, 1);
    line = "R 1920 1320                a";
    //line = "R 1920 1320                a";
    int retval = get_res(line, res_p);
    printf("retval : |%d|\nres.x  : |%lf|\nres.y  : |%lf|\n", retval, info.res.x, info .res.y);
    */

    // * gnl_to_shape -> RES
    /*
    t_r     res;
    res.x = -1;
    res.y = -1;
    gnl_to_shapes(res);
    printf("x : %d\ny : %d\n", res.x, res.y);
    */

    // * get_al
    /*
    t_param info;
    t_al     *al_p;
    al_p = &(info.al);
    al_p->ratio = 0;
    al_p->color = 0;
    char *line = calloc(100, 1);
    line = "A 0.6 172,42,101                ";
    //line = "A 0.2 255,255,255                aawd";
    int retval = get_al(line, al_p);
    printf("retval : |%d|\n ratio : |%lf|\n color : |%d|\n", retval, info.al.ratio, info.al.color);
    */

    // * get_c
    /*
    t_param info;
    t_c     *c_p;
    c_p = &(info.cam);
    c_p->pos[0] = 0;
    c_p->pos[1] = 0;
    c_p->pos[2] = 0;
    c_p->vec[0] = 0;
    c_p->vec[1] = 0;
    c_p->vec[2] = 0;
    c_p->fov = 0;
    char *line = calloc(100, 1);
    line = "l -50.0,0,20 -0.5,0.5,0       90         ";
    int retval = get_c(line, c_p);
    printf("\nretval : %d\n", retval);
    printf("retval : |%d|\npos : |%lf|%lf|%lf|\n", retval, c_p->pos[0], c_p->pos[1], c_p->pos[2]);
    printf("vect : |%lf|%lf|%lf|\nfov : |%f|\n", c_p->vec[0], c_p->vec[1], c_p->vec[2], c_p->fov);
    */