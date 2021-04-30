/*
** EPITECH PROJECT, 2020
** inputcleaner.c
** File description:
** makes sur the expression to evalexp is without special cases
*/

#include "../include/eval_expr.h"
#include "../include/my.h"

int is_oper_char(char a)
{
    if (a == '-' || a == '+' || a == '/' || a == '*' || a == '%')
        return (1);
    else
        return (0);
}

int count_open_brackets(char *str, int i)
{
    int number_of_open_brackets = 0;

    for (int a = 0; str[i + a] != ')'; a++) {
        if (str[i + a] == '(')
            number_of_open_brackets++;
    }
    return (number_of_open_brackets);
}

char *inputcleaner(char *str)
{
    char *new_str;
    int j = 0;
    int s_case = 0;
    int closed_brc ;
    int we_are_in_the_case = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && is_oper_char(str[i -1]) && str[i + 1] == '(')
            s_case++;
    }
    new_str = malloc(sizeof(char) * (my_strlen(str) + s_case * 4));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && is_oper_char(str[i -1]) && str[i + 1] == '(') {
            we_are_in_the_case = 1;
            closed_brc = count_open_brackets(str, i);
            new_str[j] = '(';
            j++;
            new_str[j] = '-';
            j++;
            new_str[j] = '1';
            j++;
            new_str[j] = '*';
            j++;
            i++;
        }
        if (str[i] == ')' && s_case != 0 && closed_brc != 0)
            closed_brc--;
        if (we_are_in_the_case == 1 && closed_brc == 0 && s_case != 0) {
            new_str[j] = ')';
            j++;
            we_are_in_the_case = 0;
        }
        new_str[j] = str[i];
        j++;
    }
    return (new_str);
}