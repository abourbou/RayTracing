#include "../../../includes/parsing.h"

int main(void)
{
    float res;
    char *str;
    // cut at 23(21) 2147.0010200000003 so .13

    //          Tests with float values
    printf("\nTests with float values\n\n");

    str = "2147.0010200000003";
    res = 0.0;
    printf("string :           %s\n", str);
    printf("retval [%d] ~ res = %.15lf\n", ft_atod(str, &res), res);

    res = 0.0;
    str = "2147.001020000002";
    printf("string :           %s\n", str);
    printf("retval [%d] ~ res = %.15lf\n", ft_atod(str, &res), res);

    res = 0.0;
    str = "1.414213562370";
    printf("string :           %s\n", str);
    printf("retval [%d] ~ res = %.15lf\n", ft_atod(str, &res), res);

    res = 0.0;
    str = "0.0000000021";
    printf("string :           %s\n", str);
    printf("retval [%d] ~ res = %.15lf\n", ft_atod(str, &res), res);

    res = 0.0;
    str = "-0.0000000021";
    printf("string :           %s\n", str);
    printf("retval [%d] ~ res = %.15lf\n", ft_atod(str, &res), res);

    res = 0.0;
    str = "-000555.214";
    printf("string :           %s\n", str);
    printf("retval [%d] ~ res = %lf\n", ft_atod(str, &res), res);

    res = 0.0;
    str = "-0.0000000021";
    printf("string :           %s\n", str);
    printf("retval [%d] ~ res = %.15lf\n", ft_atod(str, &res), res);

    res = 0.0;


    //          Tests with int and errors
    printf("\nTests with int and errors\n");
    str = "12";
    printf("\nstring : %s\n", str);
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = "-12";
    printf("string : %s\n", str);
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = "13.";
    printf("string : %s\n", str);
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = "12.12";
    printf("string : %s\n", str);
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = "12.1";
    printf("string : %s\n", str);
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = "12.00";
    printf("string : %s\n", str);
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;


    //         Tests with zeros, potatoes, NULL, and \0
    printf("\nTests with zeros, potatoes, NULL, and \\0\n\n");

    str = "0";
    printf("string : |%s| (%s)\n", str, "\"0\"");
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = "patate.12";
    printf("string : %s\n", str);
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = "";
    printf("string : |%s| (%s)\n", str, "\"\"");
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;

    str = 0;
    printf("string : |%s| (%s)\n", str, "0");
    printf("%d : %f\n", ft_atod(str, &res), res);
    res = 0.0;
}