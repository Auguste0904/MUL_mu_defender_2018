/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

void manage_move_zombie(game_t *game, int can_move, zombie_t *zombie)
{
    if (can_move == 1) {
        zombie->pos.x += -1.5 * game->ratio;
        move_rect_zombie(zombie);
    } else {
        eat_rect_zombie(zombie);
    }
}

void damage_zombie12(game_t *game, zombie_t *zombie, zombie_t *tmp1)
{
    if (zombie == game->zombie) {
        game->zombie = game->zombie->next;
    } else {
        while (tmp1->next != NULL && tmp1->next != zombie)
            tmp1 = tmp1->next;
        if (tmp1->next)
            tmp1->next = tmp1->next->next;
    }
}

void damage_sunflower12(game_t *game, sunflower_t *sunflower, sunflower_t *tmp1)
{
    if (sunflower == game->sunflower) {
        game->sunflower = game->sunflower->next;
    } else {
        while (tmp1->next != NULL && tmp1->next != sunflower)
            tmp1 = tmp1->next;
        if (tmp1->next)
            tmp1->next = tmp1->next->next;
    }
}
