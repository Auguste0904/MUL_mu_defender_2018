/*
** EPITECH PROJECT, 2019
** click_game_plants_hud
** File description:
** Action when you click on the plants int the hud
*/

#include "my.h"

void check_drag_cactus(game_t *game, sfVector2f cactus_hud_pos)
{
    game->game_loop->x = sfMouse_getPositionRenderWindow(game->window->wind).x;
    game->game_loop->y = sfMouse_getPositionRenderWindow(game->window->wind).y;
    if (sfMouse_isButtonPressed(sfMouseLeft) && !game->game_loop->drag &&
    game->game_loop->x >= cactus_hud_pos.x &&
    game->game_loop->x <= cactus_hud_pos.x + 75 * game->ratio &&
    game->game_loop->y >= cactus_hud_pos.y &&
    game->game_loop->y <= cactus_hud_pos.y + 108 * game->ratio &&
    game->game_loop->nb_price >= 150) {
        game->game_loop->drag = 4;
        sfMusic_play(game->game_loop->pick);
    }
}

int check_drop_cactus(game_t *game, cactus_t *cactus)
{
    game->game_loop->drag = 0;
    if (game->game_loop->y < 200 * game->ratio ||
    game->game_loop->y > 975 * game->ratio ||
    game->game_loop->x < 325 * game->ratio ||
    game->game_loop->x > 1525 * game->ratio) {
        return (0);
    }
    change_display_price(game, game->game_loop->nb_price -= 150);
    if (game->cactus == NULL) {
        game->cactus = create_cactus((sfVector2f)
        {game->game_loop->x, game->game_loop->y});
    } else {
        while (cactus->next)
            cactus = cactus->next;
        cactus->next = create_cactus((sfVector2f)
        {game->game_loop->x, game->game_loop->y});
    }
    sfMusic_play(game->game_loop->drop);
    return (0);
}

void click_cactus_hud(game_t *game)
{
    cactus_t *cactus = game->cactus;
    sfVector2f cactus_hud_pos =
    sfSprite_getPosition(game->game_loop->cactus_hud_s);

    check_drag_cactus(game, cactus_hud_pos);
    if (game->game_loop->drag == 4 &&
    game->window->event.type == sfEvtMouseButtonReleased &&
    game->window->event.mouseButton.button == sfMouseLeft &&
    !(game->game_loop->x >= cactus_hud_pos.x &&
    game->game_loop->x <= cactus_hud_pos.x + 75 * game->ratio &&
    game->game_loop->y >= cactus_hud_pos.y &&
    game->game_loop->y <= cactus_hud_pos.y + 108 * game->ratio)) {
        check_drop_cactus(game, cactus);
    }
}
