/*
** EPITECH PROJECT, 2019
** create_pause_menu
** File description:
** Creation of the pause menu for the game
*/

#include "my.h"

void create_text_pause(game_t *game)
{
    game->game_loop->resume = sfText_create();
    game->game_loop->menu = sfText_create();
    game->game_loop->quit = sfText_create();
    sfText_setFont(game->game_loop->resume, game->set_menu->set_font);
    sfText_setFont(game->game_loop->menu, game->set_menu->set_font);
    sfText_setFont(game->game_loop->quit, game->set_menu->set_font);
    sfText_setString(game->game_loop->resume, "Resume game");
    sfText_setString(game->game_loop->menu, "Back to menu");
    sfText_setString(game->game_loop->quit, "Quit");
    sfText_setCharacterSize(game->game_loop->resume, 40 * game->ratio);
    sfText_setCharacterSize(game->game_loop->menu, 40 * game->ratio);
    sfText_setCharacterSize(game->game_loop->quit, 40 * game->ratio);
    sfText_setPosition(game->game_loop->resume,
    (sfVector2f){845 * game->ratio, 682 * game->ratio});
    sfText_setPosition(game->game_loop->menu,
    (sfVector2f){840 * game->ratio, 765 * game->ratio});
    sfText_setPosition(game->game_loop->quit,
    (sfVector2f){910 * game->ratio, 850 * game->ratio});
}

void create_pause(game_t *game)
{
    game->game_loop->pause_s = sfSprite_create();
    game->game_loop->pause =
    sfTexture_createFromFile("assets/img/game/pause.png", NULL);
    sfSprite_setTexture(game->game_loop->pause_s,
    game->game_loop->pause, sfTrue);
    sfSprite_setPosition(game->game_loop->pause_s,
    (sfVector2f){600 * game->ratio, 250 * game->ratio});
    sfSprite_setScale(game->game_loop->pause_s,
    (sfVector2f){1.7 * game->ratio, 1.7 * game->ratio});
}