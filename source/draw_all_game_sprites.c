/*
** EPITECH PROJECT, 2021
** draw_all_game_sprites.c
** File description:
** display all sprites
*/

#include "my_runner.h"

void draw_sea_sprites(sfRenderWindow *win, sfClock *clock_anim, sfClock *clock_back,
    int death)
{
    sfSprite *sea_1 = set_sea_1(clock_anim, clock_back, death);
    sfSprite *sea_2 = set_sea_2(clock_anim, clock_back, death);
    sfSprite *sea_3 = set_sea_3(clock_anim, clock_back, death);

    sfRenderWindow_drawSprite(win, sea_1, NULL);
    sfRenderWindow_drawSprite(win, sea_2, NULL);
    sfRenderWindow_drawSprite(win, sea_3, NULL);
}

void draw_background_sprites(sfRenderWindow *win, sfClock *clock_anim, sfClock *clock_back,
    int death)
{
    sfSprite *back_sprite_1 = set_background_1(clock_anim, clock_back, death);
    sfSprite *back_sprite_2 = set_background_2(clock_anim, clock_back, death);
    sfSprite *back_sprite_3 = set_background_3(clock_anim, clock_back, death);

    sfRenderWindow_drawSprite(win, back_sprite_1, NULL);
    sfRenderWindow_drawSprite(win, back_sprite_2, NULL);
    sfRenderWindow_drawSprite(win, back_sprite_3, NULL);
}

void draw_ground(sfRenderWindow *win, sfClock *clock, int death)
{
    sfSprite *ground_1 = set_ground_1(clock, death);
    sfSprite *ground_2 = set_ground_2(clock, death);
    sfSprite *ground_3 = set_ground_3(clock, death);

    sfRenderWindow_drawSprite(win, ground_1, NULL);
    sfRenderWindow_drawSprite(win, ground_2, NULL);
    sfRenderWindow_drawSprite(win, ground_3, NULL);
}

void draw_all_sprites(sfRenderWindow *win, sfClock *clock_anim, sfClock *clock_move,
                      sfClock *clock_sea, sfClock *clock_back, sfClock *clock_ground, 
    int death)
{
    draw_sea_sprites(win, clock_anim, clock_sea, death);
    draw_background_sprites(win, clock_anim, clock_back, death);
    draw_ground(win, clock_ground, death);
}
