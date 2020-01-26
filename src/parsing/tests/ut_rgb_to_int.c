/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ut_rgb_to_int.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:00:06 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/parsing.h"

int main(void)
{
    //* init
    char *str = calloc(100, 1);
    int i = 0;
    int retval = 0;
    float color[3];

    //* valid cases
    printf("\nsimples valid cases :\n");

    str = "245,172,32";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    printf("\nr : |%d|\n", retval);
    printf("color[0] : |%.0f|\n", color[0]);
    printf("color[1] : |%.0f|\n", color[1]);
    printf("color[2] : |%.0f|\n", color[2]);
    printf("Should get %s\n", str);

    str = "0,0,0";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    printf("\nr : |%d|\n", retval);
    printf("color[0] : |%.0f|\n", color[0]);
    printf("color[1] : |%.0f|\n", color[1]);
    printf("color[2] : |%.0f|\n", color[2]);
    printf("Should get %s\n", str);

    //* invalid cases
    printf("\ninvalid cases :\n\n(only error message should appear)\n\n");

    str = "a,b,c";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    // printf("color[0] : |%f|\n", color[0]);
    // printf("color[1] : |%f|\n", color[1]);
    // printf("color[2] : |%f|\n", color[2]);
    if (retval != 0)
    {
        printf("\nr : |%d|\n", retval);
        printf("color[0] : |%f|\n", color[0]);
        printf("color[1] : |%f|\n", color[1]);
        printf("color[2] : |%f|\n", color[2]);
    }

    str = "0,0";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    // printf("color[0] : |%f|\n", color[0]);
    // printf("color[1] : |%f|\n", color[1]);
    // printf("color[2] : |%f|\n", color[2]);
    if (retval != 0)
    {
        printf("\nr : |%d|\n", retval);
        printf("color[0] : |%f|\n", color[0]);
        printf("color[1] : |%f|\n", color[1]);
        printf("color[2] : |%f|\n", color[2]);
    }

    str = "";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    //printf("color[0] : |%f|\n", color[0]);
    //printf("color[1] : |%f|\n", color[1]);
    //printf("color[2] : |%f|\n", color[2]);
    if (retval != 0)
    {
        printf("\nr : |%d|\n", retval);
        printf("color[0] : |%f|\n", color[0]);
        printf("color[1] : |%f|\n", color[1]);
        printf("color[2] : |%f|\n", color[2]);
    }

    str = "256,257,421";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    //printf("color[0] : |%f|\n", color[0]);
    //printf("color[1] : |%f|\n", color[1]);
    //printf("color[2] : |%f|\n", color[2]);
    if (retval != 0)
    {
        printf("\nr : |%d|\n", retval);
        printf("color[0] : |%f|\n", color[0]);
        printf("color[1] : |%f|\n", color[1]);
        printf("color[2] : |%f|\n", color[2]);
    }

    str = "0, 0,    0";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    //printf("color[0] : |%f|\n", color[0]);
    //printf("color[1] : |%f|\n", color[1]);
    //printf("color[2] : |%f|\n", color[2]);
    if (retval != 0)
    {
        printf("\nr : |%d|\n", retval);
        printf("color[0] : |%f|\n", color[0]);
        printf("color[1] : |%f|\n", color[1]);
        printf("color[2] : |%f|\n", color[2]);
    }

    str = "1,1,";
    i = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    retval = rgb_to_int(str, &i, color);
    //printf("color[0] : |%f|\n", color[0]);
    //printf("color[1] : |%f|\n", color[1]);
    //printf("color[2] : |%f|\n", color[2]);
    if (retval != 0)
    {
        printf("\nr : |%d|\n", retval);
        printf("color[0] : |%f|\n", color[0]);
        printf("color[1] : |%f|\n", color[1]);
        printf("color[2] : |%f|\n", color[2]);
    }

    printf("\n(only error message should appear)\n\n");
}