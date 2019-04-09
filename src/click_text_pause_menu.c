/*
** EPITECH PROJECT, 2019
** click_text_pause_menu
** File description:
** Click on the text in the pause menu
*/

#include "my.h"

void change_text_pause_menu1(game_t *game, sfVector2f resume_pos,
sfVector2f menu_pos)
{
    if (game->game_loop->x >= resume_pos.x &&
        game->game_loop->x <= resume_pos.x + 512 * game->ratio &&
        game->game_loop->y >= resume_pos.y &&
        game->game_loop->y <= resume_pos.y + 73 * game->ratio)
        sfText_setColor(game->game_loop->resume, sfGreen);
    else
        sfText_setColor(game->game_loop->resume, sfBlack);
    if (game->game_loop->x >= menu_pos.x &&
        game->game_loop->x <= menu_pos.x + 512 * game->ratio &&
        game->game_loop->y >= menu_pos.y &&
        game->game_loop->y <= menu_pos.y + 73 * game->ratio)
        sfText_setColor(game->game_loop->menu, sfGreen);
    else
        sfText_setColor(game->game_loop->menu, sfBlack);
}

void change_text_pause_menu(game_t *game)
{
    sfVector2f resume_pos = (sfVector2f){685 * game->ratio, 675 * game->ratio};
    sfVector2f menu_pos = (sfVector2f){685 * game->ratio, 760 * game->ratio};
    sfVector2f quit_pos = (sfVector2f){685 * game->ratio, 845 * game->ratio};

    game->game_loop->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->game_loop->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    change_text_pause_menu1(game, resume_pos, menu_pos);
    if (game->game_loop->x >= quit_pos.x &&
        game->game_loop->x <= quit_pos.x + 512 * game->ratio &&
        game->game_loop->y >= quit_pos.y &&
        game->game_loop->y <= quit_pos.y + 73 * game->ratio)
        sfText_setColor(game->game_loop->quit, sfGreen);
    else
        sfText_setColor(game->game_loop->quit, sfBlack);
}

void click_text_pause_menu1(game_t *game, sfVector2f resume_pos,
sfVector2f menu_pos, int *close)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->pause == 1 &&
    game->game_loop->x >= resume_pos.x &&
    game->game_loop->x <= resume_pos.x + 512 * game->ratio &&
    game->game_loop->y >= resume_pos.y &&
    game->game_loop->y <= resume_pos.y + 73 * game->ratio) {
        sfMusic_play(game->button_click);
        game->pause = 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->game_loop->x >= menu_pos.x &&
    game->game_loop->x <= menu_pos.x + 512 * game->ratio &&
    game->game_loop->y >= menu_pos.y &&
    game->game_loop->y <= menu_pos.y + 73 * game->ratio) {
        close[0] = 42;
        sfMusic_stop(game->game_loop->music);
        sfMusic_play(game->main_menu->music);
        sfMusic_play(game->button_click);
    }
}

void click_text_pause_menu(game_t *game, int *close)
{
    sfVector2f resume_pos = (sfVector2f){685 * game->ratio, 675 * game->ratio};
    sfVector2f menu_pos = (sfVector2f){685 * game->ratio, 760 * game->ratio};
    sfVector2f quit_pos = (sfVector2f){685 * game->ratio, 845 * game->ratio};

    game->game_loop->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->game_loop->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    click_text_pause_menu1(game, resume_pos, menu_pos, close);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        game->game_loop->x >= quit_pos.x &&
        game->game_loop->x <= quit_pos.x + 512 * game->ratio &&
        game->game_loop->y >= quit_pos.y &&
        game->game_loop->y <= quit_pos.y + 73 * game->ratio)
        sfRenderWindow_close(game->window->wind);
}
