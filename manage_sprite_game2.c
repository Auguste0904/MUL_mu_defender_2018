/*
** EPITECH PROJECT, 2019
** manage
** File description:
** manage spritte
*/

#include "my.h"

void manage_game_sun(game_t *game)
{
    sun_t *sun = game->sun;
    sun_t *sun_backup = NULL;
    int move = (sfClock_getElapsedTime(game->game_loop->sun_move)
    .microseconds > 30000) ? 1 : 0;

    if (move) {
        while (sun != NULL) {
            sun_backup = sun->next;
            if (sun->pos.y < sun->floor || sun->speed.y < 0) {
                if (sun->speed.y < 4)
                    sun->speed.y += 0.2;
                if (sun->speed.x > 0)
                    sun->speed.x -= 0.1;
                else if (sun->speed.x < 0)
                    sun->speed.x += 0.1;
                sun->pos.y += sun->speed.y;
                sun->pos.x += sun->speed.x;
            }
            if (sfClock_getElapsedTime(sun->ghost).microseconds > 30000000)
                sun->alpha = (sun->alpha <= 1) ? 0 : sun->alpha - 2;
            if (sun->alpha == 0)
                destroy_sun(game, sun);
            sun = sun_backup;
        }
        sfClock_restart(game->game_loop->sun_move);
    }
    sun = game->sun;
    if (sfClock_getElapsedTime(game->game_loop->game_sun)
    .microseconds > 12000000) {
        if (game->sun == NULL)
            game->sun = create_sun((sfVector2f)
            {rand() % 1001 + 500, rand() % 501 - 600},
            (sfVector2f){0, 4}, rand() % 501 + 250);
        else {
            while (sun->next)
                sun = sun->next;
            sun->next = create_sun((sfVector2f)
            {rand() % 1001 + 500, rand() % 501 - 600},
            (sfVector2f){0, 4}, rand() % 501 + 250);
        }
        sfClock_restart(game->game_loop->game_sun);
    }
}

void manage_game_sunflower(game_t *game)
{
    sunflower_t *sunflower = game->sunflower;
    sun_t *sun = game->sun;

    while (sunflower != NULL) {
        move_rect_sunflower(sunflower);
        if (sfClock_getElapsedTime(sunflower->sun).microseconds > 15000000) {
            if (game->sun == NULL)
                game->sun = create_sun((sfVector2f)
                {sunflower->pos.x - 30, sunflower->pos.y - 30},
                (sfVector2f){(rand() % 121) / 10 - 6, -4},
                sunflower->pos.y + rand() % 91 - 60);
            else {
                while (sun->next)
                    sun = sun->next;
                sun->next = create_sun((sfVector2f)
                {sunflower->pos.x - 30, sunflower->pos.y - 30},
                (sfVector2f){(rand() % 121) / 10 - 6, -4},
                sunflower->pos.y + rand() % 91 - 60);
            }
            sfClock_restart(sunflower->sun);
        }
        sunflower = sunflower->next;
    }
}

void manage_game_wallnut(game_t *game)
{
    wallnut_t *wallnut = game->wallnut;

    while (wallnut != NULL) {
        move_rect_wallnut(wallnut);
        wallnut = wallnut->next;
    }
}

void manage_zombie_wave(game_t *game)
{
    zombie_t *zombie = game->zombie;

    if (sfClock_getElapsedTime(game->zombie_clock).microseconds >
    game->zombie_clock_limit) {
        game->zombie_wave = game->zombie_wave * 1.2 + rand() % 3;
        if (game->zombie == NULL)
            game->zombie = create_zombie(game);
        zombie = game->zombie;
        while (zombie->next)
            zombie = zombie->next;
        for (int i = 0; i < game->zombie_wave; i++) {
            zombie->next = create_zombie(game);
            zombie = zombie->next;
        }
        sfClock_restart(game->zombie_clock);
        game->zombie_clock_limit =
        game->zombie_clock_limit * 1.2 + rand() % 5000;
    }
}

void manage_game_cactus(game_t *game)
{
    cactus_t *cactus = game->cactus;
    pick_t *pick = game->pick;
    zombie_t *zombie = game->zombie;
    int shot = 0;

    while (cactus != NULL) {
        move_rect_cactus(cactus);
        shot = 0;
        zombie = game->zombie;
        while (zombie != NULL) {
            if (cactus->pos.x < zombie->pos.x && zombie->pos.x < 1750 &&
            cactus->pos.y > zombie->pos.y &&
            cactus->pos.y < zombie->pos.y + 150)
                shot = 1;
            zombie = zombie->next;
        }
        if (sfClock_getElapsedTime(cactus->attack).microseconds >
        1400000 && shot) {
            pick = game->pick;
            if (game->pick == NULL) {
                game->pick = create_pick((sfVector2f){cactus->pos.x + 15,
                cactus->pos.y - 38}, 25);
            } else {
                while (pick->next != NULL)
                    pick = pick->next;
                pick->next = create_pick((sfVector2f){cactus->pos.x + 15,
                cactus->pos.y - 38}, 25);
            }
            sfClock_restart(cactus->attack);
        }
        cactus = cactus->next;
    }
}