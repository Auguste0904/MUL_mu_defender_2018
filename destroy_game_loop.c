/*
** EPITECH PROJECT, 2019
** destroy_game_loop
** File description:
** All destroy og the game
*/

#include "my.h"

void destroy_game_loop2(game_t *game)
{
    sfMusic_destroy(game->game_loop->music);
    sfMusic_destroy(game->game_loop->pick);
    sfMusic_destroy(game->game_loop->drop);
    sfMusic_destroy(game->game_loop->chomp);
    sfMusic_destroy(game->game_loop->awooga);
    sfMusic_destroy(game->game_loop->peashot);
    sfMusic_destroy(game->game_loop->points);
    sfMusic_destroy(game->game_loop->lose);
    sfMusic_destroy(game->game_loop->scream);
}

void destroy_game_loop(game_t *game)
{
    sfView_destroy(game->game_loop->view);
    sfClock_destroy(game->game_loop->anim);
    sfClock_destroy(game->game_loop->sun_move);
    sfClock_destroy(game->game_loop->bullet_move);
    sfClock_destroy(game->game_loop->bullet2_move);
    sfClock_destroy(game->game_loop->enemy_move);
    sfClock_destroy(game->game_loop->game_sun);
    destroy_game_loop2(game);
    sfSprite_destroy(game->game_loop->back_s);
    sfTexture_destroy(game->game_loop->back);
    sfSprite_destroy(game->game_loop->zombie_s);
    sfTexture_destroy(game->game_loop->zombie);
    sfSprite_destroy(game->game_loop->sunflower_s);
    sfTexture_destroy(game->game_loop->sunflower);
    sfSprite_destroy(game->game_loop->green_flo_hud_s);
    sfTexture_destroy(game->game_loop->green_flo_hud);
    sfSprite_destroy(game->game_loop->sunflower_hud_s);
    sfTexture_destroy(game->game_loop->sunflower_hud);
}

void destroy_sun(game_t *game, sun_t *sun)
{
    sun_t *tmp1 = game->sun;

    if (sun == game->sun) {
        game->sun = game->sun->next;
    } else {
        while (tmp1->next != NULL && tmp1->next != sun)
            tmp1 = tmp1->next;
        if (tmp1->next)
            tmp1->next = tmp1->next->next;
    }
}