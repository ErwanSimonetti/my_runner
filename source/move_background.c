/*
** EPITECH PROJECT, 2021
** move_background.c
** File description:
** for parallax
*/

#include "my_runner.h"

int get_back_pos(int back)
{
    switch (back) {
    case 1:
        return(1);
        break;
    case 2:
        return (955);
        break;
    case 3:
        return (1910);
        break;
    }
}

static int has_waited_bg(sfClock *clock)
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

sfVector2f move_background(sfClock *clock_back, int back)
{
    sfTime time = sfClock_getElapsedTime(clock_back);
    float time_float = sfTime_asSeconds(time);
    int back_pos = get_back_pos(back);
    static int has_walked = 0;
    int speed;
    static float x;

    if (has_walked == 0)
        speed = 30;
    if (time_float > 1.8 || has_walked == 1) {
        has_walked = 1;
        speed = 65;
    }
    if (has_waited_bg(clock_back) == 1)
        x = get_time(clock_back, speed, back_pos);
    else
        x = back_pos;
    while (x < -955) {
        x += 2865;
    }
    sfVector2f position = {x, 0};
    return (position);
}
