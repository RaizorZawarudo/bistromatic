/*
** EPITECH PROJECT, 2020
** evalexp
** File description:
** take 1
*/

#include "../include/eval_expr.h"
#include "../include/my.h"
#include "../include/add_substract.h"
#include "../include/general_utilities.h"

void put_in_stack_two(char *a, int *position_of_counter, char **nstack)
{
    *position_of_counter += 1;
    nstack[*position_of_counter] = a;
}

int prep_op(char *nb1, char *nb2)
{
    if ((nb1[0] == '-' && nb2[0] != '-') || (nb1[0] != '-' && nb2[0] == '-'))
        return 1;
    else
        return 0;
}

char *oper1(char **nstack, char *operator, int *stackpos)
{
    char *temp = 0;

    switch (operator[0]) {
    case '+':temp = doing_add(nstack, stackpos); return (temp);
    case '-':temp = doing_subb(nstack, stackpos); return (temp);
    case '*':temp = doing_mult(nstack, stackpos); return (temp);
    case '/':temp = doing_div(nstack, stackpos); return (temp);
    case '%':temp = doing_modd(nstack, stackpos); return (temp);
    }
    return ("this return cannot happen");
}

void calculator1(struct calc *val, char **postfix)
{
    while (val->i < my_arrlen(postfix)) {
        if (is_number(postfix[val->i])) {
            val->nstack[*val->stackpos + 1] =
            malloc(sizeof(char) * my_strlen(postfix[val->i]));
            put_in_stack_two(postfix[val->i], val->stackpos, val->nstack);
        }
         if (is_operator(postfix[val->i])) {
            if (postfix[val->i][0] == '+' ||
                postfix[val->i][0] == '-' || postfix[val->i][0] == '*' ||
                postfix[val->i][0] == '/' || postfix[val->i][0] == '%') {
                val->nstack[*val->stackpos - 1]
                = oper1(val->nstack, postfix[val->i], val->stackpos);
                *val->stackpos = *val->stackpos - 1;
            }
        }
    val->i++;
    }
}


char *postfix_expression_calculator (char **postfix)
{
    int st_position = 0;
    struct calc *val = malloc(sizeof(*val));
    val->i = 0;
    val->stackpos = &st_position;
    val->nstack = malloc(sizeof(char *) * (my_arrlen(postfix)));

    calculator1(val, postfix);
    return (val->nstack[1]);
}