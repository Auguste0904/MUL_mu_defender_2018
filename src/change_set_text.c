/*
** EPITECH PROJECT, 2019
** change_set_text.c
** File description:
** Change the texts of the settings menu
*/

#include "my.h"

void change_text_two(game_t *game, sfVector2f win2_pos, sfVector2f win3_pos)
{
    if (game->main_menu->x >= win2_pos.x &&
        game->main_menu->x <= win2_pos.x + 228 * game->ratio &&
        game->main_menu->y >= win2_pos.y &&
        game->main_menu->y <= win2_pos.y + 30 * game->ratio)
        sfText_setColor(game->set_menu->window2, sfGreen);
    else
        sfText_setColor(game->set_menu->window2, sfBlack);
    if (game->main_menu->x >= win3_pos.x &&
        game->main_menu->x <= win3_pos.x + 228 * game->ratio &&
        game->main_menu->y >= win3_pos.y &&
        game->main_menu->y <= win3_pos.y + 30 * game->ratio)
        sfText_setColor(game->set_menu->window3, sfGreen);
    else
        sfText_setColor(game->set_menu->window3, sfBlack);
}

void change_text_one(game_t *game, sfVector2f back_pos, sfVector2f window1_pos)
{
    if (game->main_menu->x >= back_pos.x &&
        game->main_menu->x <= back_pos.x + 480 * game->ratio &&
        game->main_menu->y >= back_pos.y &&
        game->main_menu->y <= back_pos.y + 95 * game->ratio)
        sfText_setColor(game->set_menu->back, sfGreen);
    else
        sfText_setColor(game->set_menu->back, sfBlack);
    if (game->main_menu->x >= window1_pos.x &&
        game->main_menu->x <= window1_pos.x + 230 * game->ratio &&
        game->main_menu->y >= window1_pos.y &&
        game->main_menu->y <= window1_pos.y + 30 * game->ratio)
        sfText_setColor(game->set_menu->window1, sfGreen);
    else
        sfText_setColor(game->set_menu->window1, sfBlack);
}

void change_text_set_menu(game_t *game)
{
    sfVector2f back_pos = (sfVector2f){720 * game->ratio, 907 * game->ratio};
    sfVector2f window1_pos = (sfVector2f){850 * game->ratio, 697 * game->ratio};
    sfVector2f window2_pos = (sfVector2f){855 * game->ratio, 760 * game->ratio};
    sfVector2f window3_pos = (sfVector2f){855 * game->ratio, 823 * game->ratio};

    game->main_menu->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->main_menu->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    change_text_one(game, back_pos, window1_pos);
    change_text_two(game, window2_pos, window3_pos);
}
