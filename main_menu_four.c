/*
** EPITECH PROJECT, 2019
** main_menu_four
** File description:
** main menu
*/

#include "my.h"

void dave_appears3(game_t *game, float *dave_speed)
{
    if (dave_speed[0] <= 14.8 * (1 / game->ratio)) {
        sfSprite_move(game->main_menu->dave_s,
        (sfVector2f){-dave_speed[0] * game->ratio, 0});
        sfText_move(game->main_menu->dave_text,
        (sfVector2f){-dave_speed[0] * game->ratio, 0});
        sfSprite_setPosition(game->main_menu->bubble_s, (sfVector2f)
        {sfSprite_getPosition(game->main_menu->dave_s).x
            + 170 * game->ratio,
            sfSprite_getPosition(game->main_menu->dave_s).y
            + 90 * game->ratio});
        sfText_setPosition(game->main_menu->dave_text, (sfVector2f)
        {sfSprite_getPosition(game->main_menu->dave_s).x
            + 85 * game->ratio,
            sfSprite_getPosition(game->main_menu->dave_s).y
            - 200 * game->ratio});
        dave_speed[0] += 0.185 * (1 / game->ratio);
    }
}

void dave_appears2(game_t *game, float *dave_speed)
{
    if (dave_speed[0] > 0) {
        sfSprite_move(game->main_menu->dave_s,
        (sfVector2f){dave_speed[0], 0});
        sfSprite_setPosition(game->main_menu->bubble_s, (sfVector2f)
        {sfSprite_getPosition(game->main_menu->dave_s).x
            + 170 * game->ratio,
            sfSprite_getPosition(game->main_menu->dave_s).y
            + 90 * game->ratio});
        sfText_setPosition(game->main_menu->dave_text, (sfVector2f)
        {sfSprite_getPosition(game->main_menu->dave_s).x
            + 85 * game->ratio,
            sfSprite_getPosition(game->main_menu->dave_s).y
            - 200 * game->ratio});
        dave_speed[0] -= 0.19 * (1 / game->ratio);
    }
}

void dave_appears1(game_t *game, float *dave_speed)
{
    if (sfClock_getElapsedTime(game->main_menu->dave_clock)
    .microseconds > 8000) {
        if (game->main_menu->display_dave) {
            dave_appears2(game, dave_speed);
        } else {
            dave_appears3(game, dave_speed);
        }
        sfClock_restart(game->main_menu->dave_clock);
    }
}

void dave_appears(game_t *game, int initialize)
{
    static float dave_speed = 14.8;

    if (initialize)
        dave_speed = 14.8 * game->ratio;
    else {
        dave_appears1(game, &dave_speed);
    }
}
