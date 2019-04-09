/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void damage_plant3(game_t *game, wallnut_t *wallnut, zombie_t *zombie)
{
    wallnut_t *tmp1 = game->wallnut;

    if (sfClock_getElapsedTime(zombie->attack).microseconds > 500000) {
        wallnut->health -= zombie->damage;
        damage_plant13(game, wallnut, tmp1);
        sfMusic_play(game->game_loop->chomp);
        sfClock_restart(zombie->attack);
    }
}

void damage_plant(game_t *game, peashooter_t *peashooter, zombie_t *zombie)
{
    peashooter_t *tmp1 = game->peashooter;

    if (sfClock_getElapsedTime(zombie->attack).microseconds > 500000) {
        peashooter->health -= zombie->damage;
        damage_plant10(game, peashooter, tmp1);
        sfMusic_play(game->game_loop->chomp);
        sfClock_restart(zombie->attack);
    }
}

void damage_plant4(game_t *game, cactus_t *cactus, zombie_t *zombie)
{
    cactus_t *tmp1 = game->cactus;

    if (sfClock_getElapsedTime(zombie->attack).microseconds > 500000) {
        cactus->health -= zombie->damage;
        damage_plant14(game, cactus, tmp1);
        sfMusic_play(game->game_loop->chomp);
        sfClock_restart(zombie->attack);
    }
}

void check_pick_damage(game_t *game, zombie_t *zombie, pick_t *pick)
{
    if (pick->pos.x - 38 > zombie->pos.x &&
    pick->pos.x < zombie->pos.x + 100 &&
    pick->pos.y > zombie->pos.y &&
    pick->pos.y < zombie->pos.y + 100) {
        damage_zombie2(game, zombie, pick);
    }
}

void manage_pick_zombie(game_t *game, pick_t *pick)
{
    zombie_t *zombie = game->zombie;
    zombie_t *zombie_backup = NULL;

    if (pick->pos.x > 1920) {
        destroy_pick(game, pick);
    } else {
        pick->pos.x += 9 *game->ratio;
        zombie = game->zombie;
        while (zombie) {
            zombie_backup = zombie->next;
            check_pick_damage(game, zombie, pick);
            zombie = zombie_backup;
        }
    }
}
