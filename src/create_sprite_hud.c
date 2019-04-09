/*
** EPITECH PROJECT, 2019
** create_sprite_hud
** File description:
** createtion of sprite hud
*/

#include "my.h"

void create_sprite_hud_sprite(game_t *game)
{
    game->game_loop->green_flo_hud_s = sfSprite_create();
    game->game_loop->sunflower_hud_s = sfSprite_create();
    game->game_loop->wallnut_hud_s = sfSprite_create();
    game->game_loop->cactus_hud_s = sfSprite_create();
}

void create_sprite_hud_position(game_t *game)
{
    sfSprite_setPosition(game->game_loop->green_flo_hud_s,
    (sfVector2f){-244 * game->ratio, 128 * game->ratio});
    sfSprite_setPosition(game->game_loop->sunflower_hud_s,
    (sfVector2f){-169 * game->ratio, 128 * game->ratio});
    sfSprite_setPosition(game->game_loop->wallnut_hud_s,
    (sfVector2f){-97 * game->ratio, 128 * game->ratio});
    sfSprite_setPosition(game->game_loop->cactus_hud_s,
    (sfVector2f){-22 * game->ratio, 128 * game->ratio});
}

void create_sprite_hud_texture(game_t *game)
{
    sfSprite_setTexture(game->game_loop->green_flo_hud_s,
    game->game_loop->green_flo_hud, sfTrue);
    sfSprite_setTexture(game->game_loop->sunflower_hud_s,
    game->game_loop->sunflower_hud, sfTrue);
    sfSprite_setTexture(game->game_loop->cactus_hud_s,
    game->game_loop->cactus_hud, sfTrue);
    sfSprite_setTexture(game->game_loop->wallnut_hud_s,
    game->game_loop->wallnut_hud, sfTrue);
}

void create_sprite_hud_scale(game_t *game)
{
    sfSprite_setScale(game->game_loop->green_flo_hud_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->game_loop->sunflower_hud_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->game_loop->wallnut_hud_s,
    (sfVector2f){1.275 * game->ratio, 1.275 * game->ratio});
    sfSprite_setScale(game->game_loop->cactus_hud_s,
    (sfVector2f){game->ratio, game->ratio});
}

void create_sprite_hud(game_t *game)
{
    create_sprite_hud_sprite(game);
    game->game_loop->green_flo_hud =
    sfTexture_createFromFile("assets/img/game/basic_flower_card.png", NULL);
    game->game_loop->cactus_hud =
    sfTexture_createFromFile("assets/img/game/cactus_card.png", NULL);
    game->game_loop->sunflower_hud =
    sfTexture_createFromFile("assets/img/game/sunflower_card.png", NULL);
    game->game_loop->wallnut_hud =
    sfTexture_createFromFile("assets/img/game/wallnut_card.png", NULL);
    create_sprite_hud_texture(game);
    create_sprite_hud_position(game);
    create_sprite_hud_scale(game);
}