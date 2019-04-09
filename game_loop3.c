/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void game_init_intro(game_t *game, int alpha)
{
    sfSprite_setColor(game->game_loop->hud_s,
    sfColor_fromRGBA(255, 255, 255, alpha));
    sfSprite_setColor(game->game_loop->green_flo_hud_s,
    sfColor_fromRGBA(255, 255, 255, alpha));
    sfSprite_setColor(game->game_loop->sunflower_hud_s,
    sfColor_fromRGBA(255, 255, 255, alpha));
    sfSprite_setColor(game->game_loop->wallnut_hud_s,
    sfColor_fromRGBA(255, 255, 255, alpha));
    sfSprite_setColor(game->game_loop->cactus_hud_s,
    sfColor_fromRGBA(255, 255, 255, alpha));
    sfSprite_setPosition(game->game_loop->hud_s,
    (sfVector2f){-369 * game->ratio, 108 * game->ratio});
    sfClock_restart(game->game_loop->anim);
}

void game_intro_setalpha(game_t *game, int *alpha, int *close)
{
    rand();
    event_close(game, close);
    if (alpha[0] < 255 && sfClock_getElapsedTime(game->game_loop->anim)
    .microseconds > 8000) {
        alpha[0] = (alpha[0] > 250) ? 255 : alpha[0] + 2 * (1 / game->ratio);
        sfSprite_setColor(game->game_loop->hud_s,
        sfColor_fromRGBA(255, 255, 255, alpha[0]));
        sfSprite_setColor(game->game_loop->green_flo_hud_s,
        sfColor_fromRGBA(255, 255, 255, alpha[0]));
        sfSprite_setColor(game->game_loop->sunflower_hud_s,
        sfColor_fromRGBA(255, 255, 255, alpha[0]));
        sfSprite_setColor(game->game_loop->wallnut_hud_s,
        sfColor_fromRGBA(255, 255, 255, alpha[0]));
        sfSprite_setColor(game->game_loop->cactus_hud_s,
        sfColor_fromRGBA(255, 255, 255, alpha[0]));
        sfClock_restart(game->game_loop->anim);
    }
    draw_intro2(game, alpha[0]);
}

void game_intro_drawalpha(game_t *game, int alpha)
{
    if (alpha < 255 / 3) {
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->ready_s, NULL);
    } else if (alpha < (255 / 3) * 2) {
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->set_s, NULL);
    } else {
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->play_s, NULL);
    }
    sfRenderWindow_display(game->window->wind);
    sfRenderWindow_clear(game->window->wind, sfBlack);
}

void game_intro2(game_t *game, int *close)
{
    int alpha = 0;

    game_init_intro(game, alpha);
    while (sfRenderWindow_isOpen(game->window->wind) && !close[0] &&
    alpha < 255) {
        game_intro_setalpha(game, &alpha, close);
        game_intro_drawalpha(game, alpha);
    }
    sfView_reset(game->game_loop->view, (sfFloatRect)
    {0, 0, 1920 * game->ratio, 1080 * game->ratio});
    sfRenderWindow_setView(game->window->wind, game->game_loop->view);
}

void manage_zombie_peashooter(game_t *game, zombie_t *zombie, int *can_move)
{
    peashooter_t *peashooter = game->peashooter;
    peashooter_t *peashooter_backup = NULL;

    while (peashooter) {
        peashooter_backup = peashooter->next;
        if (zombie->pos.x + 20 > peashooter->pos.x &&
        zombie->pos.x + 20 < peashooter->pos.x + 20 &&
        zombie->pos.y < peashooter->pos.y &&
        peashooter->pos.y < zombie->pos.y + 150) {
            damage_plant(game, peashooter, zombie);
            can_move[0] = 0;
        }
        peashooter = peashooter_backup;
    }
}
