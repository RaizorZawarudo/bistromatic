/*
** EPITECH PROJECT, 2020
** divide.c
** File description:
** .
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/general_utilities.h"
#include "../include/add_substract.h"
#include "../include/multiply.h"
#include "../include/divide.h"

div_operation_t prep_input(char *input1, char *input2)
{
    div_operation_t output;
    output.dividend = my_strdup(input1);
    output.divider = my_strdup(input2);
    output.quotient = my_strdup("\0");
    output.leftover = my_strdup("?");
    return output;
}

char *get_div(char *dividend, char *divider, char *leftover)
{
    char *output = "";
    int leftover_len = my_strlen(leftover);
    int i;

    if (leftover[0] == '?') {
        for (i = 0; is_largest(divider, output) && dividend[i] != '\0'; i++)
            output = append_char(output, dividend[i]);
        output = "";
        for (int j = 0; j < i - 1; j++)
            output = append_char(output, dividend[j]);
        if (is_largest(divider, output))
            output = append_char(output, dividend[i - 1]);
    }
    else {
        if (str_n(leftover))
            output = append_char(output, dividend[0]);
        else
            for (int j = 0; j < leftover_len + 1; j++)
                output = append_char(output, dividend[j]);
    }
    return output;
}

char *rep_div(char *cons_div, char *leftover, char *original_div)
{
    int og_div_len = my_strlen(original_div);
    int considered_div_len = my_strlen(cons_div);
    int leftover_len = my_strlen(leftover);
    char *output = malloc(sizeof(char) * (og_div_len - considered_div_len + 1));

    if (!str_n(leftover)) {
        output = my_strcpy(output, leftover);
        if (my_strcmp(cons_div, original_div) == 0)
            return output;
        my_strcpy(&output[leftover_len], &original_div[considered_div_len]);
    } else
        output = my_strcpy(output, &original_div[considered_div_len]);
    return output;
}

div_operation_t operation_update(div_operation_t inputs)
{
    char *dividend = get_div(inputs.dividend, inputs.divider, inputs.leftover);
    char *sum_divider = "0";
    div_operation_t output;
    int i = 0;
    char *quotient_str;

    output.divider = my_strdup(inputs.divider);
    output.quotient = my_strdup(inputs.quotient);
    for (i = 0; is_largest(dividend, sum_divider); i++)
        sum_divider = infin_add(sum_divider, inputs.divider, 0);
    sum_divider = infin_sub(sum_divider, inputs.divider);
    i--;
    output.leftover = my_strdup(infin_sub(dividend, sum_divider));
    output.dividend = my_strdup(rep_div(dividend, output.leftover, inputs.dividend));
    quotient_str = int_to_string(i);
    for (int j = 0; j < my_strlen(quotient_str); j++)
        output.quotient = append_char(output.quotient, quotient_str[j]);
    if (is_largest(output.dividend, output.divider) && !str_n(output.dividend))
        output = operation_update(output);
    return output;
}

char *infin_divide(char *input1, char *input2, int res_neg)
{
    div_operation_t operation = prep_input(input1, input2);
    int len_diff;

    if (input2[0] == '0')
        exit(84);
    operation = operation_update(operation);
    len_diff = my_strlen(operation.dividend) - my_strlen(operation.leftover);
    if (str_n(operation.dividend) && str_n(operation.leftover))
        for (int i = 0; i <= len_diff; i++)
            operation.quotient = append_char(operation.quotient, '0');
    if (res_neg) {
        operation.quotient = append_digit('-', operation.quotient);
        return operation.quotient;
    }
    else
        return operation.quotient;
}

char *infin_modulo(char *input1, char *input2, int res_neg)
{
    div_operation_t operation = prep_input(input1, input2);

    operation = operation_update(operation);
    if (res_neg) {
        operation.leftover = append_digit('-', operation.leftover);
        return operation.leftover;
    }
    else
        return operation.leftover;
}