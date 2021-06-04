/*
** EPITECH PROJECT, 2021
** menu code for runner
** File description:
** menu
*/

#include "my_runner.h"

static sfRenderWindow *create_window(char *title)
{
    sfVideoMode mode = {1920, 1080};
    sfRenderWindow *win = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);

    sfRenderWindow_setFramerateLimit(win, 30);
    return (win);
}

int fade_out(sfMusic *music, sfSprite *backg_sprite,
             sfSprite *text_sprite)
{
    sfColor black = sfColor_fromRGBA(0, 0, 0, 30);
    
    sfSprite_setColor(backg_sprite, black);
    sfSprite_setColor(text_sprite, black);
    sfMusic_destroy(music);
}


void wait_fade_out(sfClock *clock_fade, sfRenderWindow *win)
{
    sfTime time;
    float time_float;

    time = sfClock_getElapsedTime(clock_fade);
    time_float = sfTime_asSeconds(time);
    if (time_float > 2)
        do_my_runner(win);
}

int do_menu(void)
{
    sfRenderWindow *win = create_window("main_menu");
    sfSprite *backg_sprite = set_background_image();
    sfSprite *text_sprite = set_text_image();
    sfMusic *music = play_background_music("sounds/main_menu.wav");
    sfMusic *ring_sound = sfMusic_createFromFile("sounds/ring_sound.wav");
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfClock *clock_fade;
    int pressed = 0;

    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_drawSprite(win, backg_sprite, NULL);
        animate_text(text_sprite, clock);
        sfRenderWindow_drawSprite(win, text_sprite, NULL);
        while (sfRenderWindow_pollEvent(win, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win);
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
                sfRenderWindow_close(win);
            if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue && pressed == 0) {
                sfMusic_play(ring_sound);
                fade_out(music, backg_sprite, text_sprite);
                clock_fade = sfClock_create();
                pressed = 1;
            }
        }
        if (pressed == 1)
            wait_fade_out(clock_fade, win);
        sfRenderWindow_display(win);
    }
}
    
