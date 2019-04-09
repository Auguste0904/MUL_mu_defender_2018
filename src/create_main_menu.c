/*
** EPITECH PROJECT, 2019
** create_main_menu
** File description:
** All create of my_defender's main menu
*/

#include "my.h"

void create_texture2(game_t *game)
{
    game->main_menu->zombie =
    sfTexture_createFromFile("assets/img/zombie_balloon.png", NULL);
    game->main_menu->balloon =
    sfTexture_createFromFile("assets/img/balloon.png", NULL);
    game->main_menu->play =
    sfTexture_createFromFile("assets/img/main_menu/play.png", NULL);
    game->main_menu->play_2 =
    sfTexture_createFromFile("assets/img/main_menu/play_clicked.png", NULL);
    game->main_menu->bubble =
    sfTexture_createFromFile("assets/img/main_menu/bubble.png", NULL);
}

void create_texture(game_t *game)
{
    game->main_menu->back =
    sfTexture_createFromFile("assets/img/main_menu/menu.png", NULL);
    game->main_menu->logo =
    sfTexture_createFromFile("assets/img/main_menu/logo.png", NULL);
    game->main_menu->tombstone =
    sfTexture_createFromFile("assets/img/main_menu/menu_tombstone.png", NULL);
    game->main_menu->tree =
    sfTexture_createFromFile("assets/img/main_menu/menu_tree.png", NULL);
    game->main_menu->house =
    sfTexture_createFromFile("assets/img/main_menu/menu_bg.png", NULL);
    game->main_menu->grass =
    sfTexture_createFromFile("assets/img/main_menu/grass.png", NULL);
    game->main_menu->snail =
    sfTexture_createFromFile("assets/img/main_menu/snailspriteshet.png", NULL);
    create_texture2(game);
}

void set_textures_two(game_t *game)
{
    sfSprite_setTexture(game->main_menu->zombie_s,
    game->main_menu->zombie, sfTrue);
    sfSprite_setTexture(game->main_menu->balloon_s,
    game->main_menu->balloon, sfTrue);
    sfSprite_setTexture(game->main_menu->bubble_s,
    game->main_menu->bubble, sfTrue);
    sfSprite_setOrigin(game->main_menu->bubble_s,
    (sfVector2f){215 * game->ratio, 425 * game->ratio});
    sfSprite_setTexture(game->main_menu->play_s,
    game->main_menu->play, sfTrue);
    sfSprite_setTexture(game->main_menu->play_2_s,
    game->main_menu->play_2, sfTrue);

}

void set_textures(game_t *game)
{
    sfSprite_setTexture(game->main_menu->back_s,
    game->main_menu->back, sfTrue);
    sfSprite_setTexture(game->main_menu->logo_s,
    game->main_menu->logo, sfTrue);
    sfSprite_setTexture(game->main_menu->tombstone_s,
    game->main_menu->tombstone, sfTrue);
    sfSprite_setTexture(game->main_menu->tree_s,
    game->main_menu->tree, sfTrue);
    sfSprite_setTexture(game->main_menu->house_s,
    game->main_menu->house, sfTrue);
    sfSprite_setTexture(game->main_menu->grass_s,
    game->main_menu->grass, sfTrue);
    sfSprite_setTexture(game->main_menu->snail_s,
    game->main_menu->snail, sfTrue);
    set_textures_two(game);
}

void create_main_menu(game_t *game)
{
    create_sprite(game);
    create_texture(game);
    create_text(game);
    change_sprite(game);
    set_textures(game);
    game->main_menu->snail_clock = sfClock_create();
    game->window->click_pressed = 0;
}
