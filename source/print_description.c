/*
** EPITECH PROJECT, 2020
** print_description.c
** File description:
** displays description and available inputs
*/

#include "my_runner.h"

int print_description(void)
{
    my_putstr("DESCRIPTION :\n\n");
    my_putstr("This program is a runner game: ");
    my_putstr("you have to go as far as possible without dying to score as\n");
    my_putstr("many points as possible.");
    my_putstr("\nYou can jump to avoid enemies.");
    my_putstr("\n\n");
    my_putstr("-  -  -  -  -  -  -  -");
    my_putstr("\n\n");
    my_putstr("USER INPUTS :\n\n");
    my_putstr("ENTER(main menu): LAUNCH GAME\n");
    my_putstr("SPACE: JUMP\n");
    my_putstr("ESCAPE: CLOSE GAME\n");
}
