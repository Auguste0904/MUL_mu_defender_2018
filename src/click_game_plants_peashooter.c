/*
** EPITECH PROJECT, 2019
** click_game_plants_hud
** File description:
** Action when you click on the plants int the hud
*/

#include "my.h"

void check_drag_peashooter(game_t *game, sfVector2f pea_hud_pos)
{
    game->game_loop->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->game_loop->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    if (sfMouse_isButtonPressed(sfMouseLeft) && !game->game_loop->drag &&
    game->game_loop->x >= pea_hud_pos.x &&
    game->game_loop->x <= pea_hud_pos.x + 75 * game->ratio &&
    game->game_loop->y >= pea_hud_pos.y &&
    game->game_loop->y <= pea_hud_pos.y + 108 * game->ratio &&
    game->game_loop->nb_price >= 100) {
        game->game_loop->drag = 2;
        sfMusic_play(game->game_loop->pick);
    }
}

int check_drop_peashooter(game_t *game, peashooter_t *peashooter)
{
    game->game_loop->drag = 0;
    if (game->game_loop->y < 200 * game->ratio ||
    game->game_loop->y > 975 * game->ratio ||
    game->game_loop->x < 325 * game->ratio ||
    game->game_loop->x > 1525 * game->ratio) {
        return (0);
    }
    change_display_price(game, game->game_loop->nb_price -= 100);
    if (game->peashooter == NULL) {
        game->peashooter = create_peashooter((sfVector2f)
        {game->game_loop->x, game->game_loop->y});
    } else {
        while (peashooter->next)
            peashooter = peashooter->next;
        peashooter->next = create_peashooter((sfVector2f)
        {game->game_loop->x, game->game_loop->y});
    }
    sfMusic_play(game->game_loop->drop);
    return (0);
}

void click_peashooter_hud(game_t *game)
{
    peashooter_t *peashooter = game->peashooter;
    sfVector2f pea_hud_pos =
    sfSprite_getPosition(game->game_loop->green_flo_hud_s);

    check_drag_peashooter(game, pea_hud_pos);
    if (game->game_loop->drag == 2 &&
    game->window->event.type == sfEvtMouseButtonReleased &&
    game->window->event.mouseButton.button == sfMouseLeft &&
    !(game->game_loop->x >= pea_hud_pos.x &&
    game->game_loop->x <= pea_hud_pos.x + 75 * game->ratio &&
    game->game_loop->y >= pea_hud_pos.y &&
    game->game_loop->y <= pea_hud_pos.y + 108 * game->ratio)) {
        check_drop_peashooter(game, peashooter);
    }
}
