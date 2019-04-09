/*
** EPITECH PROJECT, 2019
** manage_price_text
** File description:
** Manage the text of the price
*/

#include "my.h"

void create_text_price(game_t *game)
{
    char *str = NULL;

    game->game_loop->nb_price = 150;
    game->game_loop->price = sfText_create();
    sfText_setFont(game->game_loop->price, game->set_menu->set_font);
    sfText_setString(game->game_loop->price,
    str = my_itoa(game->game_loop->nb_price));
    free(str);
    sfText_setCharacterSize(game->game_loop->price, 30 * game->ratio);
    sfText_setPosition(game->game_loop->price,
    (sfVector2f){58 * game->ratio, 58 * game->ratio});
    sfText_setColor(game->game_loop->price, sfBlack);
}
