/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** inlcude
*/

#ifndef MY_H_
#define MY_H_

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define HELP ("            You have to plant\n   plants in order to save \
your\n   house from zombies invasion.\nThe suns are the in-game money.\n  \
Different types of plants can\n  help you to protect your brain.")

typedef struct game
{
    int lose;
    int score;
    int zombie_wave;
    int zombie_clock_limit;
    sfClock *zombie_clock;
    int fps;
    int menu;
    int game;
    int pause;
    float ratio;
    sfMusic *button_click;
    sfClock *check_lose;
    struct window *window;
    struct main_menu *main_menu;
    struct set_menu *set_menu;
    struct game_loop *game_loop;
    struct zombie *zombie;
    struct pea *pea;
    struct pick *pick;
    struct sun *sun;
    struct sunflower *sunflower;
    struct peashooter *peashooter;
    struct cactus *cactus;
    struct wallnut *wallnut;
}game_t;

typedef struct sun
{
    sfVector2f pos;
    sfVector2f speed;
    float floor;
    sfClock *ghost;
    int alpha;
    struct sun *next;
}sun_t;

typedef struct sunflower
{
    int health;
    sfVector2f pos;
    sfIntRect sheet;
    sfClock *anim;
    sfClock *sun;
    struct sunflower *next;
}sunflower_t;

typedef struct peashooter
{
    int health;
    sfVector2f pos;
    sfIntRect sheet;
    sfClock *anim;
    sfClock *attack;
    struct peashooter *next;
}peashooter_t;

typedef struct cactus
{
    int health;
    sfVector2f pos;
    sfIntRect sheet;
    sfClock *anim;
    sfClock *attack;
    struct cactus *next;
}cactus_t;

typedef struct pick
{
    int damage;
    sfVector2f pos;
    struct pick *next;
}pick_t;

typedef struct pea
{
    int damage;
    sfVector2f pos;
    struct pea *next;
}pea_t;

typedef struct wallnut
{
    int health;
    sfVector2f pos;
    sfIntRect sheet;
    sfClock *anim;
    struct wallnut *next;
}wallnut_t;

typedef struct zombie
{
    int damage;
    int health;
    sfVector2f pos;
    sfIntRect sheet;
    sfClock *anim;
    sfClock *attack;
    struct zombie *next;
}zombie_t;

typedef struct window
{
    sfRenderWindow *wind;
    sfEvent event;
    int escape_pressed;
    int click_pressed;
}window_t;

typedef struct main_menu
{
    int display_dave;
    int x;
    int y;
    sfMusic *dave_sound;
    sfClock *dave_clock;
    sfRectangleShape *fade;
    sfClock *fade_clock;
    sfText *dave_text;
    sfText *settings;
    sfText *help;
    sfText *quit;
    sfFont *font;
    sfMusic *music;
    sfMusic *boom;
    sfSprite *back_s;
    sfTexture *back;
    sfSprite *logo_s;
    sfTexture *logo;
    sfSprite *tombstone_s;
    sfTexture *tombstone;
    sfSprite *tree_s;
    sfTexture *tree;
    sfSprite *house_s;
    sfTexture *house;
    sfSprite *grass_s;
    sfTexture *grass;
    sfSprite *snail_s;
    sfTexture *snail;
    sfClock *snail_clock;
    sfSprite *zombie_s;
    sfSprite *play_s;
    sfTexture *play;
    sfSprite *play_2_s;
    sfTexture *play_2;
    sfTexture *zombie;
    sfSprite *balloon_s;
    sfTexture *balloon;
    sfSprite *dave_s;
    sfTexture *dave;
    sfSprite *bubble_s;
    sfTexture *bubble;
    sfClock *zombie_clock;
}main_menu_t;

typedef struct set_menu
{
    int fullscreen;
    sfFont *set_font;
    sfText *back;
    sfText *window1;
    sfText *window2;
    sfText *window3;
    sfSprite *tab_s;
    sfTexture *tab;
    sfSprite *valide_but_s;
    sfTexture *valide_but;
}set_menu_t;

typedef struct game_loop
{
    int x;
    int y;
    int drag;
    int nb_price;
    sfSprite *ready_s;
    sfTexture *ready;
    sfSprite *zombiewon_s;
    sfTexture *zombiewon;
    sfRectangleShape *black_fade;
    sfSprite *set_s;
    sfTexture *set;
    sfSprite *play_s;
    sfTexture *play;
    sfClock *sun_move;
    sfClock *bullet_move;
    sfClock *bullet2_move;
    sfClock *enemy_move;
    sfClock *game_sun;
    sfView *view;
    sfClock *anim;
    sfMusic *music;
    sfMusic *pick;
    sfMusic *drop;
    sfMusic *chomp;
    sfMusic *awooga;
    sfMusic *peashot;
    sfMusic *points;
    sfMusic *lose;
    sfMusic *scream;
    sfSprite *back_s;
    sfTexture *back;
    sfSprite *hud_s;
    sfTexture *hud;
    sfSprite *zombie_s;
    sfTexture *zombie;
    sfSprite *sunflower_s;
    sfTexture *sunflower;
    sfSprite *pea_s;
    sfTexture *pea;
    sfSprite *peashooter_s;
    sfTexture *peashooter;
    sfSprite *cactus_s;
    sfTexture *cactus;
    sfSprite *pick_s;
    sfTexture *pick_t;
    sfSprite *sun_s;
    sfTexture *sun;
    sfSprite *green_flo_hud_s;
    sfTexture *green_flo_hud;
    sfSprite *sunflower_hud_s;
    sfTexture *sunflower_hud;
    sfSprite *wallnut_hud_s;
    sfTexture *wallnut_hud;
    sfSprite *cactus_hud_s;
    sfTexture *cactus_hud;
    sfSprite *wallnut_s;
    sfTexture *wallnut;
    sfSprite *pause_s;
    sfTexture *pause;
    sfText *resume;
    sfText *menu;
    sfText *quit;
    sfText *price;
}game_loop_t;

/* Lib functions */
void *my_malloc(size_t size, int fill);
char *my_revstr(char *str);
void my_putchar(char c);
char *my_itoa(int nb);
int my_atoi(char const *str);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strdup(char const *str);
void *my_malloc(size_t size, int fill);
char *my_revstr(char *str);

/* Main menu function */
int display_help(void);
int main_menu(game_t *game);
void manage_snail(game_t *game);
void manage_zombie(game_t *game);
void create_main_menu(game_t *game);
void draw_main_menu(game_t *game);
void change_text_main_menu(game_t *game);
void click_text_menu(game_t *game);
void all_destroy(game_t *game);
void change_button_main_menu(game_t *game);
void click_button_menu(game_t *game);
void shoot_balloon(game_t *game, sfIntRect rect);
void create_fade(game_t *game);
void draw_fade(game_t *game);
void all_destroy(game_t *game);
void all_destroy_2(game_t *game);
void create_dave(game_t *game);
void scale_text(game_t *game);
void create_sprite(game_t *game);
void create_text(game_t *game);
void change_sprite(game_t *game);

/* Settings menu function */
void change_fullscreen(game_t *game, sfVector2f full_pos);
int set_menu(game_t *game);
void draw_set_menu(game_t *game);
void create_set_menu(game_t *game);
void change_text_set_menu(game_t *game);
void click_text_set_menu(game_t *game);
void scale_resize(game_t *game);

/* Game loop functions */
int game_loop(game_t *game);
void event_close(game_t *game, int *close);
void create_game_loop(game_t *game);
void intro_deccelerate(game_t *game, int *pause, float *speed, float *zoom);
void intro_accelerate(game_t *game, int *pause, float *speed, float *zoom);
void intro_draw(game_t *game, int zombpo[4]);
void intro_anim_clock(game_t *game, int *pause);
void create_sprite_hud(game_t *game);
void draw_intro2(game_t *game, int alpha);
void draw_game_loop(game_t *game);
void create_plants(game_t *game);
void destroy_game_loop(game_t *game);
void change_sprite_game_play(game_t *game);
void move_rect_zombie(zombie_t *zombie);
void click_sunflower_hud(game_t *game);
void move_rect_sunflower(sunflower_t *sunflower);
struct zombie *create_zombie(game_t *game);
void display_zombie(game_t *game);
void display_sunflower(game_t *game);
void display_dragndrop(game_t *game);
struct sunflower *create_sunflower(sfVector2f pos);
void create_pause(game_t *game);
void create_text_pause(game_t *game);
void change_text_pause_menu(game_t *game);
void click_text_pause_menu(game_t *game, int *close);
void click_peashooter_hud(game_t *game);
void manage_game_peashooter(game_t *game);
void move_rect_peashooter(peashooter_t *peashooter);
struct peashooter *create_peashooter(sfVector2f pos);
void display_peashooter(game_t *game);
void display_pea(game_t *game);
struct pea *create_pea(sfVector2f pos, int damage);
struct pick *create_pick(sfVector2f pos, int damage);
void create_text_price(game_t *game);
void damage_plant(game_t *game, peashooter_t *peashooter, zombie_t *zombie);
void eat_rect_zombie(zombie_t *zombie);
void create_intro(game_t *game);
void create_outro(game_t *game);
void damage_plant2(game_t *game, sunflower_t *sunflower, zombie_t *zombie);
void display_sun(game_t *game);
struct sun *create_sun(sfVector2f pos, sfVector2f speed, float floor);
struct wallnut *create_wallnut(sfVector2f pos);
struct cactus *create_cactus(sfVector2f pos);
void move_rect_wallnut(wallnut_t *wallnut);
void move_rect_cactus(cactus_t *cactus);
void click_wallnut_hud(game_t *game);
void display_wallnut(game_t *game);
void display_cactus(game_t *game);
void display_pick(game_t *game);
void damage_plant3(game_t *game, wallnut_t *wallnut, zombie_t *zombie);
void damage_plant4(game_t *game, cactus_t *cactus, zombie_t *zombie);
void click_cactus_hud(game_t *game);
void change_display_price(game_t *game, int nb);
sfVector2f create_pos(sfVector2f pos);
void dave_appears(game_t *game, int initialize);
void close_end(game_t *game, int *close);
void game_intro(game_t *game, int *close);
void manage_zombie_peashooter(game_t *game, zombie_t *zombie, int *can_move);
void manage_game_zombie(game_t *game);
void game_intro2(game_t *game, int *close);
void damage_zombie2(game_t *game, zombie_t *zombie, pick_t *pick);
void damage_zombie(game_t *game, zombie_t *zombie, pea_t *pea);
void destroy_pea(game_t *game, pea_t *pea);
void destroy_pick(game_t *game, pick_t *pick);
void manage_move_zombie(game_t *game, int can_move, zombie_t *zombie);
void damage_zombie12(game_t *game, zombie_t *zombie, zombie_t *tmp1);
void damage_sunflower12(game_t *game, sunflower_t *sunflower, sunflower_t *tmp1);
void damage_plant13(game_t *game, wallnut_t *wallnut, wallnut_t *tmp1);
void damage_plant10(game_t *game, peashooter_t *wallnut, peashooter_t *tmp1);
void damage_plant14(game_t *game, cactus_t *wallnut, cactus_t *tmp1);
void manage_pick_zombie(game_t *game, pick_t *pick);
void check_plant13(wallnut_t *wallnut, wallnut_t *tmp1);
void check_plant10(peashooter_t *wallnut, peashooter_t *tmp1);
void check_plant14(cactus_t *wallnut, cactus_t *tmp1);
void manage_pea_zombie(game_t *game, pea_t *pea);
void manage_game_pea(game_t *game);
void manage_game_peashooter(game_t *game);
void manage_game_pick(game_t *game);
void destroy_sun(game_t *game, sun_t *sun);
void check_pea_damage(game_t *game, zombie_t *zombie, pea_t *pea);
void manage_game_sun(game_t *game);
void manage_game_sunflower(game_t *game);
void manage_game_wallnut(game_t *game);
void manage_zombie_wave(game_t *game);
void manage_game_cactus(game_t *game);
void game_end(game_t *game, int *close);

#endif
