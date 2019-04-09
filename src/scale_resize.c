/*
** EPITECH PROJECT, 2019
** scale_resize
** File description:
** All scale and resize for the settings menu
*/

#include "my.h"

void scale_sprite2(game_t *game)
{
    sfSprite_setScale(game->main_menu->snail_s,
    (sfVector2f){1.25 * game->ratio, 1.25 * game->ratio});
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
    sfRectangleShape_setSize(game->main_menu->fade,
    (sfVector2f){1920 * game->ratio, 1080 * game->ratio});
}

void scale_sprite(game_t *game)
{
    sfSprite_setScale(game->set_menu->tab_s,
    (sfVector2f){1.45 * game->ratio, 1.45 * game->ratio});
    sfSprite_setScale(game->set_menu->valide_but_s,
    (sfVector2f){1.32 * game->ratio, 1.32 * game->ratio});
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
    scale_sprite2(game);
}

void pos_sprite2(game_t *game)
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
}

void pos_sprite(game_t *game)
{
    pos_sprite2(game);
    sfSprite_setPosition(game->main_menu->zombie_s,
    (sfVector2f){-300 * game->ratio, 600 * game->ratio});
    sfSprite_setPosition(game->main_menu->balloon_s,
    (sfVector2f){-300 * game->ratio, 535 * game->ratio});
    sfSprite_setPosition(game->main_menu->play_s,
    (sfVector2f){1325 * game->ratio, 290 * game->ratio});
    sfSprite_setPosition(game->main_menu->play_2_s,
    (sfVector2f){1325 * game->ratio, 290 * game->ratio});
    sfSprite_setPosition(game->main_menu->dave_s,
    (sfVector2f){-500 * game->ratio, 520 * game->ratio});
    sfSprite_setPosition(game->main_menu->bubble_s, (sfVector2f)
    {sfSprite_getPosition(game->main_menu->dave_s).x + 170 * game->ratio,
    sfSprite_getPosition(game->main_menu->dave_s).y + 90 * game->ratio});
    sfSprite_setPosition(game->set_menu->tab_s,
    (sfVector2f){385 * game->ratio, 260 * game->ratio});
    sfSprite_setPosition(game->set_menu->valide_but_s,
    (sfVector2f){1073 * game->ratio, 615 * game->ratio});
}

void scale_resize(game_t *game)
{
    sfRenderWindow_destroy(game->window->wind);
    if (game->set_menu->fullscreen) {
        game->window->wind = sfRenderWindow_create((sfVideoMode)
        {1920 * game->ratio, 1080 * game->ratio, 32}, "My_defender",
        sfFullscreen | sfClose, NULL);
    } else {
        game->window->wind = sfRenderWindow_create((sfVideoMode)
        {1920 * game->ratio, 1080 * game->ratio, 32}, "My_defender",
        sfClose, NULL);
    }
    sfRenderWindow_setFramerateLimit(game->window->wind, 60);
    scale_text(game);
    scale_sprite(game);
    pos_sprite(game);
}
