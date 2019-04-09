/*
** EPITECH PROJECT, 2019
** all_destroy
** File description:
** All destroy of the game
*/

#include "my.h"

void all_destroy_2(game_t *game)
{
    sfSprite_destroy(game->main_menu->balloon_s);
    sfTexture_destroy(game->main_menu->balloon);
    sfSprite_destroy(game->main_menu->zombie_s);
    sfTexture_destroy(game->main_menu->zombie);
    sfSprite_destroy(game->main_menu->play_s);
    sfTexture_destroy(game->main_menu->play);
    sfText_destroy(game->main_menu->settings);
    sfText_destroy(game->main_menu->quit);
    sfMusic_destroy(game->main_menu->boom);
    sfMusic_destroy(game->main_menu->music);
    sfMusic_destroy(game->main_menu->dave_sound);
    sfMusic_destroy(game->button_click);
    sfRenderWindow_destroy(game->window->wind);
}

void all_destroy(game_t *game)
{
    sfSprite_destroy(game->main_menu->back_s);
    sfTexture_destroy(game->main_menu->back);
    sfSprite_destroy(game->main_menu->logo_s);
    sfTexture_destroy(game->main_menu->logo);
    sfSprite_destroy(game->main_menu->house_s);
    sfTexture_destroy(game->main_menu->house);
    sfSprite_destroy(game->main_menu->tombstone_s);
    sfTexture_destroy(game->main_menu->tombstone);
    sfSprite_destroy(game->main_menu->tree_s);
    sfTexture_destroy(game->main_menu->tree);
    sfSprite_destroy(game->main_menu->grass_s);
    sfTexture_destroy(game->main_menu->grass);
    sfSprite_destroy(game->main_menu->snail_s);
    sfTexture_destroy(game->main_menu->snail);
    all_destroy_2(game);
}
