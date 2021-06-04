/*
** EPITECH PROJECT, 2020
** 102_architect.h
** File description:
** header
*/

#include <unistd.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <stdlib.h>
#include <time.h>

//lib
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str);
int print_error_msg(char const *str);

//menu
int do_menu(void);
sfSprite *set_background_image(void);
sfSprite *set_text_image(void);
void animate_text(sfSprite *text_sprite, sfClock *clock);

//runner
int do_my_runner(sfRenderWindow *win);
static sfTexture *walk(int semi_seconds);
sfSprite *set_background_1(sfClock *clock_anim, sfClock *clock_back, int death);
sfSprite *set_background_2(sfClock *clock_anim, sfClock *clock_back, int death);
sfSprite *set_background_3(sfClock *clock_anim, sfClock *clock_back, int death);
sfSprite *set_sea_1(sfClock *clock, sfClock *clock_move, int death);
sfSprite *set_sea_2(sfClock *clock_anim, sfClock *clock_move, int death);
sfSprite *set_sea_3(sfClock *clock_anim, sfClock *clock_move, int death);
sfVector2f move_sea(sfClock *clock_move, int sea);
sfVector2f move_background(sfClock *clock_back, int back);
sfVector2f move_ground(sfClock *clock_ground, int ground);
sfVector2f move_spikes(sfClock *clock_ground, int spikes);

sfSprite *set_ground_1(sfClock *clock, int death);
sfSprite *set_ground_2(sfClock *clock, int death);
sfSprite *set_ground_3(sfClock *clock, int death);
sfSprite *set_spikes_1(sfClock *clock, int death);
sfSprite *set_spikes_2(sfClock *clock, int death);
sfSprite *set_spikes_3(sfClock *clock, int death);
sfSprite *set_sonic_sprite(sfClock *clock_move);
void draw_all_sprites(sfRenderWindow *win, sfClock *clock_anim, sfClock *clock_move,
                      sfClock *clock_sea, sfClock *clock_back, sfClock *clock_ground,
                      int death);
int draw_spikes(sfRenderWindow *win, sfClock *clock, sfSprite *sonic, int death);
sfTexture *animate_tile_2(int tick);
sfTexture *animate_sea(int tick);
int death_animation(sfRenderWindow *win, int death, sfClock *clock_death, sfSprite *sonic);
float get_time(sfClock *clock_move, int speed, int pos);
int get_tick (sfClock *clock);
int get_movement_tick (sfClock *clock);
static int has_waited(sfClock *clock);
static int has_waited_bg(sfClock *clock);
int jump(sfSprite *sonic, sfClock *clock_jump);

//both
sfMusic *play_background_music(char *title);

//description
int print_description(void);

//game_over
void destroy_clocks (sfClock *clock_a, sfClock *clock_m, sfClock *clock_s,
                     sfClock *clock_b, sfClock *clock_g, sfClock *clock_j,
                     sfClock *clock_d);
void destroy_musics (sfMusic *ost, sfMusic *jump);
