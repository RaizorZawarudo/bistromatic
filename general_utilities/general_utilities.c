/*
** EPITECH PROJECT, 2020
** general_utilities.c
** File description:
** .
*/

#include "../include/my.h"
#include "../include/general_utilities.h"

char *append_digit(char digit, char *dest)
{
    char *temp = my_strdup(dest);
    int dest_len = my_strlen(dest);

    if (dest_len == 0) {
        dest = malloc(sizeof(char) * (dest_len + 2));
        dest[0] = digit;
        dest[1] = '\0';
        return dest;
    } else{
        dest = malloc(sizeof(char) * (dest_len + 2));
        dest[0] = digit;
        for (int i = 0; i < dest_len; i++) {
            dest[i + 1] = temp[i];
        }
    }
    free(temp);
    dest[dest_len + 1] = '\0';
    return dest;
}

int get_digit(char c)
{
    if (c >= '0' && c <= '9')
        return c - 48;
    else
        return -1;
}

int is_largest(char *input1, char *input2)
{
    int input1_len = my_strlen(input1);
    int input2_len = my_strlen(input2);
    int i;

    if (input1_len == input2_len) {
        for (i = 0; input1[i] == input2[i] && input1[i] 
        != '\0' && input2[i] != '\0'; i++);
        if (get_digit(input1[i]) >= get_digit(input2[i]))
                return 1;
            else
                return 0;
    }
    if (input1_len > input2_len)
        return 1;
    else
        return 0;
}