/*
** EPITECH PROJECT, 2021
** set_game_spikes.c
** File description:
** spikes
*/

#include "my_runner.h"

sfSprite *set_spikes_1(sfClock *clock, int death)
{
    sfSprite *ground_sprite = sfSprite_create();
    sfVector2f scale_ground = {0.15, 0.15};
    sfVector2f position_ground = move_spikes(clock, 1);
    static sfVector2f position_death;
    static int already_dead = 0;

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

sfSprite *set_spikes_2(sfClock *clock, int death)
{
    sfSprite *ground_sprite = sfSprite_create();
    sfVector2f scale_ground = {0.15, 0.15};
    sfVector2f position_ground = move_spikes(clock, 2);
    static sfVector2f position_death;
    static int already_dead = 0;

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

sfSprite *set_spikes_3(sfClock *clock, int death)
{
    sfSprite *ground_sprite = sfSprite_create();
    sfVector2f scale_ground = {0.15, 0.15};
    sfVector2f position_ground = move_spikes(clock, 3);
    static sfVector2f position_death;
    static int already_dead = 0;

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
