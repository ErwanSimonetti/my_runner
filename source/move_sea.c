/*
** EPITECH PROJECT, 2021
** move_sea.c
** File description:
** move three layers of sea at the same time
*/

#include "my_runner.h"

int get_sea_pos(int sea)
{
    switch (sea) {
    case 1:
        return(0);
        break;
    case 2:
        return (1050);
        break;
    case 3:
        return (2100);
        break;
    }
}

int get_new_pos(int pos, int speed)
{
    switch (pos) {
    case 0:
        if (speed == 100 | speed == 250)
            return(275);
        else
            return (550);
        break;
    case 1050:
        return (1325);
        break;
    case 2100:
        return (2375);
        break;
    case 959:
        return (1510);
        break;
    case 1918:
        return (2470);
        break;
    case 1:
        return (63);
        break;
    case 955:
        return (1017);
        break;
    case 1910:
        return (1972);
        break;
    default:
        return (pos);
        break;
    }
}

float get_time(sfClock *clock_move, int speed, int pos)
{
    sfTime time;
    float time_float;
    float x;
    static int has_walked = 0;
    int new_pos = get_new_pos(pos, speed);

    time = sfClock_getElapsedTime(clock_move);
    time_float = sfTime_asSeconds(time);
    if (time_float >= 1.8 && has_walked == 0)
        has_walked = 1;
    if (has_walked == 0)
        x = pos - speed * time_float;
    else
        x = new_pos - speed * time_float;
    return (x);
}

static int has_waited_sea(sfClock *clock)
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

sfVector2f move_sea(sfClock *clock_back, int sea)
{
    sfTime time = sfClock_getElapsedTime(clock_back);
    float time_float = sfTime_asSeconds(time);
    int sea_pos = get_sea_pos(sea);
    static int has_walked = 0;
    int speed;
    static float x;

    if (has_walked == 0)
        speed = 100;
    if (time_float > 1.8 || has_walked == 1) {
        has_walked = 1;
        speed = 250;
    }
    if (has_waited_sea(clock_back) == 1)
        x = get_time(clock_back, speed, sea_pos);
    else
        x = sea_pos;
    while (x < -1050) {
        x += 3150;
    }
    sfVector2f position = {x, 0};
    return (position);
}
