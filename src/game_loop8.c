/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void damage_plant13(game_t *game, wallnut_t *wallnut, wallnut_t *tmp1)
{
    if (wallnut->health <= 0) {
        sfClock_destroy(wallnut->anim);
        if (wallnut == game->wallnut) {
            game->wallnut = game->wallnut->next;
        } else {
            check_plant13(wallnut, tmp1);
        }
    }
}

void damage_plant10(game_t *game, peashooter_t *wallnut, peashooter_t *tmp1)
{
    if (wallnut->health <= 0) {
        sfClock_destroy(wallnut->anim);
        sfClock_destroy(wallnut->attack);
        if (wallnut == game->peashooter) {
            game->peashooter = game->peashooter->next;
        } else {
            check_plant10(wallnut, tmp1);
        }
    }
}

void damage_plant14(game_t *game, cactus_t *wallnut, cactus_t *tmp1)
{
    if (wallnut->health <= 0) {
        sfClock_destroy(wallnut->anim);
        sfClock_destroy(wallnut->attack);
        if (wallnut == game->cactus) {
            game->cactus = game->cactus->next;
        } else {
            check_plant14(wallnut, tmp1);
        }
    }
}
