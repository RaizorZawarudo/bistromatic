/*
** EPITECH PROJECT, 2020
** evalexp
** File description:
** storage3
*/

#include "../include/eval_expr.h"
#include "../include/my.h"

void brackets(struct Postfix_variables *var, int i, char **normal_array)
{
    if (normal_array[i][0] == '(')
            put_in_stack(normal_array[i][0], var->stackpos,
            var->postfixer_stack);
        if (normal_array[i][0] == ')') {
            dump(var->postfixer_stack, var->stackpos, var->postfix, var->size);
            *var->stackpos -= 1;
        }
}

void operator_num(struct Postfix_variables *var, int i, char **normal_array)
{
    if (is_number(normal_array[i]))
            put_in_post(var->postfix, var->size, normal_array[i]);
    if (is_operator(normal_array[i])) {
            if (check_operator(normal_array[i][0]) <=
            check_operator(var->postfixer_stack[*var->stackpos]))
                dump(var->postfixer_stack, var->stackpos,
                var->postfix, var->size);
            put_in_stack(normal_array[i][0], var->stackpos,
            var->postfixer_stack);
        }
}

char **postfix_expression_creator(char **normal_array)
{
    int pos = 0;
    int sizei = 0;
    int i = 0;
    struct Postfix_variables *var = malloc(sizeof(*var));

    var->stackpos = &pos;
    var->postfix = malloc(sizeof(char *) * (my_arrlen(normal_array) + 1));
    var->size = &sizei;
    var->postfixer_stack = malloc(sizeof(char) * my_arrlen(normal_array) + 1);
    var->postfix[my_arrlen(normal_array)] = NULL;
    var->postfixer_stack[0] = '#';
    for (int counter = 0; counter < my_arrlen(normal_array); counter++)
        var->postfix[counter] = malloc(sizeof(char) * 11);
    while (i < my_arrlen(normal_array)) {
        operator_num(var, i, normal_array);
        brackets(var, i, normal_array);
        i = i + 1;
    }
    dump(var->postfixer_stack, var->stackpos, var->postfix, var->size);
    return (var->postfix);
}
