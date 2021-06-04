/*
** EPITECH PROJECT, 2021
** set_game_ground.c
** File description:
** made to draw & move ground sprites
*/

#include "my_runner.h"

sfSprite *set_ground_1(sfClock *clock, int death)
{
    sfSprite *ground_sprite = sfSprite_create();
    sfTexture *ground =
        sfTexture_createFromFile("textures/ground/basic_ground.png", NULL);
    sfVector2f scale_ground = {3.76, 3.76};
    sfVector2f position_ground = move_ground(clock, 1);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(ground_sprite, ground, 1);
    sfSprite_setScale(ground_sprite, scale_ground);
    if (death == 0)
        sfSprite_setPosition(ground_sprite, position_ground);
    if (death == 1 && already_dead == 0) {
        position_death = position_ground;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(ground_sprite, position_death);
    return (ground_sprite);
}

sfSprite *set_ground_2(sfClock *clock, int death)
{
    sfSprite *ground_sprite = sfSprite_create();
    sfTexture *ground =
        sfTexture_createFromFile("textures/ground/basic_ground.png", NULL);
    sfVector2f scale_ground = {3.76, 3.76};
    sfVector2f position_ground = move_ground(clock, 2);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(ground_sprite, ground, 1);
    sfSprite_setScale(ground_sprite, scale_ground);
    if (death == 0)
        sfSprite_setPosition(ground_sprite, position_ground);
    if (death == 1 && already_dead == 0) {
        position_death = position_ground;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(ground_sprite, position_death);
    return (ground_sprite);
}

sfSprite *set_ground_3(sfClock *clock, int death)
{
    sfSprite *ground_sprite = sfSprite_create();
    sfTexture *ground =
        sfTexture_createFromFile("textures/ground/basic_ground.png", NULL);
    sfVector2f scale_ground = {3.76, 3.76};
    sfVector2f position_ground = move_ground(clock, 3);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(ground_sprite, ground, 1);
    sfSprite_setScale(ground_sprite, scale_ground);
    if (death == 0)
        sfSprite_setPosition(ground_sprite, position_ground);
    if (death == 1 && already_dead == 0) {
        position_death = position_ground;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(ground_sprite, position_death);
    return (ground_sprite);
}
