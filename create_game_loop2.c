/*
** EPITECH PROJECT, 2019
** create_game_loop2
** File description:
** Create game loop for the game itself
*/

#include "my.h"

void create_intro_pos_scale(game_t *game)
{
    sfSprite_setPosition(game->game_loop->ready_s,
    (sfVector2f){200 * game->ratio, 500 * game->ratio});
    sfSprite_setPosition(game->game_loop->set_s,
    (sfVector2f){200 * game->ratio, 500 * game->ratio});
    sfSprite_setPosition(game->game_loop->play_s,
    (sfVector2f){200 * game->ratio, 500 * game->ratio});
    sfSprite_setScale(game->game_loop->ready_s,
    (sfVector2f){1.5 * game->ratio, 1.5 *game->ratio});
    sfSprite_setScale(game->game_loop->set_s,
    (sfVector2f){1.5 * game->ratio, 1.5 *game->ratio});
    sfSprite_setScale(game->game_loop->play_s,
    (sfVector2f){1.5 * game->ratio, 1.5 *game->ratio});
}

void create_intro(game_t *game)
{
    game->game_loop->ready_s = sfSprite_create();
    game->game_loop->set_s = sfSprite_create();
    game->game_loop->play_s = sfSprite_create();
    game->game_loop->ready =
    sfTexture_createFromFile("assets/img/game/ready.png", NULL);
    game->game_loop->set =
    sfTexture_createFromFile("assets/img/game/set.png", NULL);
    game->game_loop->play =
    sfTexture_createFromFile("assets/img/game/plant.png", NULL);
    sfSprite_setTexture(game->game_loop->ready_s,
    game->game_loop->ready, sfTrue);
    sfSprite_setTexture(game->game_loop->set_s,
    game->game_loop->set, sfTrue);
    sfSprite_setTexture(game->game_loop->play_s,
    game->game_loop->play, sfTrue);
    create_intro_pos_scale(game);
}
