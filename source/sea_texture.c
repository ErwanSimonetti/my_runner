/*
** EPITECH PROJECT, 2021
** sea_texture.c
** File description:
** animate sea
*/

#include "my_runner.h"

sfTexture *animate_sea(int tick)
{
    sfTexture *sea_1 =
        sfTexture_createFromFile("textures/sea/sea_1.png", NULL);
    sfTexture *sea_2 =
        sfTexture_createFromFile("textures/sea/sea_2.png", NULL);
    sfTexture *sea_3 =
        sfTexture_createFromFile("textures/sea/sea_3.png", NULL);
    sfTexture *sea_4 =
        sfTexture_createFromFile("textures/sea/sea_4.png", NULL);
    
    switch (tick) {
    case 1:
        return(sea_1);
        break;
    case 2:
        return(sea_2);
        break;
    case 3:
        return(sea_3);
        break;
    case 4:
        return(sea_4);
        break;
    }
}
