/*
** EPITECH PROJECT, 2021
** play_background_music.c
** File description:
** made to set a loop and play half volume
*/

#include "my_runner.h"

sfMusic *play_background_music(char *title)
{
    sfMusic *music = sfMusic_createFromFile(title);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfMusic_setVolume(music, 50);
    return (music);
}
