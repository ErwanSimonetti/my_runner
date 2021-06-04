/*
** EPITECH PROJECT, 2021
** draw_spikes.c
** File description:
** tell if sonic got hit with spikes
*/

#include "my_runner.h"

int spike_hit_sonic(sfSprite *sonic, sfSprite *spike, int nb)
{
    sfFloatRect rec_sonic = sfSprite_getGlobalBounds(sonic);
    sfFloatRect rec_spike = sfSprite_getGlobalBounds(spike);

    if (rec_spike.left <= 200 && rec_spike.left >= 20) {
        if (rec_spike.top + rec_spike.height < rec_sonic.top + rec_sonic.height)
            return (1);
    }
    return(0);
}

int draw_spikes(sfRenderWindow *win, sfClock *clock, sfSprite *sonic, int death)
{
    sfTexture *spikes_tex =
        sfTexture_createFromFile("textures/ground/spikes.png", NULL);
    sfSprite *spikes_1 = set_spikes_1(clock, death);
    sfSprite *spikes_2 = set_spikes_2(clock, death);
    sfSprite *spikes_3 = set_spikes_3(clock, death);

    sfSprite_setTexture(spikes_1, spikes_tex, 1);
    sfSprite_setTexture(spikes_2, spikes_tex, 1);
    sfSprite_setTexture(spikes_3, spikes_tex, 1);
    sfRenderWindow_drawSprite(win, spikes_1, NULL);
    sfRenderWindow_drawSprite(win, spikes_2, NULL);
    sfRenderWindow_drawSprite(win, spikes_3, NULL);
    if (spike_hit_sonic(sonic, spikes_1, 1) == 1)
        return(1);
    if (spike_hit_sonic(sonic, spikes_2, 2) == 1)
        return(1);
    if (spike_hit_sonic(sonic, spikes_3, 3) == 1)
        return(1);
    return(0);
}
