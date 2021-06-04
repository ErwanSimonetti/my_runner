/*
** EPITECH PROJECT, 2021
** game_over.c
** File description:
** display game over screen
*/

#include "my_runner.h"

void destroy_clocks (sfClock *clock_a, sfClock *clock_m, sfClock *clock_s,
                     sfClock *clock_b, sfClock *clock_g, sfClock *clock_j,
                     sfClock *clock_d)
{
    sfClock_destroy(clock_a);
    sfClock_destroy(clock_m);
    sfClock_destroy(clock_s);
    sfClock_destroy(clock_b);
    sfClock_destroy(clock_g);
    sfClock_destroy(clock_j);
    sfClock_destroy(clock_d);
}

void destroy_musics (sfMusic *ost, sfMusic *jump)
{
    sfMusic_destroy(ost);
    sfMusic_destroy(jump);
}
