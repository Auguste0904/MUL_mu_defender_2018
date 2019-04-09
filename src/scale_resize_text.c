/*
** EPITECH PROJECT, 2019
** scale_resize_text
** File description:
** Scale for the resize of the text from the change of the size of the window
*/

#include "my.h"

void text_setcharasize(game_t * game)
{
    sfText_setCharacterSize(game->set_menu->back, 100 * game->ratio);
    sfText_setCharacterSize(game->set_menu->window1, 25 * game->ratio);
    sfText_setCharacterSize(game->set_menu->window2, 25 * game->ratio);
    sfText_setCharacterSize(game->set_menu->window3, 25 * game->ratio);
    sfText_setCharacterSize(game->main_menu->settings, 30 * game->ratio);
    sfText_setCharacterSize(game->main_menu->help, 26 * game->ratio);
    sfText_setCharacterSize(game->main_menu->quit, 40 * game->ratio);
    sfText_setCharacterSize(game->main_menu->dave_text, 50 * game->ratio);
}

void scale_text(game_t *game)
{
    sfText_setPosition(game->set_menu->back,
    (sfVector2f){855 * game->ratio, 890 * game->ratio});
    sfText_setPosition(game->set_menu->window1,
    (sfVector2f){850 * game->ratio, 697 * game->ratio});
    sfText_setPosition(game->set_menu->window2,
    (sfVector2f){850 * game->ratio, 760 * game->ratio});
    sfText_setPosition(game->set_menu->window3,
    (sfVector2f){850 * game->ratio, 823 * game->ratio});
    sfText_setPosition(game->main_menu->settings,
    (sfVector2f){1575 * game->ratio, 915 * game->ratio});
    sfText_setPosition(game->main_menu->help,
    (sfVector2f){1687 * game->ratio, 950 * game->ratio});
    sfText_setPosition(game->main_menu->quit,
    (sfVector2f){1800 * game->ratio, 925 * game->ratio});
    sfSprite_setScale(game->main_menu->dave_s,
    (sfVector2f){game->ratio * 1.25, game->ratio * 1.25});
    sfText_setPosition(game->main_menu->dave_text, (sfVector2f)
    {sfSprite_getPosition(game->main_menu->dave_s).x + 140 * game->ratio,
    sfSprite_getPosition(game->main_menu->dave_s).y - 190 * game->ratio});
    text_setcharasize(game);
}