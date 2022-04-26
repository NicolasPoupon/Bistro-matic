/*
** EPITECH PROJECT, 2021
** fct_evalexpr.c
** File description:
** fct of evalexpr
*/

#include "include/my.h"
#include <stdlib.h>

int pos_start_nb1(char *src, int pos_op, char minus)
{
    int i = pos_op - 1;

    while (it_is_num(src[i]) == 0 || src[i] == minus) {
        if (i == 0)
            return (0);
        i--;
    }
    return (i + 1);
}

int pos_end_nb2(char *src, int pos_op, char minus)
{
    int i = pos_op + 1;

    if (src[i] == minus)
        i++;
    while (it_is_num(src[i]) == 0) {
        if (src[i + 1] == '\0')
            return (my_strlen(src) - 1);
        i++;
    }
    return (i - 1);
}

char *fill_after_par(char *src, int pos_l_par, char *after_par)
{
    after_par = malloc(sizeof(char) * (pos_l_par + 1));
    if (after_par == NULL)
        return (NULL);
    after_par = my_strncpy_rev(after_par, src, pos_l_par + 1);
    return (after_par);
}

char *fill_before_par(char *src, int pos_f_par, char *before_par)
{
    before_par = malloc(sizeof(char) * (pos_f_par + 1));
    if (before_par == NULL)
        return (NULL);
    before_par = my_strncpy(before_par, src, pos_f_par);
    return (before_par);
}

int *find_first_parent_to_calc(char *src, int *pos_parent, char const *sign)
{
    int closed_parent = 0;
    int opened_parent = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == sign[1] && closed_parent == 0)
            closed_parent = i;
    }
    for (int j = closed_parent; j > 0; j--) {
        if (src[j] == sign[0] && opened_parent == 0)
            opened_parent = j;
    }
    pos_parent[0] = opened_parent;
    pos_parent[1] = closed_parent;
    return (pos_parent);
}
