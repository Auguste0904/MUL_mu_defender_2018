/*
** EPITECH PROJECT, 2019
** linked_list_green_plant
** File description:
** Creation of the liked list of the green plant
*/

#include "my.h"

void move_rect_wallnut(wallnut_t *wallnut)
{
    if ((sfClock_getElapsedTime(wallnut->anim).microseconds > 2400000 &&
    wallnut->sheet.left == 0) ||
    (sfClock_getElapsedTime(wallnut->anim).microseconds > 100000 &&
    wallnut->sheet.left != 0)) {
        wallnut->sheet.left += 100;
        sfClock_restart(wallnut->anim);
    }
    if (wallnut->sheet.left >= 400)
        wallnut->sheet.left = 0;
    if (wallnut->health <= 400 && wallnut->health > 200)
        wallnut->sheet.top = 100;
    else if (wallnut->health <= 200)
        wallnut->sheet.top = 200;
}

struct wallnut *create_wallnut(sfVector2f pos)
{
    wallnut_t *tmp = NULL;

    tmp = malloc(sizeof(struct wallnut));
    tmp->health = 600;
    tmp->pos = create_pos(pos);
    tmp->sheet = (sfIntRect){0, 0, 100, 100};
    tmp->anim = sfClock_create();
    tmp->next = NULL;
    return (tmp);
}
