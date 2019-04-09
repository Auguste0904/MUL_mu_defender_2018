/*
** EPITECH PROJECT, 2019
** display_plants
** File description:
** Display plants functions
*/

#include "my.h"

void display_sunflower(game_t *game)
{
    sunflower_t *sunflower = game->sunflower;

    while (sunflower != NULL) {
        sfSprite_setPosition(game->game_loop->sunflower_s, sunflower->pos);
        sfSprite_setTextureRect(game->game_loop->sunflower_s,
        sunflower->sheet);
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->sunflower_s, NULL);
        sunflower = sunflower->next;
    }
}

void display_peashooter(game_t *game)
{
    peashooter_t *peashooter = game->peashooter;

    while (peashooter != NULL) {
        sfSprite_setPosition(game->game_loop->peashooter_s, peashooter->pos);
        sfSprite_setTextureRect(game->game_loop->peashooter_s,
        peashooter->sheet);
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->peashooter_s, NULL);
        peashooter = peashooter->next;
    }
}

void display_cactus(game_t *game)
{
    cactus_t *cactus = game->cactus;

    while (cactus != NULL) {
        sfSprite_setPosition(game->game_loop->cactus_s, cactus->pos);
        sfSprite_setTextureRect(game->game_loop->cactus_s, cactus->sheet);
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->cactus_s, NULL);
        cactus = cactus->next;
    }
}

void display_wallnut(game_t *game)
{
    wallnut_t *wallnut = game->wallnut;

    while (wallnut != NULL) {
        sfSprite_setPosition(game->game_loop->wallnut_s, wallnut->pos);
        sfSprite_setTextureRect(game->game_loop->wallnut_s, wallnut->sheet);
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->wallnut_s, NULL);
        wallnut = wallnut->next;
    }
}

void display_zombie(game_t *game)
{
    zombie_t *zombie = game->zombie;

    while (zombie != NULL) {
        sfSprite_setPosition(game->game_loop->zombie_s, zombie->pos);
        sfSprite_setTextureRect(game->game_loop->zombie_s, zombie->sheet);
        sfRenderWindow_drawSprite(game->window->wind,
        game->game_loop->zombie_s, NULL);
        zombie = zombie->next;
    }
}