/*
** EPITECH PROJECT, 2020
** add_substract_utilities.c
** File description:
** Source file containing any utility functions pertaining to add_substract
*/

#include "../include/add_substract.h"
#include "../include/general_utilities.h"
#include "../include/my.h"

char *remove_zeros(char *str)
{
    int i;
    int str_len = my_strlen(str);

    if (str[str_len - 1] == '0')
        str_len--;
    for (i = 0; i < str_len; i++) {
        if (str[i] != '0')
            break;
    }
    return &str[i];
}

char *get_abs(char *str)
{
    char *cp ;
    int i = 0;

    if (str[0] == '-') {
        cp = malloc(sizeof(char) * (my_strlen(str) - 1));
        for (; str[i] != '\0';i++) {
            cp[i] = str[i+1];
        }
        cp[i] = '\0';
        return (cp);
    }
        return (str);
}