/*
** EPITECH PROJECT, 2019
** create_main_menu3
** File description:
** Creation of the main menu
*/

#include "my.h"

void change_sprite_three(game_t *game)
{
    sfSprite_setScale(game->main_menu->zombie_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->main_menu->balloon_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->main_menu->play_s,
    (sfVector2f){1.5 * game->ratio, 1.5 * game->ratio});
    sfSprite_setScale(game->main_menu->play_2_s,
    (sfVector2f){1.5 * game->ratio, 1.5 * game->ratio});
    sfSprite_setScale(game->main_menu->bubble_s,
    (sfVector2f){0.9 * game->ratio, 0.9 * game->ratio});
}

void change_sprite_two(game_t *game)
{
    sfSprite_setScale(game->main_menu->logo_s,
    (sfVector2f){0.4 * game->ratio, 0.4 * game->ratio});
    sfSprite_setScale(game->main_menu->tree_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->main_menu->back_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->main_menu->tombstone_s,
    (sfVector2f){1.5 * game->ratio, 1.5 * game->ratio});
    sfSprite_setScale(game->main_menu->house_s,
    (sfVector2f){1.6 * game->ratio, 1.6 * game->ratio});
    sfSprite_setScale(game->main_menu->grass_s,
    (sfVector2f){2 * game->ratio, 2 * game->ratio});
    sfSprite_setScale(game->main_menu->snail_s,
    (sfVector2f){1.25 * game->ratio, 1.25 * game->ratio});
    change_sprite_three(game);
    game->window->escape_pressed = 0;
}

void change_sprite(game_t *game)
{
    sfSprite_setPosition(game->main_menu->logo_s,
    (sfVector2f){690 * game->ratio, 20 * game->ratio});
    sfSprite_setPosition(game->main_menu->tombstone_s,
    (sfVector2f){825 * game->ratio, 240 * game->ratio});
    sfSprite_setPosition(game->main_menu->house_s,
    (sfVector2f){306 * game->ratio, 665 * game->ratio});
    sfSprite_setPosition(game->main_menu->grass_s,
    (sfVector2f){450 * game->ratio, 956 * game->ratio});
    sfSprite_setPosition(game->main_menu->snail_s,
    (sfVector2f){1400 * game->ratio, 960 * game->ratio});
    sfSprite_setPosition(game->main_menu->zombie_s,
    (sfVector2f){-300 * game->ratio, 600 * game->ratio});
    sfSprite_setPosition(game->main_menu->balloon_s,
    (sfVector2f){-300 * game->ratio, 535 * game->ratio});
    sfSprite_setPosition(game->main_menu->play_s,
    (sfVector2f){1325 * game->ratio, 290 * game->ratio});
    sfSprite_setPosition(game->main_menu->play_2_s,
    (sfVector2f){1325 * game->ratio, 290 * game->ratio});
    change_sprite_two(game);
}