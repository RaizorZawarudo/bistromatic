/*
** EPITECH PROJECT, 2020
** infin_multiply
** File description:
** .
*/

#include <string.h>
#include "../include/general_utilities.h"
#include "../include/my.h"
#include "../include/multiply.h"
#include "../include/add_substract.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int srclen = my_strlen(src);
    char *newsrc = malloc(sizeof(char)*(srclen + 1));

    for (i = 0; i <= srclen; i++)
        newsrc[i] = src[i];
    newsrc[i-1] = '\0';
    return (newsrc);
}

struct operands_mult prepare_input(char *input1, char *input2)
{
    struct operands_mult output;
    output.multiplied = malloc(sizeof(char) * (my_strlen(input1) + 1));
    output.multiplier = malloc(sizeof(char) * (my_strlen(input2) + 1));
    output.multiplied = my_strcpy(output.multiplied, input1);
    output.multiplier = my_strcpy(output.multiplier, input2);
    if ((output.multiplied[0] == '-') ^ (output.multiplier[0] == '-')) {
        if (output.multiplier[0] == '-') {
            output.multiplier =
            my_strcpy(output.multiplier, &output.multiplier[1]);
        }
        if (output.multiplied[0] == '-') {
            output.multiplied =
            my_strcpy(output.multiplied, &output.multiplied[1]);
        }
        output.res_neg = 1;
    } else
        output.res_neg = 0;
    return output;
}

char *update_res(char *res, struct operands_mult inputs, int index)
{
    int line = my_strlen(inputs.multiplier) - index;
    int digit;
    int leftover = 0;
    int multiplier = get_digit(inputs.multiplier[index]);
    char *line_res = "\0";

    for (int i = 1; i < line; i++)
        line_res = append_digit('0', line_res);
    for (int i = my_strlen(inputs.multiplied) - 1; i >= 0; i--) {
        digit = multiplier * get_digit(inputs.multiplied[i]) + leftover;
        leftover = 0;
        while (digit >= 10) {
            digit -= 10;
            leftover++;
        }
        line_res = append_digit(digit + 48, line_res);
    }
    if (leftover)
        line_res = append_digit(leftover + 48, line_res);
    return infin_add(my_strdup(res), line_res, 0);
}

char *infin_multiply(char *input1, char *input2, int res_neg)
{
    struct operands_mult inputs = prepare_input(input1, input2);
    char *res = "0";

    for (int i = my_strlen(inputs.multiplier) - 1; i >= 0; i--)
        res = update_res(res, inputs, i);
    if (res_neg == 1)
        res = append_digit('-', res);
    return res;
}