/*
** EPITECH PROJECT, 2021
** jump.c
** File description:
** make sonic jump
*/

#include "my_runner.h"

static sfTexture *animate_jump(int tick)
{
    sfTexture *current;

    switch (tick) {
    case 1:
        current = sfTexture_createFromFile("textures/sonic/jump_1.png", NULL);
        break;
    case 2:
        current= sfTexture_createFromFile("textures/sonic/jump_2.png", NULL);
        break;
    case 3:
        current= sfTexture_createFromFile("textures/sonic/jump_3.png", NULL);
        break;
    case 4:
        current= sfTexture_createFromFile("textures/sonic/jump_4.png", NULL);
        break;
    case 5:
        current= sfTexture_createFromFile("textures/sonic/jump_5.png", NULL);
        break;
        
    }
}

int get_jump_tick(float time_float, int is_falling, int is_midair)
{
    int tick = 1;
    int times_0_5 = 1;

    while (0.025 * times_0_5 <= time_float) {
        times_0_5 += 1;
        tick += 1;
        if (tick == 6)
            tick = 1;
    }
    return (tick);
}

int jump(sfSprite *sonic, sfClock *clock_jump)
{
    int tick_jump;
    sfTime time;
    float time_float = 0;
    sfTexture *sonic_jump;
    float y;
    static int is_falling = 0;
    static int is_midair = 0;

    time = sfClock_getElapsedTime(clock_jump);
    time_float = sfTime_asSeconds(time);
    tick_jump = get_jump_tick(time_float, is_falling, is_midair);
    sonic_jump = animate_jump(tick_jump);
    sfSprite_setTexture(sonic, sonic_jump, 1);
    if (is_midair == 0 && is_falling == 0)
    y = 585 - (time_float * 1100);
    if (y <= 350 && is_falling == 0) {
        is_midair = 1;
        y = 350;
    }
    if (is_falling == 1)
        y = 350 + (time_float) * 1100;
    if (time_float > 0.50 && is_falling == 0) {
        is_falling = 1;
        sfClock_restart(clock_jump);
    }
    sfVector2f position = {0, y};
    sfSprite_setPosition(sonic, position);
    if (y >= 570 && is_falling == 1) {
        is_falling = 0;
        is_midair = 0;
        sfClock_destroy(clock_jump);
        return (0);
    }
}
