/*
** EPITECH PROJECT, 2021
** set_game_background.c
** File description:
** parallax
*/

#include "my_runner.h"

sfSprite *set_background_1(sfClock *clock_anim, sfClock *clock_back, int death)
{
    sfSprite *backg_sprite = sfSprite_create();
    sfTexture *back =
        sfTexture_createFromFile("textures/background/back_1.png", NULL);
    sfVector2f scale_backg = {3.75, 3.75};
    sfVector2f position_backg = move_background(clock_back, 1);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(backg_sprite, back, 1);
    sfSprite_setScale(backg_sprite, scale_backg);
    if (death == 0)
        sfSprite_setPosition(backg_sprite, position_backg);
    if (death == 1 && already_dead == 0) {
        position_death = position_backg;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(backg_sprite, position_death);
    return (backg_sprite);
}

sfSprite *set_background_2(sfClock *clock_anim, sfClock *clock_back, int death)
{
    sfSprite *backg_sprite = sfSprite_create();
    int tick_anim = get_tick(clock_anim);
    sfTexture *back = animate_tile_2(tick_anim);
    sfVector2f scale_backg = {3.75, 3.75};
    sfVector2f position_backg = move_background(clock_back, 2);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(backg_sprite, back, 1);
    sfSprite_setScale(backg_sprite, scale_backg);
    if (death == 0)
        sfSprite_setPosition(backg_sprite, position_backg);
    if (death == 1 && already_dead == 0) {
        position_death = position_backg;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(backg_sprite, position_death);
    return (backg_sprite);
}

sfSprite *set_background_3(sfClock *clock_anim, sfClock *clock_back, int death)
{
    sfSprite *backg_sprite = sfSprite_create();
    int tick_anim = get_tick(clock_anim);
    sfTexture *back =
        sfTexture_createFromFile("textures/background/back_3.png", NULL);
    sfVector2f scale_backg = {3.75, 3.75};
    sfVector2f position_backg = move_background(clock_back, 3);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(backg_sprite, back, 1);
    sfSprite_setScale(backg_sprite, scale_backg);
    if (death == 0)
        sfSprite_setPosition(backg_sprite, position_backg);
    if (death == 1 && already_dead == 0) {
        position_death = position_backg;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(backg_sprite, position_death);
    return (backg_sprite);
}

sfSprite *set_sea_1(sfClock *clock_anim, sfClock *clock_move, int death)
{
    sfSprite *backg_sprite = sfSprite_create();
    int tick_anim = get_tick(clock_anim);
    sfTexture *back = animate_sea(tick_anim);
    sfVector2f scale_backg = {4.75, 4.75};
    sfVector2f position_backg = move_sea(clock_move, 1);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(backg_sprite, back, 1);
    sfSprite_setScale(backg_sprite, scale_backg);
    if (death == 0)
        sfSprite_setPosition(backg_sprite, position_backg);
    if (death == 1 && already_dead == 0) {
        position_death = position_backg;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(backg_sprite, position_death);
    return (backg_sprite);
}

sfSprite *set_sea_2(sfClock *clock_anim, sfClock *clock_move, int death)
{
    sfSprite *backg_sprite = sfSprite_create();
    int tick_anim = get_tick(clock_anim);
    sfTexture *back = animate_sea(tick_anim);
    sfVector2f scale_backg = {4.75, 4.75};
    sfVector2f position_backg = move_sea(clock_move, 2);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(backg_sprite, back, 1);
    sfSprite_setScale(backg_sprite, scale_backg);
    if (death == 0)
        sfSprite_setPosition(backg_sprite, position_backg);
    if (death == 1 && already_dead == 0) {
        position_death = position_backg;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(backg_sprite, position_death);
    return (backg_sprite);
}

sfSprite *set_sea_3(sfClock *clock_anim, sfClock *clock_move, int death)
{
    sfSprite *backg_sprite = sfSprite_create();
    int tick_anim = get_tick(clock_anim);
    sfTexture *back = animate_sea(tick_anim);
    sfVector2f scale_backg = {4.75, 4.75};
    sfVector2f position_backg = move_sea(clock_move, 3);
    static sfVector2f position_death;
    static int already_dead = 0;

    sfSprite_setTexture(backg_sprite, back, 1);
    sfSprite_setScale(backg_sprite, scale_backg);
    if (death == 0)
        sfSprite_setPosition(backg_sprite, position_backg);
    if (death == 1 && already_dead == 0) {
        position_death = position_backg;
        already_dead = 1;
    }
    if (death == 1 && already_dead == 1)
        sfSprite_setPosition(backg_sprite, position_death);
    return (backg_sprite);
}
