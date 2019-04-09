/*
** EPITECH PROJECT, 2019
** create_game_loop
** File description:
** Creates for the game loop
*/

#include "my.h"

void create_map_game_loop(game_t *game)
{
    char *random = my_strdup("assets/img/map1.png");

    random[14] = (rand() % 3 + 1) + '0';
    game->game_loop->back_s = sfSprite_create();
    game->game_loop->back =
    sfTexture_createFromFile(random, NULL);
    free(random);
    sfSprite_setTexture(game->game_loop->back_s,
    game->game_loop->back, sfTrue);
    sfSprite_setOrigin(game->game_loop->back_s,
    (sfVector2f){1270, 690});
    sfSprite_setScale(game->game_loop->back_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setPosition(game->game_loop->back_s,
    (sfVector2f){-855 * game->ratio + 1270 * game->ratio, 690 * game->ratio});
    game->game_loop->anim = sfClock_create();
}

void create_hud(game_t *game)
{
    game->game_loop->hud_s = sfSprite_create();
    game->game_loop->hud =
    sfTexture_createFromFile("assets/img/game/int1.png", NULL);
    sfSprite_setTexture(game->game_loop->hud_s, game->game_loop->hud, sfTrue);
    game->game_loop->zombie_s = sfSprite_create();
    game->game_loop->zombie =
    sfTexture_createFromFile("assets/img/game/zombie.png", NULL);
    sfSprite_setTexture(game->game_loop->zombie_s,
    game->game_loop->zombie, sfTrue);
    sfSprite_setTextureRect(game->game_loop->zombie_s,
    (sfIntRect){0, 0, 150, 200});
    sfSprite_setScale(game->game_loop->zombie_s,
    (sfVector2f){game->ratio, game->ratio});
    sfSprite_setScale(game->game_loop->hud_s,
    (sfVector2f){2.3 * game->ratio, 2.3 * game->ratio});
    sfSprite_setColor(game->game_loop->hud_s,
    sfColor_fromRGBA(255, 255, 255, 0));
    game->score = 0;
}

void create_music_game_loop(game_t *game)
{
    game->game_loop->music =
    sfMusic_createFromFile("assets/sound/grasswalk.ogg");
    game->game_loop->pick =
    sfMusic_createFromFile("assets/sound/seedlift.ogg");
    game->game_loop->drop =
    sfMusic_createFromFile("assets/sound/dirt_rise.ogg");
    game->game_loop->chomp =
    sfMusic_createFromFile("assets/sound/chomp.ogg");
    game->game_loop->awooga =
    sfMusic_createFromFile("assets/sound/awooga.ogg");
    game->game_loop->peashot =
    sfMusic_createFromFile("assets/sound/kernelpult.ogg");
    game->game_loop->points =
    sfMusic_createFromFile("assets/sound/points.ogg");
    game->game_loop->lose =
    sfMusic_createFromFile("assets/sound/losemusic.ogg");
}

void create_game_loop(game_t *game)
{
    create_map_game_loop(game);
    create_hud(game);
    create_music_game_loop(game);
    game->game_loop->scream =
    sfMusic_createFromFile("assets/sound/scream.ogg");
    game->game_loop->view = sfView_createFromRect((sfFloatRect)
    {0, 0, 1920 * game->ratio, 1080 * game->ratio});
    sfRenderWindow_setView(game->window->wind, game->game_loop->view);
    game->game = 0;
    game->peashooter = NULL;
    game->pea = NULL;
    game->zombie = NULL;
    game->sunflower = NULL;
}
