/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

void game_end6(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->back_s, NULL);
    display_sunflower(game);
    display_wallnut(game);
    display_pea(game);
    display_pick(game);
    display_peashooter(game);
    display_cactus(game);
    display_zombie(game);
    display_sun(game);
    sfRenderWindow_drawRectangleShape(game->window->wind,
    game->game_loop->black_fade, NULL);
    sfRenderWindow_drawSprite(game->window->wind,
    game->game_loop->zombiewon_s, NULL);
    sfRenderWindow_display(game->window->wind);
    sfRenderWindow_clear(game->window->wind, sfBlack);
}

void game_end5(game_t *game, float *speed)
{
    sunflower_t *sunflower = game->sunflower;
    sun_t *sun = game->sun;

    while (sunflower) {
        sunflower->pos.x += speed[0];
        sunflower = sunflower->next;
    }
    while (sun) {
        sun->pos.x += speed[0];
        sun = sun->next;
    }
    sfSprite_move(game->game_loop->back_s, (sfVector2f){speed[0], 0});
    sfClock_restart(game->game_loop->anim);
}

void game_end4(game_t *game, float *speed)
{
    pick_t *pick = game->pick;
    wallnut_t *wallnut = game->wallnut;
    pea_t *pea = game->pea;

    while (pick) {
        pick->pos.x += speed[0];
        pick = pick->next;
    }
    while (wallnut) {
        wallnut->pos.x += speed[0];
        wallnut = wallnut->next;
    }
    while (pea) {
        pea->pos.x += speed[0];
        pea = pea->next;
    }
    game_end5(game, speed);
}

void game_end3(game_t *game, float *speed)
{
    zombie_t *zombie = game->zombie;
    peashooter_t *peashooter = game->peashooter;
    cactus_t *cactus = game->cactus;

    while (zombie) {
        zombie->pos.x += speed[0];
        zombie = zombie->next;
    }
    while (peashooter) {
        peashooter->pos.x += speed[0];
        peashooter = peashooter->next;
    }
    while (cactus) {
        cactus->pos.x += speed[0];
        cactus = cactus->next;
    }
    game_end4(game, speed);
}

void game_end2(game_t *game, int *accelerate, float *speed)
{
    if (sfClock_getElapsedTime(game->game_loop->anim).microseconds >
        12000 && accelerate[0] != -1) {
        if (accelerate[0] == 1) {
            speed[0] += 0.2;
            if (speed[0] >= 10)
                accelerate[0] = 0;
        }
        if (accelerate[0] == 0) {
            speed[0] -= 0.2;
                if (speed[0] <= 0)
                    accelerate[0] = -1;
        }
        if (accelerate[0] == -1)
            speed[0] = 0;
        game_end3(game, speed);
    }
}

void game_end1(game_t *game, int *accelerate, float *speed, int *alpha)
{
    if (accelerate[0] == -1) {
        sfMusic_play(game->game_loop->scream);
        sfMusic_play(game->game_loop->chomp);
        sfClock_restart(game->game_loop->anim);
        accelerate[0] = -2;
    }
    if (sfClock_getElapsedTime(game->game_loop->anim).microseconds > 12000 &&
        accelerate[0] == -2 && alpha[0] < 255) {
        alpha[0] += 2;
        sfSprite_setColor(game->game_loop->zombiewon_s,
        sfColor_fromRGBA(255, 255, 255, alpha[0]));
        sfRectangleShape_setFillColor(game->game_loop->black_fade,
        sfColor_fromRGBA(0, 0, 0, alpha[0]));
        sfClock_restart(game->game_loop->anim);
    }
    game_end2(game, accelerate, speed);
}

void game_end(game_t *game, int *close)
{
    float speed = 0;
    int accelerate = 1;
    int alpha = 1;

    sfClock_restart(game->game_loop->anim);
    sfMusic_play(game->game_loop->lose);
    sfMusic_stop(game->game_loop->music);
    create_outro(game);
    while (sfRenderWindow_isOpen(game->window->wind) && close[0] != 42) {
        close_end(game, close);
        game_end1(game, &accelerate, &speed, &alpha);
        game_end6(game);
    }
}
