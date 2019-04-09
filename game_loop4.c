/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void manage_zombie_cactus(game_t *game, zombie_t *zombie, int *can_move)
{
    cactus_t *cactus = game->cactus;
    cactus_t *cactus_backup = NULL;

    while (cactus) {
        cactus_backup = cactus->next;
        if (zombie->pos.x + 20 > cactus->pos.x &&
        zombie->pos.x + 20 < cactus->pos.x + 20 &&
        zombie->pos.y < cactus->pos.y &&
        cactus->pos.y < zombie->pos.y + 150) {
            damage_plant4(game, cactus, zombie);
            can_move[0] = 0;
        }
        cactus = cactus_backup;
    }
}

void manage_zombie_sunflower(game_t *game, zombie_t *zombie, int *can_move)
{
    sunflower_t *sunflower = game->sunflower;
    sunflower_t *sunflower_backup = NULL;

    while (sunflower) {
        sunflower_backup = sunflower->next;
        if (zombie->pos.x + 20 > sunflower->pos.x &&
        zombie->pos.x + 20 < sunflower->pos.x + 20 &&
        zombie->pos.y < sunflower->pos.y &&
        sunflower->pos.y < zombie->pos.y + 200) {
            damage_plant2(game, sunflower, zombie);
            can_move[0] = 0;
        }
        sunflower = sunflower_backup;
    }
}

void manage_zombie_wallnut(game_t *game, zombie_t *zombie, int *can_move)
{
    wallnut_t *wallnut = game->wallnut;
    wallnut_t *wallnut_backup = NULL;

    while (wallnut) {
        wallnut_backup = wallnut->next;
        if (zombie->pos.x + 20 > wallnut->pos.x &&
        zombie->pos.x + 20 < wallnut->pos.x + 20 &&
        zombie->pos.y < wallnut->pos.y &&
        wallnut->pos.y < zombie->pos.y + 200) {
            damage_plant3(game, wallnut, zombie);
            can_move[0] = 0;
        }
        wallnut = wallnut_backup;
    }
}

void manage_zombie_general(game_t *game, zombie_t *zombie, int *can_move)
{
    manage_zombie_peashooter(game, zombie, can_move);
    manage_zombie_cactus(game, zombie, can_move);
    manage_zombie_sunflower(game, zombie, can_move);
    manage_zombie_wallnut(game, zombie, can_move);
}

void manage_game_zombie(game_t *game)
{
    zombie_t *zombie = game->zombie;
    int move = (sfClock_getElapsedTime(game->game_loop->enemy_move).microseconds
    > 30000) ? 1 : 0;
    int can_move = 1;

    if (move == 1) {
        while (zombie) {
            can_move = 1;
            manage_zombie_general(game, zombie, &can_move);
            manage_move_zombie(game, can_move, zombie);
            zombie = zombie->next;
        }
        sfClock_restart(game->game_loop->enemy_move);
    }
}
