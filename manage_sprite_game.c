/*
** EPITECH PROJECT, 2019
** manage_sprite_game
** File description:
** manage sprite
*/

#include "my.h"

void manage_game_pick(game_t *game)
{
    pick_t *pick = game->pick;
    pick_t *pick_backup = NULL;
    int move =
    (sfClock_getElapsedTime(game->game_loop->bullet2_move).microseconds
    > 20000) ? 1 : 0;

    if (move == 1) {
        while (pick) {
            pick_backup = pick->next;
            manage_pick_zombie(game, pick);
            pick = pick_backup;
        }
        sfClock_restart(game->game_loop->bullet2_move);
    }
}

void manage_game_pea(game_t *game)
{
    pea_t *pea = game->pea;
    pea_t *pea_backup = NULL;
    int move =
    (sfClock_getElapsedTime(game->game_loop->bullet_move).microseconds
    > 20000) ? 1 : 0;

    if (move == 1) {
        while (pea) {
            pea_backup = pea->next;
            manage_pea_zombie(game, pea);
            pea = pea_backup;
        }
        sfClock_restart(game->game_loop->bullet_move);
    }
}

void manage_pea_zombie(game_t *game, pea_t *pea)
{
    zombie_t *zombie = game->zombie;
    zombie_t *zombie_backup = NULL;

    if (pea->pos.x > 1920) {
        destroy_pea(game, pea);
    } else {
        pea->pos.x += 9 *game->ratio;
        zombie = game->zombie;
        while (zombie) {
            zombie_backup = zombie->next;
            check_pea_damage(game, zombie, pea);
            zombie = zombie_backup;
        }
    }
}

void manage_game_peashooter(game_t *game)
{
    peashooter_t *peashooter = game->peashooter;
    pea_t *pea = game->pea;
    zombie_t *zombie = game->zombie;
    int shot = 0;

    while (peashooter != NULL) {
        move_rect_peashooter(peashooter);
        shot = 0;
        zombie = game->zombie;
        while (zombie != NULL) {
            if (peashooter->pos.x < zombie->pos.x && zombie->pos.x < 1750 &&
            peashooter->pos.y > zombie->pos.y &&
            peashooter->pos.y < zombie->pos.y + 150)
                shot = 1;
            zombie = zombie->next;
        }
        if (sfClock_getElapsedTime(peashooter->attack).microseconds >
        1400000 && shot) {
            pea = game->pea;
            if (game->pea == NULL) {
                game->pea = create_pea((sfVector2f){peashooter->pos.x + 15,
                peashooter->pos.y - 38}, 15);
            } else {
                while (pea->next != NULL)
                    pea = pea->next;
                pea->next = create_pea((sfVector2f){peashooter->pos.x + 15,
                peashooter->pos.y - 38}, 15);
            }
            sfClock_restart(peashooter->attack);
        }
        peashooter = peashooter->next;
    }
}