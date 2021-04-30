/*
** EPITECH PROJECT, 2020
** main.c
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

int print_h (void)
{
        my_putstr("USAGE\n");
        my_putstr("./calc base operators size_read\n");
        my_putstr("\nDESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the");
        my_putstr(" parentheses and the 5 operators\n");
        my_putstr("- size_read: number of characters to be read\n");
        return 0;
}

static char  *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;
    char *cp ;

    check_error(ac, av);
    check_base(av[1]);
    check_ops(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    cp = converted_base_num(expr, av[1]);
    cp = converted_base_ope(cp, av[2]);
    my_putstr(eval_expr(cp, av[1]));
    my_putchar('\n');
    return (EXIT_SUCCESS);
}