/*
** EPITECH PROJECT, 2020
** calculation
** File description:
** .
*/

#include "./include/my.h"
#include "./include/add_substract.h"
#include "./include/multiply.h"
#include "./include/divide.h"

char *doing_add(char **stack, int *pos)
{
     char *temp = malloc(sizeof(char) * ((my_strlen(stack[*pos])) +
     (my_strlen(stack[*pos - 1]))));

     if (stack[*pos - 1][0] == '-' && stack[*pos][0] == '-') {
          temp = infin_add(get_abs(stack[*pos - 1]),
          get_abs(stack[*pos]), 1);
          return (temp);
     }
     if (prep_op(stack[*pos - 1], stack[*pos]) && stack[*pos - 1][0] == '-') {
         temp = infin_sub(get_abs(stack[*pos]), get_abs(stack[*pos - 1]));
     } else if (prep_op(stack[*pos - 1], stack[*pos])) {
         temp = infin_sub(get_abs(stack[*pos - 1]), get_abs(stack[*pos]));
     } else {
         temp = infin_add(get_abs(stack[*pos - 1]), get_abs(stack[*pos]), 0);
     }
     return (temp);
}

char *doing_subb(char **stack, int *pos)
{
     char *temp = malloc(sizeof(char) * ((my_strlen(stack[*pos])) +
     (my_strlen(stack[*pos - 1]))));

     if (stack[*pos - 1][0] == '-' && stack[*pos][0] == '-') {
          temp = infin_sub(get_abs(stack[*pos]), get_abs(stack[*pos - 1]));
          return (temp);
     }
     if (prep_op(stack[*pos - 1], stack[*pos]) && stack[*pos][0] == '-' ) {
          temp = infin_add(get_abs(stack[*pos - 1]), get_abs(stack[*pos]), 0);
     } else if (prep_op(stack[*pos - 1], stack[*pos])) {
          temp = infin_add(get_abs(stack[*pos - 1]), get_abs(stack[*pos]), 1);
     } else {
          temp = infin_sub(get_abs(stack[*pos - 1]), get_abs(stack[*pos]));
     }
   return (temp);
}

char *doing_mult(char **stack, int *pos)
{
     char *temp = malloc(sizeof(char) * ((my_strlen(stack[*pos])) +
     (my_strlen(stack[*pos - 1]))));

     if (prep_op(stack[*pos - 1], stack[*pos]))
     {
          temp = infin_multiply(get_abs(stack[*pos - 1]),
          get_abs(stack[*pos]), 1);
     } else {
          temp = infin_multiply(get_abs(stack[*pos - 1]),
          get_abs(stack[*pos]), 0);
     }
     return (temp);
}

char *doing_div(char **stack, int *pos)
{
     char *temp = malloc(sizeof(char) * ((my_strlen(stack[*pos])) +
     (my_strlen(stack[*pos - 1]))));

     if (prep_op(stack[*pos - 1], stack[*pos]))
     {
          temp = infin_divide(get_abs(stack[*pos - 1]),
          get_abs(stack[*pos]), 1);
     } else {
          temp = infin_divide(get_abs(stack[*pos - 1]),
          get_abs(stack[*pos]), 0);
     }
     return (temp);
}

char *doing_modd(char **stack, int *pos)
{
     char *temp = malloc(sizeof(char) * ((my_strlen(stack[*pos])) +
     (my_strlen(stack[*pos - 1]))));

     if (prep_op(stack[*pos - 1], stack[*pos]))
     {
          temp = infin_modulo(get_abs(stack[*pos - 1]),
          get_abs(stack[*pos]), 1);
     } else {
          temp = infin_modulo(get_abs(stack[*pos - 1]),
          get_abs(stack[*pos]), 0);
     }
     return (temp);
}