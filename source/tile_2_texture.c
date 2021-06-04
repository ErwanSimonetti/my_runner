/*
** EPITECH PROJECT, 2021
** tile_2_texture.c
** File description:
** animate tile_2
*/

#include "my_runner.h"

sfTexture *animate_tile_2(int tick)
{
    sfTexture *current;
    
    switch (tick) {
    case 1:
        current = sfTexture_createFromFile("textures/background/back_2-10.png", NULL);
        break;
    case 2:
        current	= sfTexture_createFromFile("textures/background/back_2-11.png", NULL);
        break;
    case 3:
        current	= sfTexture_createFromFile("textures/background/back_2-12.png", NULL);
        break;
    case 4:
        current	= sfTexture_createFromFile("textures/background/back_2-13.png", NULL);
        break;
    }
    return (current);
}
