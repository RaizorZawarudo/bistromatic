/*
** EPITECH PROJECT, 2020
** evalexp
** File description:
** storage1
*/

#include "../include/eval_expr.h"
#include "../include/my.h"

int my_arrlen(char **arr)
{
    int count = 0;
    for (int counter = 0; arr[counter]; counter++)
        count++;
    return (count);
}

char *remove_from_stack(char a, int *position_of_counter)
{
    char *operator_as_string = NULL;
    operator_as_string = malloc(sizeof(char) * 2);

    operator_as_string[0] = a;
    operator_as_string[1] = '\0';
    *position_of_counter -= 1;
    return (operator_as_string);
}

void put_in_post(char **post, int *size, char *normal)
{
    post[*size] = normal;
    *size += 1;
}

void put_in_stack(char a, int *position_of_counter, char *postfixer_stack)
{
    *position_of_counter += 1;
    postfixer_stack[*position_of_counter] = a;
}

void dump(char *stack, int *stackcounter, char **postarray, int *postcounter)
{
    while (stack[*stackcounter] != '#' && stack[*stackcounter] != '(' ) {
        put_in_post(postarray, postcounter,
        remove_from_stack(stack[*stackcounter], stackcounter));
    }
}