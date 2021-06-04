/*
** EPITECH PROJECT, 2021
** move_ground.c
** File description:
** move ground and loop it
*/

#include "my_runner.h"

int get_ground_pos(int back)
{
    switch (back) {
    case 1:
        return(0);
        break;
    case 2:
        return (959);
        break;
    case 3:
        return (1918);
        break;
    }
}

static int has_waited_g(sfClock *clock)
{
    static int has_waited = 0;
    sfTime time;
    float time_float;

    time = sfClock_getElapsedTime(clock);
    time_float = sfTime_asSeconds(time);
    if (time_float > 1.25 && has_waited == 0) {
        has_waited = 1;
        sfClock_restart(clock);
    }
    return (has_waited);
}

sfVector2f move_ground(sfClock *clock_ground, int ground)
{
    sfTime time = sfClock_getElapsedTime(clock_ground);
    float time_float = sfTime_asSeconds(time);
    int ground_pos = get_ground_pos(ground);
    static int has_walked = 0;
    int speed;
    static float x;

    if (has_walked == 0)
        speed = 200;
    if (time_float > 1.8 || has_walked == 1) {
        has_walked = 1;
        speed = 430;
    }
    if (has_waited_g(clock_ground) == 1)
        x = get_time(clock_ground, speed, ground_pos);
    else
        x = ground_pos;
    while (x < -960) {
        x += 2880;
    }
    sfVector2f position = {x, 70};
    return (position);
}
