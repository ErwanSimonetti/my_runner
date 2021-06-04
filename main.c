/*
** EPITECH PROJECT, 2020
** main bs_my_ls
** File description:
** main function for bootstrap
*/

#include "my_runner.h"

int main(int ac, char **av)
{
    if (ac > 1) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            print_description();
        else
            do_menu();
    }
    else
        do_menu();
    return (0);
}
