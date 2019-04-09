/*
** EPITECH PROJECT, 2019
** change_text_menu
** File description:
** Change the text of the game
*/

#include "my.h"

void change_text_main_menu2(game_t *game)
{
    sfVector2f quit_pos = sfText_getPosition(game->main_menu->quit);

    if (game->main_menu->x >= quit_pos.x &&
        game->main_menu->x <= quit_pos.x + 65 * game->ratio &&
        game->main_menu->y >= quit_pos.y &&
        game->main_menu->y <= quit_pos.y + 45 * game->ratio)
        sfText_setColor(game->main_menu->quit, sfRed);
    else
        sfText_setColor(game->main_menu->quit, sfBlack);
}

void change_text_main_menu(game_t *game)
{
    sfVector2f settings_pos = sfText_getPosition(game->main_menu->settings);
    sfVector2f help_pos = sfText_getPosition(game->main_menu->help);

    game->main_menu->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->main_menu->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    if (game->main_menu->x >= settings_pos.x &&
        game->main_menu->x <= settings_pos.x + 102 * game->ratio &&
        game->main_menu->y >= settings_pos.y &&
        game->main_menu->y <= settings_pos.y + 35 * game->ratio)
        sfText_setColor(game->main_menu->settings, sfRed);
    else
        sfText_setColor(game->main_menu->settings, sfBlack);
    if (game->main_menu->x >= help_pos.x &&
        game->main_menu->x <= help_pos.x + 65 * game->ratio &&
        game->main_menu->y >= help_pos.y &&
        game->main_menu->y <= help_pos.y + 50 * game->ratio)
        sfText_setColor(game->main_menu->help, sfRed);
    else
        sfText_setColor(game->main_menu->help, sfBlack);
    change_text_main_menu2(game);
}

void click_text_menu2(game_t *game)
{
    sfVector2f settings_pos = sfText_getPosition(game->main_menu->settings);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        game->main_menu->x >= settings_pos.x &&
        game->main_menu->x <= settings_pos.x + 102 * game->ratio &&
        game->main_menu->y >= settings_pos.y &&
        game->main_menu->y <= settings_pos.y + 35 * game->ratio)
        set_menu(game);
}

void click_text_menu3(game_t *game)
{
    sfVector2f quit_pos = sfText_getPosition(game->main_menu->quit);

    if (sfMouse_isButtonPressed(sfMouseLeft) && !game->window->click_pressed &&
    game->main_menu->display_dave) {
        game->window->click_pressed = 1;
        game->main_menu->display_dave = 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        game->main_menu->x >= quit_pos.x &&
        game->main_menu->x <= quit_pos.x + 65 * game->ratio &&
        game->main_menu->y >= quit_pos.y &&
        game->main_menu->y <= quit_pos.y + 50 * game->ratio)
        sfRenderWindow_close(game->window->wind);
    if (game->window->event.type == sfEvtMouseButtonReleased &&
        game->window->event.mouseButton.button == sfMouseLeft &&
        game->window->click_pressed)
        game->window->click_pressed = 0;
}

void click_text_menu(game_t *game)
{
    sfVector2f help_pos = sfText_getPosition(game->main_menu->help);

    game->main_menu->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->main_menu->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    click_text_menu2(game);
    if (sfMouse_isButtonPressed(sfMouseLeft) && !game->window->click_pressed &&
    game->main_menu->x >= help_pos.x &&
    game->main_menu->x <= help_pos.x + 65 * game->ratio &&
    game->main_menu->y >= help_pos.y &&
    game->main_menu->y <= help_pos.y + 45 * game->ratio) {
        game->window->click_pressed = 1;
        game->main_menu->display_dave = 1;
        sfMusic_play(game->main_menu->dave_sound);
    }
    click_text_menu3(game);
}
