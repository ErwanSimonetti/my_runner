/*
** EPITECH PROJECT, 2021
** get_movement_tick.c
** File description:
** synchronise anim & movement
*/

#include "my_runner.h"

static int has_waited(sfClock *clock)
{
    static int has_waited = 0;
    sfTime time;
    float time_float;

    time = sfClock_getElapsedTime(clock);
    time_float = sfTime_asSeconds(time);
    if (time_float > 1.25)
        has_waited = 1;
    return (has_waited);
}

int get_movement_tick(sfClock *clock)
{
    sfTime time;
    float time_float;
    static int tick = 0;
    int wait = has_waited(clock);
    static int has_walked = 0;
    static int times_walked = 0;

    time = sfClock_getElapsedTime(clock);
    time_float = sfTime_asSeconds(time);
    if (time_float > 0.1 && wait == 1 && has_walked == 0) {
        tick += 1;
        sfClock_restart(clock);
    }
    if (time_float > 0.05 && has_walked == 1) {
        tick += 1;
        sfClock_restart(clock);
    }
    if (tick > 6 && has_walked == 0) {
        tick = 1;
        times_walked += 1;
    }
    if (tick > 10 && has_walked == 1) {
        tick = 7;
    }
    if (times_walked == 2)
        has_walked = 1;
    return (tick);
}
