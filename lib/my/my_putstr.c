/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Afficher une chaîne de caractère
*/

#include "my.h"

int my_putstr(char const *str)
{
    int a = 0;

    if (str == NULL)
        my_putstr("(null)");
    else {
        for (; str[a] != '\0'; a++) {
            my_putchar(str[a]);
        }
    }
    return (0);
}
