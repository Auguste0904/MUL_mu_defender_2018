/*
** EPITECH PROJECT, 2019
** change_set_text.c
** File description:
** Change the texts of the settings menu
*/

#include "my.h"

void change_fullscreen_one(game_t *game)
{
    sfRenderWindow_destroy(game->window->wind);
    game->window->wind = sfRenderWindow_create((sfVideoMode)
    {1920 * game->ratio, 1080 * game->ratio, 32}, "My_defender",
    sfFullscreen | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window->wind, 60);
    sfMusic_play(game->button_click);
}

void change_fullscreen_two(game_t *game)
{
    sfRenderWindow_destroy(game->window->wind);
    game->window->wind = sfRenderWindow_create((sfVideoMode)
    {1920 * game->ratio, 1080 * game->ratio, 32}, "My_defender",
    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window->wind, 60);
    sfMusic_play(game->button_click);
}

void change_fullscreen(game_t *game, sfVector2f full_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->main_menu->x >= full_pos.x && game->window->click_pressed == 0 &&
    game->main_menu->x <= full_pos.x + 50 * game->ratio &&
    game->main_menu->y >= full_pos.y &&
    game->main_menu->y <= full_pos.y + 50 * game->ratio) {
        game->set_menu->fullscreen = !game->set_menu->fullscreen;
        if (game->set_menu->fullscreen) {
            change_fullscreen_one(game);
        } else {
            change_fullscreen_two(game);
        }
        game->window->click_pressed = 1;
    }
}
