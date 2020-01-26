/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ut_get_vect.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:59:45 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shapes.h"

//TODO BETTER

int main(void)
{
    float pos[3];
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;
    float t_vect[3];
    t_vect[0] = 0;
    t_vect[1] = 0;
    t_vect[2] = 0;
    char *line = calloc(100, 1);
    line = "l -50.0,0,20 -.5,.5,0       90         ";
    int retval;
    retval = get_vect(line + 1, pos);
    printf("retval : |%d|\npos  : |%lf|%lf|%lf|\n", retval, pos[0], pos[1], pos[2]);
    line = " -.5,.5,0       90         ";
    retval = get_vect(line, t_vect);
    printf("retval : |%d|\nvect : |%lf|%lf|%lf|\n", retval, t_vect[0], t_vect[1], t_vect[2]);
}