/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

void create_music(game_t *game)
{
    game->main_menu->music =
    sfMusic_createFromFile("assets/sound/music.ogg");
    game->main_menu->dave_sound =
    sfMusic_createFromFile("assets/sound/crazydavecrazy.ogg");
    game->main_menu->boom =
    sfMusic_createFromFile("assets/sound/balloon.ogg");
    game->button_click =
    sfMusic_createFromFile("assets/sound/buttonclick.ogg");
    sfMusic_play(game->main_menu->music);
    sfMusic_setLoop(game->main_menu->music, sfTrue);
}

void malloc_struct(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->main_menu = malloc(sizeof(main_menu_t));
    game->set_menu = malloc(sizeof(set_menu_t));
    game->game_loop = malloc(sizeof(game_loop_t));
}

void free_struct(game_t *game)
{
    free(game->window);
    free(game->main_menu);
    free(game->game_loop);
    free(game->set_menu);
    free(game);
}

void create_main(game_t *game)
{
    create_music(game);
    create_fade(game);
    create_set_menu(game);
}

int main(int ac, char **av, char **env)
{
    game_t *game = malloc(sizeof(game_t));

    if (!env[0])
        return (84);
    malloc_struct(game);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (display_help());
    if (ac == 1) {
        game->ratio = 1;
        game->window->wind = sfRenderWindow_create((sfVideoMode)
        {1920 * game->ratio, 1080 * game->ratio, 32}, "My_defender",
        sfClose, NULL);
        sfRenderWindow_setFramerateLimit(game->window->wind, 60);
        create_main(game);
        main_menu(game);
        all_destroy(game);
    }
    free_struct(game);
    return (0);
}
