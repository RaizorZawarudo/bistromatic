/*
** EPITECH PROJECT, 2020
** infin_add.h
** File description:
** .
*/

#ifndef INFIN_ADD_H
#define INFIN_ADD_H

#include <stdlib.h>

struct operands_add {
    char *long_operand;
    char *short_operand;
};

char *infin_add(char *input1, char *input2, int neg_num);
char *infin_sub(char *input1, char *input2);
char *remove_zeros(char *str);

#endif