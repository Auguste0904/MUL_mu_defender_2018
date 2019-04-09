/*
** EPITECH PROJECT, 2019
** click_game_plants_hud
** File description:
** Action when you click on the plants int the hud
*/

#include "my.h"

void check_drag_wallnut(game_t *game, sfVector2f wallnut_hud_pos)
{
    game->game_loop->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->game_loop->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    if (sfMouse_isButtonPressed(sfMouseLeft) && !game->game_loop->drag &&
    game->game_loop->x >= wallnut_hud_pos.x &&
    game->game_loop->x <= wallnut_hud_pos.x + 75 * game->ratio &&
    game->game_loop->y >= wallnut_hud_pos.y &&
    game->game_loop->y <= wallnut_hud_pos.y + 108 * game->ratio &&
    game->game_loop->nb_price >= 50) {
        game->game_loop->drag = 3;
        sfMusic_play(game->game_loop->pick);
    }
}

int check_drop_wallnut(game_t *game, wallnut_t *wallnut)
{
    game->game_loop->drag = 0;
    if (game->game_loop->y < 200 * game->ratio ||
    game->game_loop->y > 975 * game->ratio ||
    game->game_loop->x < 325 * game->ratio ||
    game->game_loop->x > 1525 * game->ratio) {
        return (0);
    }
    change_display_price(game, game->game_loop->nb_price -= 50);
    if (game->wallnut == NULL) {
        game->wallnut = create_wallnut((sfVector2f)
        {game->game_loop->x, game->game_loop->y});
    } else {
        while (wallnut->next)
            wallnut = wallnut->next;
        wallnut->next = create_wallnut((sfVector2f)
        {game->game_loop->x, game->game_loop->y});
    }
    sfMusic_play(game->game_loop->drop);
    return (0);
}

void click_wallnut_hud(game_t *game)
{
    wallnut_t *wallnut = game->wallnut;
    sfVector2f wallnut_hud_pos =
    sfSprite_getPosition(game->game_loop->wallnut_hud_s);

    check_drag_wallnut(game, wallnut_hud_pos);
    if (game->game_loop->drag == 3 &&
    game->window->event.type == sfEvtMouseButtonReleased &&
    game->window->event.mouseButton.button == sfMouseLeft &&
    !(game->game_loop->x >= wallnut_hud_pos.x &&
    game->game_loop->x <= wallnut_hud_pos.x + 75 * game->ratio &&
    game->game_loop->y >= wallnut_hud_pos.y &&
    game->game_loop->y <= wallnut_hud_pos.y + 108 * game->ratio)) {
        check_drop_wallnut(game, wallnut);
    }
}
