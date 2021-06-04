/*
** EPITECH PROJECT, 2021
** death.c
** File description:
** death_animation
*/

#include "my_runner.h"

void set_death_texture(sfSprite *sonic)
{
    sfTexture *sonic_death =
        sfTexture_createFromFile("textures/sonic/die.png", NULL);

    sfSprite_setTexture(sonic, sonic_death, 1);
}

int death_animation(sfRenderWindow *win, int death, sfClock *clock_death, sfSprite *sonic)
{
    sfMusic *death_sound = sfMusic_createFromFile("sounds/death.wav");
    sfTime time_death;
    float time_float;
    float y;
    static int is_falling = 0;
    static int is_midair = 0;

    if (death == 0) {
        sfMusic_play(death_sound);
        set_death_texture(sonic);
    }
    else {
        time_death = sfClock_getElapsedTime(clock_death);
        time_float = sfTime_asSeconds(time_death);
    }
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
        sfClock_restart(clock_death);
    }
    sfVector2f position = {0, y};
    sfSprite_setPosition(sonic, position);
    if (y >= 1300 && is_falling == 1) {
        is_falling = 0;
        is_midair = 0;
        return (1);
    } else
        return (0);
}
