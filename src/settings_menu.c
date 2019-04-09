/*
** EPITECH PROJECT, 2019
** settings_menu
** File description:
** Settings menu of My_defender
*/

#include "my.h"

void close_set_wind(game_t *game, int *close)
{
    while (sfRenderWindow_pollEvent(game->window->wind,
    &game->window->event)) {
        if (game->window->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window->wind);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
    game->window->escape_pressed == 0) {
        close[0] = 1;
        game->window->escape_pressed = 1;
    }
}

int set_menu(game_t *game)
{
    int close = 0;

    while (sfRenderWindow_isOpen(game->window->wind)) {
        close_set_wind(game, &close);
        sfText_setColor(game->main_menu->settings, sfBlack);
        sfText_setColor(game->main_menu->quit, sfBlack);
        manage_snail(game);
        draw_set_menu(game);
        change_text_set_menu(game);
        click_text_set_menu(game);
        if (game->set_menu->fullscreen)
            sfRenderWindow_drawSprite(game->window->wind,
            game->set_menu->valide_but_s, NULL);
        sfRenderWindow_display(game->window->wind);
        sfRenderWindow_clear(game->window->wind, sfBlack);
        if (close)
            break;
    }
    return (0);
}
