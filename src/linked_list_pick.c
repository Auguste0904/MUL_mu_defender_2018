/*
** EPITECH PROJECT, 2019
** linked_list_green_plant
** File description:
** Creation of the liked list of the green plant
*/

#include "my.h"

struct pick *create_pick(sfVector2f pos, int damage)
{
    pick_t *tmp = NULL;

    tmp = malloc(sizeof(struct pick));
    tmp->damage = damage;
    tmp->pos = pos;
    tmp->next = (struct pick *)NULL;
    return (tmp);
}
