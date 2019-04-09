/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

void manage_snail_rect(game_t *game, int *dir, sfIntRect *rect)
{
    if (!dir[0] &&
    sfSprite_getPosition(game->main_menu->snail_s).x < 1000 * game->ratio) {
        if (rect[0].left <= 504)
            rect[0].left += 84;
        else
            dir[0] = 1;
    }
    if (dir[0] &&
    sfSprite_getPosition(game->main_menu->snail_s).x > 1400 * game->ratio) {
        if (rect[0].left >= 1)
            rect[0].left -= 84;
        else
            dir[0] = 0;
    }
}

void manage_snail(game_t *game)
{
    static int dir = -42;
    static sfIntRect rect = (sfIntRect){0, 0, 84, 59};
    static int up = 0;

    sfSprite_move(game->main_menu->snail_s, (sfVector2f){0, sin(up / 50) / 3});
    up += 1;
    if (!dir &&
        sfSprite_getPosition(game->main_menu->snail_s).x >= 1000 * game->ratio)
        sfSprite_move(game->main_menu->snail_s, (sfVector2f){-1, 0});
    if (dir &&
        sfSprite_getPosition(game->main_menu->snail_s).x <= 1400 * game->ratio)
        sfSprite_move(game->main_menu->snail_s, (sfVector2f){1, 0});
    if (sfClock_getElapsedTime(game->main_menu->snail_clock)
    .microseconds > 80000) {
        manage_snail_rect(game, &dir, &rect);
        sfClock_restart(game->main_menu->snail_clock);
    }
    sfSprite_setTextureRect(game->main_menu->snail_s, rect);
}