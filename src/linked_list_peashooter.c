/*
** EPITECH PROJECT, 2019
** linked_list_green_plant
** File description:
** Creation of the liked list of the green plant
*/

#include "my.h"

void move_rect_peashooter(peashooter_t *peashooter)
{
    if (sfClock_getElapsedTime(peashooter->anim).microseconds > 200000) {
        peashooter->sheet.left += 100;
        if (peashooter->sheet.left >= 200)
            peashooter->sheet.left = 0;
        sfClock_restart(peashooter->anim);
    }
}

sfVector2f create_pos(sfVector2f pos)
{
    for (int i = 0; i <= 5; i++) {
        if (pos.y > i * 156 + 200 && pos.y <= (i + 1) * 156 + 200) {
            pos.y = i * 156 + 270;
            break;
        }
    }
    for (int i = 0; i <= 9; i++) {
        if (pos.x > i * 133 + 315 && pos.x <= (i + 1) * 133 + 315) {
            pos.x = i * 133 + 375;
            break;
        }
    }
    return (pos);
}

struct peashooter *create_peashooter(sfVector2f pos)
{
    peashooter_t *tmp = NULL;

    tmp = malloc(sizeof(struct peashooter));
    tmp->health = 100;
    tmp->pos = create_pos(pos);
    tmp->sheet = (sfIntRect){0, 0, 100, 120};
    tmp->anim = sfClock_create();
    tmp->attack = sfClock_create();
    tmp->next = (struct peashooter *)NULL;
    return (tmp);
}
