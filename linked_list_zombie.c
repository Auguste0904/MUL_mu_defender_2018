/*
** EPITECH PROJECT, 2019
** linked_list_zombie
** File description:
** Creation of the linked list of zombies
*/

#include "my.h"

void move_rect_zombie(zombie_t *zombie)
{
    if (sfClock_getElapsedTime(zombie->anim).microseconds > 200000) {
        zombie->sheet.left += 150;
        zombie->sheet.top = 0;
        if (zombie->sheet.left >= 500)
            zombie->sheet.left = 0;
        sfClock_restart(zombie->anim);
    }
}

void eat_rect_zombie(zombie_t *zombie)
{
    if (sfClock_getElapsedTime(zombie->anim).microseconds > 200000) {
        zombie->sheet.left += 150;
        zombie->sheet.top = 200;
        if (zombie->sheet.left >= 500)
            zombie->sheet.left = 0;
        sfClock_restart(zombie->anim);
    }
}

struct zombie *create_zombie(game_t *game)
{
    zombie_t *tmp = malloc(sizeof(struct zombie));

    tmp->health = 100;
    tmp->damage = 10;
    tmp->pos = (sfVector2f){(1920 * game->ratio) + rand() % 1000,
    (rand() % 5) * 156 * game->ratio + 140 * game->ratio};
    tmp->sheet = (sfIntRect){rand() % 4 * 150, 0, 150, 200};
    tmp->anim = sfClock_create();
    tmp->attack = sfClock_create();
    tmp->next = (struct zombie *)NULL;
    return (tmp);
}
