/*
** EPITECH PROJECT, 2021
** move_spikes.c
** File description:
** move spikes
*/

#include "my_runner.h"

int get_spikes_pos(int back)
{
    switch (back) {
    case 1:
        return(3200);
        break;
    case 2:
        return (3600);
        break;
    case 3:
        return (4000);
        break;
    }
}

sfVector2f move_spikes(sfClock *clock_ground, int spikes)
{
    sfTime time = sfClock_getElapsedTime(clock_ground);
    float time_float = sfTime_asSeconds(time);
    int ground_pos = get_spikes_pos(spikes);
    int speed = 430;
    static float x;

    x = get_time(clock_ground, speed, ground_pos);
    while (x < -100) {
        x += 2000;
    }
    sfVector2f position = {x, 715};
    return (position);
}
