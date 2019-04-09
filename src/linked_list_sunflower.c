/*
** EPITECH PROJECT, 2019
** linked_list_green_plant
** File description:
** Creation of the liked list of the green plant
*/

#include "my.h"

void move_rect_sunflower(sunflower_t *sunflower)
{
    if (sfClock_getElapsedTime(sunflower->anim).microseconds > 200000) {
        sunflower->sheet.left += 100;
        if (sunflower->sheet.left >= 400)
            sunflower->sheet.left = 0;
        sfClock_restart(sunflower->anim);
    }
}

struct sunflower *create_sunflower(sfVector2f pos)
{
    sunflower_t *tmp = NULL;

    tmp = malloc(sizeof(struct sunflower));
    tmp->health = 100;
    tmp->pos = create_pos(pos);
    tmp->sheet = (sfIntRect){0, 0, 100, 100};
    tmp->anim = sfClock_create();
    tmp->sun = sfClock_create();
    tmp->next = NULL;
    return (tmp);
}
