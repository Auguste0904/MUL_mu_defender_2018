/*
** EPITECH PROJECT, 2019
** draw_game_loop
** File description:
** Draw all of the game loop
*/

#include "my.h"

void draw_intro3(game_t * game)
{
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->back_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->zombie_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->green_flo_hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->sunflower_hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->wallnut_hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->cactus_hud_s, NULL);
}

void draw_intro2(game_t *game, int alpha)
{
    draw_intro3(game);
    if (alpha < 255 / 3)
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->ready_s, NULL);
    else if (alpha < (255 / 3) * 2)
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->set_s, NULL);
    else
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->play_s, NULL);
}

void draw_game_loop(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->back_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->green_flo_hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->sunflower_hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->wallnut_hud_s, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->cactus_hud_s, NULL);
    sfRenderWindow_drawText(game->window->wind,
    game->game_loop->price, NULL);
}

void display_dragndrop2(game_t *game)
{
    if (game->game_loop->drag == 3) {
        sfSprite_setPosition(game->game_loop->wallnut_s,
        (sfVector2f){game->game_loop->x, game->game_loop->y});
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->wallnut_s, NULL);
    }
    if (game->game_loop->drag == 4) {
        sfSprite_setPosition(game->game_loop->cactus_s,
        (sfVector2f){game->game_loop->x, game->game_loop->y});
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->cactus_s, NULL);
    }
}

void display_dragndrop(game_t *game)
{
    if (game->game_loop->drag == 1) {
        sfSprite_setPosition(game->game_loop->sunflower_s,
        (sfVector2f){game->game_loop->x, game->game_loop->y});
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->sunflower_s, NULL);
    }
    if (game->game_loop->drag == 2) {
        sfSprite_setPosition(game->game_loop->peashooter_s,
        (sfVector2f){game->game_loop->x, game->game_loop->y});
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->peashooter_s, NULL);
    }
    display_dragndrop2(game);
}
