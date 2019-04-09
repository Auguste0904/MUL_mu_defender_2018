/*
** EPITECH PROJECT, 2019
** main_menu_three
** File description:
** My_defender
*/

#include "my.h"

void check_pop_pos(game_t *game, sfIntRect *rect, int *done)
{
    sfVector2f pos = sfSprite_getPosition(game->main_menu->balloon_s);

    if (game->window->event.type == sfEvtMouseButtonPressed &&
    game->window->event.mouseButton.button == sfMouseLeft &&
    rect[0].left == 0 && game->main_menu->x > pos.x + 40 &&
    game->main_menu->x < pos.x + 130 &&
    game->main_menu->y > pos.y + 40 &&
    game->main_menu->y < pos.y + 130) {
        sfMusic_play(game->main_menu->boom);
        rect[0].left += 200;
    }
    if (rect[0].left > 0 && rect[0].left < 600 && done[0]) {
        if (done[0] % 5 == 0)
            rect[0].left += 200;
        else
            done[0] += 1;
    }
    if (sfSprite_getPosition(game->main_menu->zombie_s).x < -250 * game->ratio)
        sfSprite_setPosition(game->main_menu->zombie_s, (sfVector2f)
        {1920 * game->ratio, rand() % 100 * game->ratio + 400 * game->ratio});
}

void move_zombie(game_t *game, sfIntRect *rect, int *done, float *speed)
{
    if (rect[0].left > 0) {
        if (done[0] == 0) {
            speed[0] =
            sin(sfSprite_getPosition(game->main_menu->zombie_s).x / 75);
            done[0] = 1;
        }
        sfSprite_move(game->main_menu->zombie_s, (sfVector2f){-3, speed[0]});
        speed[0] += 0.25;
    } else {
        sfSprite_move(game->main_menu->zombie_s,
        (sfVector2f){-3 * game->ratio,
            sin(sfSprite_getPosition(game->main_menu->zombie_s).x / 75)});
        sfSprite_setPosition(game->main_menu->balloon_s,
        (sfVector2f){sfSprite_getPosition(game->main_menu->zombie_s).x
            - 30 * game->ratio,
            sfSprite_getPosition(game->main_menu->zombie_s).y
            - 65 * game->ratio});
    }
}

void manage_zombie(game_t *game)
{
    static sfIntRect rect = (sfIntRect){0, 0, 200, 154};
    static float speed = 0;
    static int done = 0;

    if (sfSprite_getPosition(game->main_menu->zombie_s).y >=
    1080 * game->ratio) {
        done = 0;
        rect = (sfIntRect){0, 0, 200, 154};
        sfSprite_setPosition(game->main_menu->zombie_s,
        (sfVector2f){-500 * game->ratio, 1080 * game->ratio});
    }
    check_pop_pos(game, &rect, &done);
    move_zombie(game, &rect, &done, &speed);
    sfSprite_setTextureRect(game->main_menu->balloon_s, rect);
}
