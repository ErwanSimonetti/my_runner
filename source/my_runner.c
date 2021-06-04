/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** functions for the project
*/

#include "my_runner.h"

static sfRenderWindow *create_window(char *title)
{
    sfVideoMode mode = {1920, 1080};
    sfRenderWindow *win = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);

    sfRenderWindow_setFramerateLimit(win, 30);
    return (win);
}

int do_game(void)
{
    sfRenderWindow *win = create_window("my_sonic");
    sfSprite *sonic;
    int is_jumping = 0;
    int death = 0;
    sfEvent event;
    sfMusic *music = play_background_music("sounds/ost.wav");
    sfMusic *jump_sound = sfMusic_createFromFile("sounds/jump_sound.wav");
    sfClock *clock_anim = sfClock_create();
    sfClock *clock_move = sfClock_create();
    sfClock *clock_sea = sfClock_create();
    sfClock *clock_back = sfClock_create();
    sfClock *clock_ground = sfClock_create();
    sfClock *clock_jump;
    sfClock *clock_death;

    while (sfRenderWindow_isOpen(win)) {
        draw_all_sprites(win, clock_anim, clock_move, clock_sea, clock_back,
                         clock_ground, death);
        if (is_jumping == 0 && death == 0)
            sonic = set_sonic_sprite(clock_move);
        else if (death == 0){
            is_jumping = jump(sonic, clock_jump);
            if (is_jumping == 0)
                sfMusic_stop(jump_sound);
        }
        sfRenderWindow_drawSprite(win, sonic, NULL);
        while (sfRenderWindow_pollEvent(win, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win);
            if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && is_jumping == 0
                && death == 0) {
                is_jumping = 1;
                sfMusic_play(jump_sound);
                clock_jump = sfClock_create();
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
                sfRenderWindow_close(win);
        }
        if (draw_spikes(win, clock_ground, sonic, death) == 1 | death == 1) {
            if (death_animation(win, death, clock_death, sonic) == 1) {
                destroy_clocks(clock_anim, clock_move, clock_sea, clock_back,
                               clock_ground, clock_jump, clock_death);
                destroy_musics(music, jump_sound);
                sfRenderWindow_close(win);
                do_menu();
            }
            if (death == 0) {
                clock_death = sfClock_create();
                sfMusic_stop(music);
                death = 1;
            }
        }
        sfRenderWindow_display(win);
    }
    return (0);
}

int do_my_runner(sfRenderWindow *win)
{
    sfRenderWindow_close(win);
    do_game();
}
