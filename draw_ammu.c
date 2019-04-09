/*
** EPITECH PROJECT, 2019
** display_ammu
** File description:
** Display ammunations
*/

#include "my.h"

void display_pea(game_t *game)
{
    pea_t *pea = game->pea;

    while (pea != NULL) {
        sfSprite_setPosition(game->game_loop->pea_s, pea->pos);
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->pea_s, NULL);
        pea = pea->next;
    }
}

void display_pick(game_t *game)
{
    pick_t *pick = game->pick;

    while (pick != NULL) {
        sfSprite_setPosition(game->game_loop->pick_s, pick->pos);
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->pick_s, NULL);
        pick = pick->next;
    }
}

void display_sun(game_t *game)
{
    sun_t *sun = game->sun;

    while (sun != NULL) {
        sfSprite_setPosition(game->game_loop->sun_s, sun->pos);
        sfSprite_setColor(game->game_loop->sun_s,
        sfColor_fromRGBA(255, 255, 255, sun->alpha));
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->sun_s, NULL);
        sun = sun->next;
    }
}