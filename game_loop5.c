/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void destroy_pea(game_t *game, pea_t *pea)
{
    pea_t *tmp1;

    if (game->pea == NULL || pea == NULL)
        return ;
    if (pea == game->pea) {
        game->pea = (game->pea->next != NULL) ? game->pea->next : NULL;
    } else {
        tmp1 = game->pea;
        while (tmp1->next != NULL && tmp1->next != pea)
            tmp1 = tmp1->next;
        if (tmp1->next) {
            tmp1->next = tmp1->next->next;
        }
    }
}

void destroy_pick(game_t *game, pick_t *pick)
{
    pick_t *tmp1;

    if (game->pick == NULL || pick == NULL)
        return ;
    if (pick == game->pick) {
        game->pick = (game->pick->next != NULL) ? game->pick->next : NULL;
    } else {
        tmp1 = game->pick;
        while (tmp1->next != NULL && tmp1->next != pick)
            tmp1 = tmp1->next;
        if (tmp1->next) {
            tmp1->next = tmp1->next->next;
        }
    }
}

void damage_zombie(game_t *game, zombie_t *zombie, pea_t *pea)
{
    zombie_t *tmp1 = game->zombie;

    zombie->health -= pea->damage;
    sfMusic_play(game->game_loop->peashot);
    if (zombie->health <= 0) {
        sfClock_destroy(zombie->anim);
        sfClock_destroy(zombie->attack);
        damage_zombie12(game, zombie, tmp1);
    }
    game->score += pea->damage;
    destroy_pea(game, pea);
}

void damage_zombie2(game_t *game, zombie_t *zombie, pick_t *pick)
{
    zombie_t *tmp1 = game->zombie;

    zombie->health -= pick->damage;
    sfMusic_play(game->game_loop->peashot);
    if (zombie->health <= 0) {
        sfClock_destroy(zombie->anim);
        sfClock_destroy(zombie->attack);
        damage_zombie12(game, zombie, tmp1);
    }
    game->score += pick->damage;
    destroy_pick(game, pick);
}

void damage_plant2(game_t *game, sunflower_t *sunflower, zombie_t *zombie)
{
    sunflower_t *tmp1 = game->sunflower;

    if (sfClock_getElapsedTime(zombie->attack).microseconds > 500000) {
        sunflower->health -= zombie->damage;
        if (sunflower->health <= 0) {
            sfClock_destroy(sunflower->anim);
            sfClock_destroy(sunflower->sun);
            damage_sunflower12(game, sunflower, tmp1);
        }
        sfMusic_play(game->game_loop->chomp);
        sfClock_restart(zombie->attack);
    }
}
