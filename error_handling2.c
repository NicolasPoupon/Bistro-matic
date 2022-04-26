/*
** EPITECH PROJECT, 2021
** check par
** File description:
** error handling
*/

#include <stdio.h>
#include "include/my.h"
#include <stdlib.h>

int check_par(char *str, char open_par, char end)
{
    int comp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == open_par) {
            comp++;
        }
        if (str[i] == end) {
            comp--;
        }
    }
    if (comp != 0) {
        return (1);
    }
    return (0);
}

int check_matching_parenthesis(char *str, char open_par, char end)
{
    int comp = 0;
    int len = my_strlen(str);

    check_par(str, open_par, end);
    for (int j = len - 1; j >= 0; j--) {
        if (str[j] == end) {
            comp++;
        }
        if (str[j] == open_par) {
            comp--;
        }
    }
    if (comp != 0) {
        return (1);
    }
    return (0);
}

int two_same_nb2(char *base, int i, int comp)
{
    for (int j = i + comp; base[j] != '\0'; j++) {
        comp++;
        if (base[i] == base[j]) {
            return (1);
        }
        comp = 1;
    }
    return (0);
}

int two_same_nb(char *base)
{
    int comp = 1;

    for (int i = 0; base[i] != '\0'; i++) {
        if (two_same_nb2(base, i, comp) == 1)
            return (1);
    }
    return (0);
}

int par_sign(char *str, char *ops)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i + 1] == ops[0]) && (str[i] != ops[0] &&
                                       str[i] != ops[2] &&
                                       str[i] != ops[3] &&
                                       str[i] != ops[4] &&
                                       str[i] != ops[5] &&
                                       str[i] != ops[6]))
            return (1);
    }
    return (0);
}
