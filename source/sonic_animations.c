/*
** EPITECH PROJECT, 2021
** sonic_animations.c
** File description:
** all animations related to sonic
*/

#include "my_runner.h"

static sfTexture *animate_sonic(int tick)
{
    sfTexture *current;
    
    switch (tick) {
    case 0:
        current = sfTexture_createFromFile("textures/sonic/idle.png", NULL);
        break;
    case 1:
        current = sfTexture_createFromFile("textures/sonic/walk_1.png", NULL);
        break;
    case 2:
        current	= sfTexture_createFromFile("textures/sonic/walk_2.png", NULL);
        break;
    case 3:
        current	= sfTexture_createFromFile("textures/sonic/walk_3.png", NULL);
        break;
    case 4:
        current	= sfTexture_createFromFile("textures/sonic/walk_4.png", NULL);
        break;
    case 5:
        current	= sfTexture_createFromFile("textures/sonic/walk_5.png", NULL);
        break;
    case 6:
        current	= sfTexture_createFromFile("textures/sonic/walk_6.png", NULL);
        break;
    case 7:
        current = sfTexture_createFromFile("textures/sonic/run_1.png", NULL);
        break;
    case 8:
        current = sfTexture_createFromFile("textures/sonic/run_2.png", NULL);
        break;
    case 9:
        current = sfTexture_createFromFile("textures/sonic/run_3.png", NULL);
        break;
    case 10:
        current = sfTexture_createFromFile("textures/sonic/run_4.png", NULL);
        break;
    }
    return (current);
}

sfSprite *set_sonic_sprite(sfClock *clock_move)
{
    sfSprite *sonic = sfSprite_create();
    sfVector2f scale_sonic = {0.6, 0.6};
    sfVector2f position_sonic = {0, 585};
    int tick_anim = get_movement_tick (clock_move);
    sfTexture *sonic_anim = animate_sonic(tick_anim);

    sfSprite_setTexture(sonic, sonic_anim, 1);
    sfSprite_setPosition(sonic, position_sonic);
    return (sonic);
}
