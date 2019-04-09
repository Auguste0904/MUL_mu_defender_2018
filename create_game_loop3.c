/*
** EPITECH PROJECT, 2019
** create_game_loop3
** File description:
** Creation of the game loop
*/

#include "my.h"

void change_sprite_game_play_scale(game_t *game)
{
    sfSprite_setScale(game->game_loop->hud_s,
    (sfVector2f){2.67415 * game->ratio, 2.67415 * game->ratio});
    sfSprite_setScale(game->game_loop->green_flo_hud_s,
    (sfVector2f){1.2 * game->ratio, 1.2 * game->ratio});
    sfSprite_setScale(game->game_loop->sunflower_hud_s,
    (sfVector2f){1.2 * game->ratio, 1.2 * game->ratio});
    sfSprite_setScale(game->game_loop->wallnut_hud_s,
    (sfVector2f){1.525 * game->ratio, 1.525 * game->ratio});
    sfSprite_setScale(game->game_loop->cactus_hud_s,
    (sfVector2f){1.2 * game->ratio, 1.2 * game->ratio});
}

void change_sprite_game_play_position(game_t *game)
{
    sfSprite_setScale(game->game_loop->back_s,
    (sfVector2f){1.16 * game->ratio, 1.16 * game->ratio});
    sfSprite_setPosition(game->game_loop->hud_s,
    (sfVector2f){0, 0});
    sfSprite_setPosition(game->game_loop->green_flo_hud_s,
    (sfVector2f){143 * game->ratio, 20 * game->ratio});
    sfSprite_setPosition(game->game_loop->sunflower_hud_s,
    (sfVector2f){230 * game->ratio, 22 * game->ratio});
    sfSprite_setPosition(game->game_loop->wallnut_hud_s,
    (sfVector2f){317 * game->ratio, 22 * game->ratio});
    sfSprite_setPosition(game->game_loop->cactus_hud_s,
    (sfVector2f){402 * game->ratio, 22 * game->ratio});
    change_sprite_game_play_scale(game);
}

void create_clock_game_play(game_t *game)
{
    game->game_loop->bullet_move = sfClock_create();
    game->game_loop->bullet2_move = sfClock_create();
    game->game_loop->sun_move = sfClock_create();
    game->game_loop->game_sun = sfClock_create();
    game->check_lose = sfClock_create();
}

void set_color_game_play(game_t *game)
{
    sfSprite_setColor(game->game_loop->hud_s,
    sfColor_fromRGBA(255, 255, 255, 255));
    sfSprite_setColor(game->game_loop->green_flo_hud_s,
    sfColor_fromRGBA(255, 255, 255, 255));
    sfSprite_setColor(game->game_loop->sunflower_hud_s,
    sfColor_fromRGBA(255, 255, 255, 255));
    sfSprite_setColor(game->game_loop->wallnut_hud_s,
    sfColor_fromRGBA(255, 255, 255, 255));
    sfSprite_setColor(game->game_loop->cactus_hud_s,
    sfColor_fromRGBA(255, 255, 255, 255));
}

void change_sprite_game_play(game_t *game)
{
    sfSprite_move(game->game_loop->back_s,
    (sfVector2f){498 * game->ratio, -17 * game->ratio});
    change_sprite_game_play_position(game);
    set_color_game_play(game);
    game->game_loop->drag = 0;
    game->pause = 0;
    create_clock_game_play(game);
    game->sunflower = (struct sunflower *)NULL;
    game->peashooter = (struct peashooter *)NULL;
    game->cactus = (struct cactus *)NULL;
    game->pea = (struct pea *)NULL;
    game->pick = (struct pick *)NULL;
    game->zombie = (struct zombie *)NULL;
    game->sun = (struct sun *)NULL;
    game->wallnut = (struct wallnut *)NULL;
}