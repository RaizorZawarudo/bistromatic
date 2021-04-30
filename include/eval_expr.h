/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task 02 day 09
*/

#ifndef MY_H
#define MY_H
#include <stdio.h>
#include <stdlib.h>

struct first_malloc_sizes
{
    int alloc_size;
    int position_on_alloc_array;
    int *alloc_array;

};

struct Postfix_variables
{
    int *size ;
    char **postfix;
    int *stackpos;
    char *postfixer_stack;
};

struct Arraycounters
{
    char **returned;
    int counter;
    int counter1;
    int counter2;
    int counter4;
};

struct calc
{
    int i;
    int *stackpos;
    char **nstack;
};

char *inputcleaner(char *str);
int count_open_brackets(char *str, int i);
int is_oper_char(char a);
int counts(char *str, struct first_malloc_sizes sizes);
char **convert_to_array(char *str);
char **postfix_expression_creator(char **normal_expression_array);
int my_arrlen(char **arr);
char *remove_from_stack(char a, int *position_of_counter);
void put_in_post(char **post, int *size, char *normal);
void put_in_stack(char a, int *position_of_counter, char *postfixer_stack);
void dump(char *stack, int *stackcounter, char **postarray, int *postcounter);
int check_operator(char a);
char *postfix_expression_calculator (char **postfix);
char *eval_expr(char *str, char *bas_num);
int is_operator(char *arrayed_expression);
int is_number(char *number_string);
void operator_num(struct Postfix_variables *lol, int i, char **normal_array);
void brackets(struct Postfix_variables *lol, int i, char **normal_array);
int is_numeric(char a);
char **postfix_expression_creator(char **normal_array);
int my_minus(int i, char const *str);
int add_zero(char digit, long long nb, int nb_min);


#endif
