/*
** EPITECH PROJECT, 2019
** main_menu
** File description:
** My_defender's main menu
*/

#include "my.h"

void close_wind(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->wind,
    &game->window->event)) {
        if (game->window->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window->wind);
        if (game->window->event.type == sfEvtKeyReleased &&
            game->window->event.key.code == sfKeyEscape)
            game->window->escape_pressed = 0;
    }
}

void fade_fct(game_t *game)
{
    static int alpha = 254;

    if (sfClock_getElapsedTime(game->main_menu->fade_clock)
    .microseconds > 10000) {
        if (alpha > 0) {
            alpha -= 2;
            sfRectangleShape_setFillColor(game->main_menu->fade,
            sfColor_fromRGBA(0, 0, 0, alpha));
        }
        sfClock_restart(game->main_menu->fade_clock);
    }
    sfRenderWindow_drawRectangleShape(game->window->wind,
    game->main_menu->fade, NULL);
}

int main_menu(game_t *game)
{
    create_main_menu(game);
    create_dave(game);
    while (sfRenderWindow_isOpen(game->window->wind)) {
        rand();
        close_wind(game);
        manage_snail(game);
        manage_zombie(game);
        draw_main_menu(game);
        change_button_main_menu(game);
        click_button_menu(game);
        change_text_main_menu(game);
        click_text_menu(game);
        dave_appears(game, 0);
        fade_fct(game);
        sfRenderWindow_display(game->window->wind);
        sfRenderWindow_clear(game->window->wind, sfBlack);
    }
    return (0);
}
