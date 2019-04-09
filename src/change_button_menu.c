/*
** EPITECH PROJECT, 2019
** change_button_menu
** File description:
** Change button's menu
*/

#include "my.h"

void change_button_main_menu(game_t *game)
{
    sfVector2f play_pos = {1325 * game->ratio, 290 * game->ratio};

    play_pos = sfSprite_getPosition(game->main_menu->play_s);
    game->main_menu->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->main_menu->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    if (game->main_menu->x >= play_pos.x &&
        game->main_menu->x <= play_pos.x + 500 * game->ratio &&
        game->main_menu->y >= play_pos.y &&
        game->main_menu->y <= play_pos.y + 210 * game->ratio)
        sfRenderWindow_drawSprite(game->window->wind,
        game->main_menu->play_2_s, NULL);
    else
        sfRenderWindow_drawSprite(game->window->wind,
        game->main_menu->play_s, NULL);
}

void click_button_menu(game_t *game)
{
    sfVector2f play_pos = {1325 * game->ratio, 290 * game->ratio};

    play_pos = sfSprite_getPosition(game->main_menu->play_s);
    game->main_menu->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->main_menu->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    if (game->window->event.type == sfEvtMouseButtonPressed &&
    game->window->event.mouseButton.button == sfMouseLeft &&
    game->main_menu->x >= play_pos.x &&
    game->main_menu->x <= play_pos.x + 500 * game->ratio &&
    game->main_menu->y >= play_pos.y &&
    game->main_menu->y <= play_pos.y + 210 * game->ratio) {
        sfMusic_stop(game->main_menu->music);
        game_loop(game);
    }
}
