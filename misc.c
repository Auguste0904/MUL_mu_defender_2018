/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

void change_display_price(game_t *game, int nb)
{
    char *str = my_itoa(nb);

    sfText_setString(game->game_loop->price, str);
    free(str);
}
