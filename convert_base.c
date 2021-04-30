/*
** EPITECH PROJECT, 2020
** convert-base
** File description:
** File to converte base and operator
*/

#include "include/my.h"
#include <stdio.h>

char *converted_base_ope(char *str, char *base_ope)
{
    char *const normal_base = "()+-*/%";
    char *cp = my_strdup(str);
    int j = 0;

    for (int i = 0; i < 8; i++) {
        for (j = 0; j <= my_strlen(str); j++) {
            if (cp[j] == base_ope[i])
                cp[j] = normal_base[i];
        }
        j = 0 ;
    }
    cp[my_strlen(str)] = '\0';
    return cp;
}

char *converted_base_num(char *str, char *base_num)
{
    char *const normal_base = "0123456789";
    char *cp = my_strdup(str);
    int j = 0;

    for (int i = 0; i < 11; i++) {
        for (j = 0; j <= my_strlen(str); j++) {
            if (cp[j] == base_num[i])
                cp[j] = normal_base[i];
        }
        j = 0 ;
    }
    cp[my_strlen(str)] = '\0';
    return cp;
}

char *converted_num_base (char *str, char *base_num)
{
    char *const normal_base = "0123456789";
    char *cp = my_strdup(str);
    int j = 0;

    for (int i = 0; i < 11; i++) {
        for (j = 0; j <= my_strlen(str); j++) {
            if (normal_base[i] == cp[j])
                cp[j] = base_num[i];
        }
        j = 0 ;
    }
    cp[my_strlen(str)] = '\0';
    return cp;
}