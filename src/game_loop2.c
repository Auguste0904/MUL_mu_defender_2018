/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void close_end(game_t *game, int *close)
{
    while (sfRenderWindow_pollEvent(game->window->wind,
    &game->window->event)) {
        if (game->window->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window->wind);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
        game->window->escape_pressed == 0) {
            game->window->escape_pressed = 1;
            close[0] = 42;
        }
        if (game->window->event.type == sfEvtKeyReleased &&
            game->window->event.key.code == sfKeyEscape)
            game->window->escape_pressed = 0;
    }
}

void event_close1(game_t *game, int *close)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->wind);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
    game->window->escape_pressed == 0 && game->game == 0) {
        game->window->escape_pressed = 1;
        close[0] = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
    game->window->escape_pressed == 0 && game->pause == 0) {
        game->window->escape_pressed = 1;
        game->pause = 1;
    }
}

void event_close(game_t *game, int *close)
{
    while (sfRenderWindow_pollEvent(game->window->wind,
    &game->window->event)) {
        event_close1(game, close);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
        game->window->escape_pressed == 0 && game->pause == 1) {
            game->window->escape_pressed = 1;
            game->pause = 0;
        }
        if (game->window->event.type == sfEvtKeyReleased &&
            game->window->event.key.code == sfKeyEscape)
            game->window->escape_pressed = 0;
    }
}

void game_intro3(game_t *game, int *pause, float *speed, float *zoom)
{
    intro_deccelerate(game, pause, speed, zoom);
    intro_accelerate(game, pause, speed, zoom);
    intro_anim_clock(game, pause);
}

void game_intro(game_t *game, int *close)
{
    int zombpo[4] = {rand() % 150 * game->ratio + 1250 * game->ratio,
        rand() % 500 * game->ratio + 200 * game->ratio,
        rand() % 150 * game->ratio + 1250 * game->ratio,
        rand() % 500 * game->ratio + 200 * game->ratio};
    int pause = 1;
    float speed = 0;
    float zoom = 1;

    while (sfRenderWindow_isOpen(game->window->wind) && !close[0]) {
        rand();
        event_close(game, close);
        game_intro3(game, &pause, &speed, &zoom);
        if (pause == 1 && sfClock_getElapsedTime(game->game_loop->anim)
        .microseconds > 1800000) {
            pause = 0;
        }
        intro_draw(game, zombpo);
        if (close[0] || pause == 42)
            break;
    }
}
