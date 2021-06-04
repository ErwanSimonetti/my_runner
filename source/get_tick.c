/*
** EPITECH PROJECT, 2021
** get_one_tick.c
** File description:
** using a clock
*/

#include "my_runner.h"

int get_tick (sfClock *clock)
{
    sfTime time;
    float time_float;

    time = sfClock_getElapsedTime(clock);
    time_float = sfTime_asSeconds(time);
    if (time_float < 0.1)
        return (1);
    else if (time_float < 0.2)
        return (2);
    else if (time_float < 0.3)
        return (3);
    else if (time_float < 0.4)
        return (4);
    else {
        sfClock_restart(clock);
        return (-1);
    }
}
