/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void intro_anim_clock(game_t *game, int *pause)
{
    if (pause[0] == 1 && sfClock_getElapsedTime(game->game_loop->anim)
    .microseconds > 1800000) {
        pause[0] = 0;
    }
}

void intro_draw(game_t *game, int zombpo[4])
{
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->back_s, NULL);
    sfSprite_setPosition(game->game_loop->zombie_s,
    (sfVector2f){zombpo[0], zombpo[1]});
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->zombie_s, NULL);
    sfSprite_setPosition(game->game_loop->zombie_s,
    (sfVector2f){zombpo[2], zombpo[3]});
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->zombie_s, NULL);
    sfRenderWindow_display(game->window->wind);
    sfRenderWindow_clear(game->window->wind, sfBlack);
}

void intro_deccelerate(game_t *game, int *pause, float *speed, float *zoom)
{
    if (pause[0] == -1 && sfClock_getElapsedTime(game->game_loop->anim)
    .microseconds > 10000) {
        speed[0] -= 0.1 * (1 / game->ratio);
        zoom[0] += 0.00003 * (1 / (game->ratio * game->ratio));
        sfSprite_move(game->game_loop->hud_s,
        (sfVector2f){-speed[0], speed[0] / 15});
        sfView_move(game->game_loop->view,
        (sfVector2f){-speed[0], speed[0] / 15});
        sfView_zoom(game->game_loop->view, zoom[0]);
        sfRenderWindow_setView(game->window->wind, game->game_loop->view);
        if (speed[0] <= 0)
            pause[0] = 42;
    }
}

void intro_accelerate(game_t *game, int *pause, float *speed, float *zoom)
{
    if (pause[0] == 0 && sfClock_getElapsedTime(game->game_loop->anim)
    .microseconds > 10000) {
        speed[0] += 0.1 * (1 / game->ratio);
        zoom[0] -= 0.00003 * (1 / (game->ratio * game->ratio));
        sfSprite_move(game->game_loop->hud_s,
        (sfVector2f){-speed[0], speed[0] / 15});
        sfView_move(game->game_loop->view,
        (sfVector2f){-speed[0], speed[0] / 15});
        sfView_zoom(game->game_loop->view, zoom[0]);
        sfRenderWindow_setView(game->window->wind, game->game_loop->view);
        if (speed[0] >= 7)
            pause[0] = -1;
    }
}
