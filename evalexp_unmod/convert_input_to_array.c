/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** yes
*/

#include "../include/eval_expr.h"
#include "../include/my.h"

int counts(char *str, struct first_malloc_sizes sizes)
{
    int res = 0;

    for (int counter = 0; counter < my_strlen(str); counter++) {
        if ((counter == 0 && str[counter] == '-') || (str[counter]
        == '-' && !is_numeric(str[counter - 1]))) {
            counter++;
            sizes.alloc_size++;
        }
        if (is_numeric(str[counter]) && is_numeric(str[counter + 1]) == 0 ) {
            res += 1;
            sizes.alloc_size++;
            sizes.alloc_array[sizes.position_on_alloc_array] =sizes.alloc_size;
            sizes.position_on_alloc_array++;
            sizes.alloc_size = 1;
        }
        if (is_numeric(str[counter]) == 0) {
            res += 1;
            sizes.alloc_array[sizes.position_on_alloc_array] = 2;
            sizes.position_on_alloc_array++;
            sizes.alloc_size = 0;
        }
        sizes.alloc_size++;
    }
    return (res);
}

void convert2(struct Arraycounters *counters, char *str)
{
    for (counters->counter4 = 0;is_numeric(str[counters->counter]);
    counters->counter4 = counters->counter4 + 1) {
        counters->returned[counters->counter1][counters->counter2]
        = str[counters->counter];
        counters->counter2 = counters->counter2 + 1;
        counters->counter = counters->counter + 1;
        counters->counter4 = counters->counter + 1;
        if (!is_numeric(str[counters->counter])) {
            counters->counter1 = counters->counter1 + 1;
            counters->counter2 = 0;
        }
    }
}

void convert1(struct Arraycounters *counters, char *str)
{
    for (counters->counter = 0; counters->counter
    < my_strlen(str); counters->counter++) {
        if ((counters->counter == 0 && str[counters->counter] == '-') ||
        (str[counters->counter] ==
        '-' && !is_numeric(str[counters->counter - 1]))) {
            counters->returned[counters->counter1][counters->counter2]
            = str[counters->counter];
            counters->counter2 = counters->counter2 + 1;
        } else if (!is_numeric(str[counters->counter])) {
            counters->returned[counters->counter1][counters->counter2]
            = str[counters->counter];
            counters->counter1 = counters->counter1 + 1;
        }
        convert2(counters, str);
        if (counters->counter4 > 0) {
            counters->counter4 = 0;
            counters->counter--;
        }
    }
}

char **convert_to_array(char *str)
{
    struct first_malloc_sizes sizes;
    sizes.alloc_array = malloc(sizeof(int) * my_strlen(str));
    sizes.alloc_size = 1;

    struct Arraycounters *counters = malloc(sizeof(*counters));
    counters->counter1 = 0;
    counters->counter2 = 0;
    counters->counter = 0;
    counters->counter4 = 0;
    counters->returned = NULL;
    counters->returned = malloc(sizeof(char *) * (counts(str, sizes) + 1));
    counters->returned[counts(str, sizes)] = NULL;
    for (counters->counter = 0; counters->counter
    < counts(str, sizes); counters->counter++) {
        counters->returned[counters->counter] =
        malloc(sizeof(char) * sizes.alloc_array[counters->counter]);
    }
    counters->counter = 0;
    convert1(counters, str);
    free (sizes.alloc_array);
    return (counters->returned);
}

char *eval_expr(char *str, char *base_num)
{
    char *new_str = inputcleaner(str);
    char **converted = convert_to_array(new_str);
    char *returned = 0;

    converted = postfix_expression_creator(converted);
    returned = postfix_expression_calculator(converted);
    returned = converted_num_base(returned, base_num);
    return (returned);
}