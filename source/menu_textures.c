/*
** EPITECH PROJECT, 2021
** menu_textures.c
** File description:
** related to background and 'press enter'
*/

#include "my_runner.h"

sfSprite *set_background_image(void)
{
    sfSprite *backg_sprite;
        sfTexture *backg_tex =
            sfTexture_createFromFile("textures/menu/main_menu.jpg", NULL);
        sfVector2f scale_backg = {1.80, 1.60};
        sfVector2f position_backg = {1.2, -50};

        backg_sprite = sfSprite_create();
        sfSprite_setTexture(backg_sprite, backg_tex, 1);
        sfSprite_setScale(backg_sprite, scale_backg);
        sfSprite_setPosition(backg_sprite, position_backg);
        return (backg_sprite);
}

sfSprite *set_text_image(void)
{
    sfSprite *text_sprite;
    sfVector2f scale_text = {1, 1};
    sfVector2f position_text = {225, 875};

    text_sprite = sfSprite_create();
    sfSprite_setScale(text_sprite, scale_text);
    sfSprite_setPosition(text_sprite, position_text);
    return (text_sprite);
}

void animate_text(sfSprite *text_sprite, sfClock *clock)
{
    sfTexture *text_tex_1 =
        sfTexture_createFromFile("textures/menu/press_enter_1.png", NULL);
    sfTexture *text_tex_2 =
        sfTexture_createFromFile("textures/menu/press_enter_2.png", NULL);
    sfTime time;
    float time_float;

    time = sfClock_getElapsedTime(clock);
    time_float = sfTime_asSeconds(time);
    if (time_float < 1)
        sfSprite_setTexture(text_sprite, text_tex_1, 1);
    else if (time_float < 2)
        sfSprite_setTexture(text_sprite, text_tex_2, 1);
    else
        sfClock_restart(clock);
}
