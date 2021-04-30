/*
** EPITECH PROJECT, 2020
** divide.h
** File description:
** .
*/

#ifndef DIVIDE_H
#define DIVIDE_H

typedef struct div_operation_s {
    char *dividend;
    char *divider;
    char *quotient;
    char *leftover;
} div_operation_t;

int str_n(char *str);
char *append_char(char *dest, char character);
char *infin_divide(char *input1, char *input2, int res_neg);
char *int_to_string(int input);
char *infin_modulo(char *input1, char *input2, int res_neg);

#endif