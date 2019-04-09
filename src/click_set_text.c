/*
** EPITECH PROJECT, 2019
** change_set_text.c
** File description:
** Change the texts of the settings menu
*/

#include "my.h"

void change_backto_menu(game_t *game, sfVector2f back_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        game->main_menu->x >= back_pos.x &&
        game->main_menu->x <= back_pos.x + 480 * game->ratio &&
        game->main_menu->y >= back_pos.y &&
        game->main_menu->y <= back_pos.y + 95 * game->ratio)
        main_menu(game);
}

void reset_ratio(game_t *game, int which_one)
{
    if (which_one == 0) {
        game->window->click_pressed = 1;
        game->ratio = 1;
        sfMusic_play(game->button_click);
        scale_resize(game);
    } else {
        game->window->click_pressed = 1;
        game->ratio = 0.86666667;
        sfMusic_play(game->button_click);
        scale_resize(game);
    }
}

void click_size_one(game_t *game, sfVector2f window1_pos, sfVector2f win2_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->main_menu->x >= window1_pos.x &&
    game->main_menu->x <= window1_pos.x + 230 * game->ratio &&
    game->main_menu->y >= window1_pos.y &&
    game->main_menu->y <= window1_pos.y + 30 * game->ratio &&
    game->window->click_pressed == 0) {
        reset_ratio(game, 0);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->main_menu->x >= win2_pos.x &&
    game->main_menu->x <= win2_pos.x + 230 * game->ratio &&
    game->main_menu->y >= win2_pos.y &&
    game->main_menu->y <= win2_pos.y + 30 * game->ratio &&
    game->window->click_pressed == 0) {
        reset_ratio(game, 1);
    }
}

void click_size_two(game_t *game, sfVector2f window3_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->main_menu->x >= window3_pos.x &&
    game->main_menu->x <= window3_pos.x + 230 * game->ratio &&
    game->main_menu->y >= window3_pos.y &&
    game->main_menu->y <= window3_pos.y + 30 * game->ratio &&
    game->window->click_pressed == 0) {
        game->window->click_pressed = 1;
        game->ratio = 0.66666667;
        sfMusic_play(game->button_click);
        scale_resize(game);
    }
    if (game->window->event.type == sfEvtMouseButtonReleased &&
        game->window->event.mouseButton.button == sfMouseLeft &&
        game->window->click_pressed)
        game->window->click_pressed = 0;
}

void click_text_set_menu(game_t *game)
{
    sfVector2f back_pos = (sfVector2f){720 * game->ratio, 907 * game->ratio};
    sfVector2f full_pos = (sfVector2f){1073 * game->ratio, 615 * game->ratio};
    sfVector2f window1_pos = (sfVector2f){850 * game->ratio, 697 * game->ratio};
    sfVector2f window2_pos = (sfVector2f){855 * game->ratio, 760 * game->ratio};
    sfVector2f window3_pos = (sfVector2f){855 * game->ratio, 823 * game->ratio};

    game->main_menu->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->main_menu->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    change_backto_menu(game, back_pos);
    change_fullscreen(game, full_pos);
    click_size_one(game, window1_pos, window2_pos);
    click_size_two(game, window3_pos);
}
