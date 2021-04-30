/*
** EPITECH PROJECT, 2020
** evalexp
** File description:
** storage2
*/

#include "../include/eval_expr.h"
#include "../include/my.h"

int is_numeric(char a)
{
    if (a >= 48 && a <= 57)
        return (1);
    return (0);
}

int check_operator(char a)
{
    if (a == '%' || a == '/' || a == '*')
        return (3);
    if (a == '+' || a == '-')
        return (2);
    if (a == '(')
        return (1);
    else
        return (0);
}

int is_operator(char *arrayed_expression)
{
    if (my_strlen(arrayed_expression) == 1 && (arrayed_expression[0] == '*' ||
                arrayed_expression[0] == '/' || arrayed_expression[0] == '+'
                || arrayed_expression[0] == '%'
                || arrayed_expression[0] == '-')) {
        return (1);
    } else
        return (0);
}

int is_number(char *number_string)
{
    if ( my_str_isnum(number_string))
        return (1);
    else
        return (0);
}



