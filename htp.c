/*
** EPITECH PROJECT, 2019
** htp
** File description:
** hrp
*/

#include "my.h"

void create_dave(game_t *game)
{
    game->main_menu->dave_clock = sfClock_create();
    game->main_menu->dave_s = sfSprite_create();
    game->main_menu->dave =
    sfTexture_createFromFile("assets/img/main_menu/dave.png", NULL);
    sfSprite_setTexture(game->main_menu->dave_s,
    game->main_menu->dave, sfTrue);
    sfSprite_setPosition(game->main_menu->dave_s,
    (sfVector2f){-500 * game->ratio, 520 * game->ratio});
    sfSprite_setScale(game->main_menu->dave_s,
    (sfVector2f){game->ratio * 1.25, game->ratio * 1.25});
    sfText_setPosition(game->main_menu->dave_text, (sfVector2f)
    {sfSprite_getPosition(game->main_menu->dave_s).x + 140,
        sfSprite_getPosition(game->main_menu->dave_s).y - 190});
    game->main_menu->display_dave = 0;
}
