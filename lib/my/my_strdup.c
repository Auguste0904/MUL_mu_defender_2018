/*
** EPITECH PROJECT, 2018
** my strdup
** File description:
** duplicate string
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *resul = NULL;
    int a = 0;

    if (src == NULL)
        return (NULL);
    resul = my_malloc(sizeof(char) * (my_strlen(src) + 1), 1);
    while (src[a] != 0) {
        resul[a] = src[a];
        a += 1;
    }
    return (resul);
}
