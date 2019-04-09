/*
** EPITECH PROJECT, 2019
** linked_list_green_plant
** File description:
** Creation of the liked list of the green plant
*/

#include "my.h"

struct pea *create_pea(sfVector2f pos, int damage)
{
    pea_t *tmp = NULL;

    tmp = malloc(sizeof(struct pea));
    tmp->damage = damage;
    tmp->pos = pos;
    tmp->next = (struct pea *)NULL;
    return (tmp);
}
