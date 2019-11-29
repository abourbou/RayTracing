/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   intersect_resolv.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 20:18:33 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 08:58:34 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

enum    e_type
{
    _sphere = 0,
    _size
};

typedef double  (*t_resolv)(void *, double[3], double[3]);

t_resolv    g_resolv[_size];

/*
**  TEST_ENUM.C
*/

void    setup_resolv(void);
double  resolv_circ(void *obj, double pos[3], double ray[3]);