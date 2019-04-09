/*
** EPITECH PROJECT, 2019
** linked_list_green_plant
** File description:
** Creation of the liked list of the green plant
*/

#include "my.h"

void move_rect_cactus(cactus_t *cactus)
{
    if (sfClock_getElapsedTime(cactus->anim).microseconds > 200000) {
        cactus->sheet.left += 100;
        if (cactus->sheet.left >= 200)
            cactus->sheet.left = 0;
        sfClock_restart(cactus->anim);
    }
}

struct cactus *create_cactus(sfVector2f pos)
{
    cactus_t *tmp = NULL;

    tmp = malloc(sizeof(struct cactus));
    tmp->health = 100;
    tmp->pos = create_pos(pos);
    tmp->sheet = (sfIntRect){0, 0, 100, 120};
    tmp->anim = sfClock_create();
    tmp->attack = sfClock_create();
    tmp->next = (struct cactus *)NULL;
    return (tmp);
}
