/*
** EPITECH PROJECT, 2019
** create_main_menu2
** File description:
** Creation of the main menu
*/

#include "my.h"

void create_sprite(game_t *game)
{
    game->main_menu->back_s = sfSprite_create();
    game->main_menu->logo_s = sfSprite_create();
    game->main_menu->tombstone_s = sfSprite_create();
    game->main_menu->tree_s = sfSprite_create();
    game->main_menu->house_s = sfSprite_create();
    game->main_menu->grass_s = sfSprite_create();
    game->main_menu->snail_s = sfSprite_create();
    game->main_menu->zombie_s = sfSprite_create();
    game->main_menu->balloon_s = sfSprite_create();
    game->main_menu->play_s = sfSprite_create();
    game->main_menu->play_2_s = sfSprite_create();
    game->main_menu->bubble_s = sfSprite_create();
}

void create_text_font_string(game_t *game)
{
    sfText_setFont(game->main_menu->settings, game->main_menu->font);
    sfText_setFont(game->main_menu->help, game->main_menu->font);
    sfText_setFont(game->main_menu->quit, game->main_menu->font);
    sfText_setFont(game->main_menu->dave_text, game->set_menu->set_font);
    sfText_setString(game->main_menu->settings, "SETTINGS");
    sfText_setString(game->main_menu->help, "HOW TO\n  PLAY");
    sfText_setString(game->main_menu->quit, "QUIT");
    sfText_setString(game->main_menu->dave_text, HELP);
}

void create_text(game_t *game)
{
    game->main_menu->settings = sfText_create();
    game->main_menu->help = sfText_create();
    game->main_menu->quit = sfText_create();
    game->main_menu->dave_text = sfText_create();
    game->main_menu->font = sfFont_createFromFile("assets/font/police.ttf");
    create_text_font_string(game);
    sfText_setPosition(game->main_menu->settings,
    (sfVector2f){1575 * game->ratio, 915 * game->ratio});
    sfText_setPosition(game->main_menu->help,
    (sfVector2f){1687 * game->ratio, 950 * game->ratio});
    sfText_setPosition(game->main_menu->quit,
    (sfVector2f){1800 * game->ratio, 925 * game->ratio});
    sfText_setCharacterSize(game->main_menu->settings, 30 * game->ratio);
    sfText_setCharacterSize(game->main_menu->help, 26 * game->ratio);
    sfText_setCharacterSize(game->main_menu->quit, 40 * game->ratio);
    sfText_setCharacterSize(game->main_menu->dave_text, 26 * game->ratio);
    sfText_setColor(game->main_menu->dave_text, sfBlack);
}