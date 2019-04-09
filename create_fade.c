/*
** EPITECH PROJECT, 2019
** create_fade
** File description:
** Create the fade of the game
*/

#include "my.h"

void create_fade(game_t *game)
{
    game->main_menu->fade = sfRectangleShape_create();
    game->main_menu->fade_clock = sfClock_create();
    sfRectangleShape_setSize(game->main_menu->fade,
    (sfVector2f){1920 * game->ratio, 1080 * game->ratio});
    sfRectangleShape_setFillColor(game->main_menu->fade,
    sfColor_fromRGBA(0, 0, 0, 255));
}