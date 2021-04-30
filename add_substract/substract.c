/*
** EPITECH PROJECT, 2020
** infin_substract
** File description:
** Code relevant to the substraction part of things
*/

#include "../include/add_substract.h"
#include "../include/my.h"
#include "../include/general_utilities.h"

static struct operands_add sort_inputs(char *input1, char *input2)
{
    char *long_input = input1;
    char *short_input = input2;
    struct operands_add output;

    if (!is_largest(long_input, short_input)) {
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

    digit = get_digit(inputs.long_operand[i]) -
    get_digit(inputs.short_operand[j]) - leftover;
    if (digit < 0) {
        digit = get_digit(inputs.long_operand[i]) + 10
        - get_digit(inputs.short_operand[j]) - leftover;
        leftover = 1;
    } else
        leftover = 0;
    output[0] = digit;
    output[1] = leftover;
    return output;
}

static char *frm(char *output, int reversed, struct operands_add inputs, int i)
{
    for (; i >= 0; i--)
        output = append_digit(inputs.long_operand[i], output);
    output = remove_zeros(output);
    if (reversed)
        output = append_digit('-', output);
    return output;
}

char *infin_sub(char *input1, char *input2)
{
    struct operands_add inputs = sort_inputs(input1, input2);
    char *output = "\0";
    int i = my_strlen(inputs.long_operand) - 1;
    int j = my_strlen(inputs.short_operand) - 1;
    int leftover = 0;
    int reversed = 0;
    int digit;

    if (input1 != inputs.long_operand)
        reversed = 1;
    for (; j >= 0; i--, j--) {
        digit = upd_digit(inputs, i, j, leftover)[0];
        leftover = upd_digit(inputs, i, j, leftover)[1];
        output = append_digit(digit + 48, output);
    }
    if (leftover) {
        output = append_digit(inputs.long_operand[i] - 1, output);
        i--;
    }
    return frm(output, reversed, inputs, i);
}