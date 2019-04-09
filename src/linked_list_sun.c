/*
** EPITECH PROJECT, 2019
** linked_list_green_plant
** File description:
** Creation of the liked list of the green plant
*/

#include "my.h"

struct sun *create_sun(sfVector2f pos, sfVector2f speed, float floor)
{
    sun_t *tmp = NULL;

    tmp = malloc(sizeof(struct sun));
    tmp->pos = pos;
    tmp->speed = speed;
    tmp->floor = floor;
    tmp->ghost = sfClock_create();
    tmp->alpha = 255;
    tmp->next = NULL;
    return (tmp);
}
