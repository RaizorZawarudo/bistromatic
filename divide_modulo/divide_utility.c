/*
** EPITECH PROJECT, 2020
** divide_utility.c
** File description:
** .
*/
#include <stdlib.h>
#include "../include/my.h"

char *append_char(char *dest, char character)
{
    int dest_len = my_strlen(dest);
    char *temp = my_strdup(dest);
    dest = malloc(sizeof(char) * (dest_len + 2));

    dest = my_strcpy(dest, temp);
    dest[dest_len] = character;
    dest[dest_len + 1] = '\0';
    return dest;
}

char *int_to_string(int input)
{
    char *output = my_strdup("");
    int length = 0;
    int first_iteration = 1;

    while (input != 0 || first_iteration) {
        if (first_iteration)
            first_iteration = 0;
        output = append_char(output, input % 10 + 48);
        length++;
        input /= 10;
    }
    output = my_revstr(output);
    output = append_char(output, '\0');
    return output;
}

int str_n(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] != '0')
            return 0;
    return 1;
}