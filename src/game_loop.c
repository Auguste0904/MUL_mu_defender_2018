/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void check_pea_damage(game_t *game, zombie_t *zombie, pea_t *pea)
{
    if (pea->pos.x - 38 > zombie->pos.x &&
    pea->pos.x < zombie->pos.x + 100 &&
    pea->pos.y > zombie->pos.y &&
    pea->pos.y < zombie->pos.y + 100) {
        damage_zombie(game, zombie, pea);
    }
}

void click_sun(game_t *game)
{
    sun_t *sun = game->sun;
    sun_t *sun_backup = NULL;
    sun_t *sun_destroy = NULL;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        while (sun != NULL) {
            sun_backup = sun->next;
            if (game->game_loop->x > sun->pos.x &&
            game->game_loop->x < sun->pos.x + 115 &&
            game->game_loop->y > sun->pos.y &&
            game->game_loop->y < sun->pos.y + 115) {
                if (sun == game->sun) {
                    game->sun = game->sun->next;
                } else {
                    sun_destroy = game->sun;
                    while (sun_destroy->next != NULL &&
                    sun_destroy->next != sun)
                        sun_destroy = sun_destroy->next;
                    if (sun_destroy->next)
                        sun_destroy->next = sun_destroy->next->next;
                }
                change_display_price(game, game->game_loop->nb_price += 50);
                sfMusic_play(game->game_loop->points);
            }
            sun = sun_backup;
        }
    }
}

int check_lose(game_t *game)
{
    zombie_t *zombie = game->zombie;
    int lose = 0;

    if (sfClock_getElapsedTime(game->check_lose).microseconds >
    1000000) {
        while (zombie && lose == 0) {
            lose = (zombie->pos.x + 140 < 0) ? 1 : lose;
            zombie = zombie->next;
        }
    }
    game->lose = lose;
    return (lose);
}

void game_play(game_t *game, int *close)
{
    create_text_price(game);
    create_pause(game);
    create_text_pause(game);
    change_sprite_game_play(game);
    game->game = 1;
    game->zombie = create_zombie(game);
    game->zombie_wave = 0;
    game->zombie_clock_limit = 10000000 + rand() % 50000;
    game->zombie_clock = sfClock_create();
    sfMusic_play(game->game_loop->awooga);
    game->game_loop->enemy_move = sfClock_create();
    sfSprite_setTextureRect(game->game_loop->sunflower_s,
    (sfIntRect){0, 0, 100, 100});
    sfSprite_setTextureRect(game->game_loop->peashooter_s,
    (sfIntRect){0, 0, 100, 120});
    sfSprite_setTextureRect(game->game_loop->wallnut_s,
    (sfIntRect){0, 0, 100, 100});
    sfSprite_setTextureRect(game->game_loop->cactus_s,
    (sfIntRect){0, 0, 100, 100});
    while (sfRenderWindow_isOpen(game->window->wind) &&
    close[0] != 42 && check_lose(game) == 0) {
        rand();
        event_close(game, close);
        if (game->pause == 0) {
            manage_zombie_wave(game);
            manage_game_zombie(game);
            manage_game_sunflower(game);
            manage_game_peashooter(game);
            manage_game_cactus(game);
            manage_game_pea(game);
            manage_game_pick(game);
            manage_game_sun(game);
            manage_game_wallnut(game);
            click_sunflower_hud(game);
            click_peashooter_hud(game);
            click_wallnut_hud(game);
            click_cactus_hud(game);
            click_sun(game);
        }
        draw_game_loop(game);
        display_sunflower(game);
        display_wallnut(game);
        display_pick(game);
        display_pea(game);
        display_cactus(game);
        display_peashooter(game);
        display_zombie(game);
        display_sun(game);
        display_dragndrop(game);
        if (game->pause == 1) {
            sfRenderWindow_drawSprite(game->window->wind ,
            game->game_loop->pause_s, NULL);
            sfRenderWindow_drawText(game->window->wind,
            game->game_loop->resume, NULL);
            sfRenderWindow_drawText(game->window->wind,
            game->game_loop->menu, NULL);
            sfRenderWindow_drawText(game->window->wind,
            game->game_loop->quit, NULL);
            change_text_pause_menu(game);
            click_text_pause_menu(game, close);
        }
        sfRenderWindow_display(game->window->wind);
        sfRenderWindow_clear(game->window->wind, sfBlack);
    }
}

int game_loop(game_t *game)
{
    int close = 0;

    create_intro(game);
    create_plants(game);
    create_game_loop(game);
    create_sprite_hud(game);
    sfMusic_play(game->game_loop->music);
    game_intro(game, &close);
    game_intro2(game, &close);
    game_play(game, &close);
    if (game->lose == 1)
        close = 0;
    game_end(game, &close);
    destroy_game_loop(game);
    return (0);
}
