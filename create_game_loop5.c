/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

void create_outro(game_t *game)
{
    game->game_loop->zombiewon_s = sfSprite_create();
    game->game_loop->zombiewon =
    sfTexture_createFromFile("assets/img/game/zombiewon.png", NULL);
    sfSprite_setTexture(game->game_loop->zombiewon_s,
    game->game_loop->zombiewon, sfTrue);
    sfSprite_setOrigin(game->game_loop->zombiewon_s,
    (sfVector2f){282, 0});
    sfSprite_setPosition(game->game_loop->zombiewon_s,
    (sfVector2f){960, 300});
    sfSprite_setColor(game->game_loop->zombiewon_s,
    sfColor_fromRGBA(255, 255, 255, 0));
    game->game_loop->black_fade =
    sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->game_loop->black_fade,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setSize(game->game_loop->black_fade,
    (sfVector2f){1920, 1080});
}
