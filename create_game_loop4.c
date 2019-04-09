/*
** EPITECH PROJECT, 2019
** create_game_loop4
** File description:
** Creation of the game loop
*/

#include "my.h"

void create_plants_scale(game_t *game)
{
    game->game_loop->sunflower_s = sfSprite_create();
    game->game_loop->peashooter_s = sfSprite_create();
    game->game_loop->cactus_s = sfSprite_create();
    game->game_loop->pea_s = sfSprite_create();
    game->game_loop->pick_s = sfSprite_create();
    game->game_loop->sun_s = sfSprite_create();
    game->game_loop->wallnut_s = sfSprite_create();
    sfSprite_setScale(game->game_loop->sunflower_s,
    (sfVector2f){1.25 * game->ratio, 1.25 * game->ratio});
    sfSprite_setScale(game->game_loop->peashooter_s,
    (sfVector2f){0.95 * game->ratio, 0.95 * game->ratio});
    sfSprite_setScale(game->game_loop->cactus_s,
    (sfVector2f){1.25 * game->ratio, 1.25 * game->ratio});
    sfSprite_setScale(game->game_loop->pick_s,
    (sfVector2f){game->ratio * 1.2, game->ratio * 1.2});
    sfSprite_setScale(game->game_loop->sun_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->game_loop->wallnut_s,
    (sfVector2f){1.2 * game->ratio, 1.2 * game->ratio});
}

void create_plants_origins(game_t *game)
{
    sfSprite_setOrigin(game->game_loop->sunflower_s,
    (sfVector2f){50 * game->ratio, 50 * game->ratio});
    sfSprite_setOrigin(game->game_loop->peashooter_s,
    (sfVector2f){50 * game->ratio, 50 * game->ratio});
    sfSprite_setOrigin(game->game_loop->cactus_s,
    (sfVector2f){50 * game->ratio, 40 * game->ratio});
    sfSprite_setOrigin(game->game_loop->wallnut_s,
    (sfVector2f){50 * game->ratio, 40 * game->ratio});
}

void create_plants_texture(game_t *game)
{
    game->game_loop->sunflower =
    sfTexture_createFromFile("assets/img/game/sunflower.png", NULL);
    game->game_loop->peashooter =
    sfTexture_createFromFile("assets/img/game/peashooter.png", NULL);
    game->game_loop->cactus =
    sfTexture_createFromFile("assets/img/game/cactus.png", NULL);
    game->game_loop->pea =
    sfTexture_createFromFile("assets/img/game/pea.png", NULL);
    game->game_loop->pick_t =
    sfTexture_createFromFile("assets/img/game/pick.png", NULL);
    game->game_loop->sun =
    sfTexture_createFromFile("assets/img/game/sun.png", NULL);
    game->game_loop->wallnut =
    sfTexture_createFromFile("assets/img/game/wallnut.png", NULL);
}

void create_plants(game_t *game)
{
    create_plants_scale(game);
    create_plants_texture(game);
    create_plants_origins(game);
    sfSprite_setTexture(game->game_loop->sunflower_s,
    game->game_loop->sunflower, sfTrue);
    sfSprite_setTexture(game->game_loop->peashooter_s,
    game->game_loop->peashooter, sfTrue);
    sfSprite_setTexture(game->game_loop->cactus_s,
    game->game_loop->cactus, sfTrue);
    sfSprite_setTexture(game->game_loop->pea_s, game->game_loop->pea, sfTrue);
    sfSprite_setScale(game->game_loop->pea_s,
    (sfVector2f){game->ratio * 1.2, game->ratio * 1.2});
    sfSprite_setTexture(game->game_loop->pick_s,
    game->game_loop->pick_t, sfTrue);
    sfSprite_setTexture(game->game_loop->sun_s, game->game_loop->sun, sfTrue);
    sfSprite_setTexture(game->game_loop->wallnut_s,
    game->game_loop->wallnut, sfTrue);
}