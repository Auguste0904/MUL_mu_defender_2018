/*
** EPITECH PROJECT, 2019
** draw_main_menu
** File description:
** All draw of my_defender's main menu
*/

#include "my.h"

void draw_main_menu2(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->snail_s, NULL);
    sfRenderWindow_drawText(game->window->wind,
    game->main_menu->settings, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->dave_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->bubble_s, NULL);
    sfRenderWindow_drawText(game->window->wind,
    game->main_menu->help, NULL);
    sfRenderWindow_drawText(game->window->wind,
    game->main_menu->quit, NULL);
    sfRenderWindow_drawText(game->window->wind,
    game->main_menu->dave_text, NULL);
}

void draw_main_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->back_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->house_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->zombie_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->balloon_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->tree_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->tombstone_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->logo_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->grass_s, NULL);
    draw_main_menu2(game);
}

void draw_text_set_menu(game_t *game)
{
    sfRenderWindow_drawText(game->window->wind, game->set_menu->back, NULL);
    sfRenderWindow_drawText(game->window->wind, game->set_menu->window1, NULL);
    sfRenderWindow_drawText(game->window->wind, game->set_menu->window2, NULL);
    sfRenderWindow_drawText(game->window->wind, game->set_menu->window3, NULL);
    sfRenderWindow_drawText(game->window->wind, game->main_menu->help, NULL);
    sfRenderWindow_drawText(game->window->wind, game->main_menu->quit, NULL);
}

void draw_set_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->back_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->house_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->tree_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->tombstone_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->logo_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->main_menu->grass_s, NULL);
    sfRenderWindow_drawText(game->window->wind,
    game->main_menu->settings, NULL);
    sfRenderWindow_drawSprite(game->window->wind, game->set_menu->tab_s, NULL);
    draw_text_set_menu(game);
}
