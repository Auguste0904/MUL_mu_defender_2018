/*
** EPITECH PROJECT, 2019
** create_set_menu
** File description:
** All creation of the settings menu
*/

#include "my.h"

void modif_text_set(game_t *game)
{
    sfText_setPosition(game->set_menu->back,
    (sfVector2f){855 * game->ratio, 890 * game->ratio});
    sfText_setPosition(game->set_menu->window1,
    (sfVector2f){850 * game->ratio, 697 * game->ratio});
    sfText_setPosition(game->set_menu->window2,
    (sfVector2f){850 * game->ratio, 760 * game->ratio});
    sfText_setPosition(game->set_menu->window3,
    (sfVector2f){850 * game->ratio, 823 * game->ratio});
    sfText_setCharacterSize(game->set_menu->back, 100 * game->ratio);
    sfText_setCharacterSize(game->set_menu->window1, 25 * game->ratio);
    sfText_setCharacterSize(game->set_menu->window2, 25 * game->ratio);
    sfText_setCharacterSize(game->set_menu->window3, 25 * game->ratio);
}

void create_text_set(game_t *game)
{
    game->set_menu->set_font =
    sfFont_createFromFile("assets/font/set_font.otf");
    game->set_menu->back = sfText_create();
    game->set_menu->window1 = sfText_create();
    game->set_menu->window2 = sfText_create();
    game->set_menu->window3 = sfText_create();
    sfText_setFont(game->set_menu->back, game->set_menu->set_font);
    sfText_setFont(game->set_menu->window1, game->set_menu->set_font);
    sfText_setFont(game->set_menu->window2, game->set_menu->set_font);
    sfText_setFont(game->set_menu->window3, game->set_menu->set_font);
    sfText_setString(game->set_menu->back, "BACK");
    sfText_setString(game->set_menu->window1, "1920x1080 (Windowed)");
    sfText_setString(game->set_menu->window2, "1664x936 (Windowed)");
    sfText_setString(game->set_menu->window3, "1280x720 (Windowed)");
    modif_text_set(game);
}

void create_sprite_set(game_t *game)
{
    game->set_menu->tab_s = sfSprite_create();
    game->set_menu->valide_but_s = sfSprite_create();
}

void create_texture_set(game_t *game)
{
    game->set_menu->tab =
    sfTexture_createFromFile("assets/img/set_menu/tab.png", NULL);
    game->set_menu->valide_but =
    sfTexture_createFromFile("assets/img/set_menu/button_ok.png", NULL);
}

void create_set_menu(game_t *game)
{
    game->set_menu->fullscreen = 0;
    create_sprite_set(game);
    create_texture_set(game);
    create_text_set(game);
    sfSprite_setTexture(game->set_menu->tab_s, game->set_menu->tab, sfTrue);
    sfSprite_setTexture(game->set_menu->valide_but_s,
    game->set_menu->valide_but, sfTrue);
    sfSprite_setPosition(game->set_menu->tab_s,
    (sfVector2f){385 * game->ratio, 260 * game->ratio});
    sfSprite_setPosition(game->set_menu->valide_but_s,
    (sfVector2f){1073 * game->ratio, 615 * game->ratio});
    sfSprite_setScale(game->set_menu->tab_s,
    (sfVector2f){1.45 * game->ratio, 1.45 * game->ratio});
    sfSprite_setScale(game->set_menu->valide_but_s,
    (sfVector2f){1.32 * game->ratio, 1.32 * game->ratio});
}