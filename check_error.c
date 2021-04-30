/*
** EPITECH PROJECT, 2020
** check_error
** File description:
** .
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/bistromatic.h"
#include "include/my.h"
#include "include/eval_expr.h"

int check_error(int ac, char **av)
{
    if (ac != 4) {
        if (ac == 1) {
            my_putstr(av[0]);
            my_putstr(" base ops\"()+_*/%\" exp_len\n");
            exit (EXIT_USAGE);
        }
        if (ac != 4 && av[1][0] == '-' && av[1][1] == 'h') {
            print_h();
            exit(EXIT_USAGE);
        } else {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        exit (EXIT_USAGE);
        }
    }
    return (0);
}

int check_same_base(char *base_num, char *base_ope)
{
    int j = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 11; j++) {
            if (base_ope[i] == base_num[j])
                exit (EXIT_BASE);
        }
        j = 0;
    }
    return (0);
}