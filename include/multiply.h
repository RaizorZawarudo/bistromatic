/*
** EPITECH PROJECT, 2020
** multiply.h
** File description:
** .
*/

#ifndef MULTIPLY_H
#define MULTIPLY_H

struct operands_mult {
    char *multiplied;
    char *multiplier;
    int res_neg;
};

char *infin_multiply(char *input1, char *input2,int res_neg);

#endif