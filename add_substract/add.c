/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** Code relevant to the addition part of thing
*/

#include <stdio.h>
#include "../include/add_substract.h"
#include "../include/my.h"
#include "../include/general_utilities.h"

static struct operands_add sort_inputs(char *input1, char *input2)
{
    char *long_input = input1;
    char *short_input = input2;
    struct operands_add output;

    if (my_strlen(short_input) > my_strlen(long_input)) {
        long_input = input2;
        short_input = input1;
    }
    output.long_operand = long_input;
    output.short_operand = short_input;
    return output;
}

static int *upd_digit(struct operands_add inputs, int i, int j, int leftover)
{
    int digit;
    int *output = malloc(sizeof(int) * 2);

    digit = get_digit(inputs.long_operand[i]) +
    get_digit(inputs.short_operand[j]) + leftover;
    if (digit >= 10) {
        digit -= 10;
        leftover = 1;
    } else
        leftover = 0;
    output[0] = digit;
    output[1] = leftover;
    return output;
}

static char *format_output(char *output, int neg_num)
{
    output = remove_zeros(output);
    if (neg_num)
        output = append_digit('-', output);
    return output;
}

char *infin_add(char *input1, char *input2, int neg_num)
{
    struct operands_add inputs = sort_inputs(input1, input2);
    char *output = "\0";
    int i = my_strlen(inputs.long_operand) - 1;
    int j = my_strlen(inputs.short_operand) - 1;
    int leftover = 0;
    int digit;

    for (; j >= 0; i--, j--) {
        digit = upd_digit(inputs, i, j, leftover)[0];
        leftover = upd_digit(inputs, i, j, leftover)[1];
        output = append_digit(digit + 48, output);
    }
    if (i < 0 && leftover)
        output = append_digit('1', output);
    else if (leftover) {
        output = append_digit(inputs.long_operand[i] + 1, output);
        i--;
    }
    for (; i >= 0; i--)
        output = append_digit(inputs.long_operand[i], output);
    return format_output(output, neg_num);
}