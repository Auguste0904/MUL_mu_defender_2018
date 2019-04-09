/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** print a string
*/

#include "my.h"

int my_intlen(int nb)
{
    int tempor = 0;

    if (!(nb))
        return (1);
    while (nb != 0) {
        tempor += 1;
        nb /= 10;
    }
    return (tempor);
}

char *my_zero(void)
{
    char *tmp = my_malloc(sizeof(char) * 2, 1);

    tmp[0] = '0';
    tmp[1] = '\0';
    return (tmp);
}

char *my_itoa(int nb)
{
    int i = 0;
    int neg = 0;
    char *str = NULL;

    if (!(nb))
        return (my_zero());
    if (nb < 0) {
        neg = 1;
        str = my_malloc(sizeof(char) * my_intlen(nb) + 2, 1);
        nb = -nb;
    } else
        str = my_malloc(sizeof(char) * my_intlen(nb) + 1, 1);
    while (nb != 0) {
        str[i] = nb % 10 + 48;
        i += 1;
        nb /= 10;
    }
    if (neg)
        str[i] = '-';
    return (my_revstr(str));
}
