/*
** EPITECH PROJECT, 2021
** evalexpr.c
** File description:
** evalexpr for bistro
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

int where_is_sign(char *src, char const *sign)
{
    int pos_op = 0;

    for (int i = 1; src[i] != '\0'; i++) {
        if ((src[i] == sign[2] || src[i] == sign[3]) && pos_op == 0)
            pos_op = i;
    }
    return (pos_op);
}

char *replace_parent_by_res(char *res, char *src, int *pos_parent)
{
    char *before_par = fill_before_par(src, pos_parent[0], before_par);
    char *after_par = fill_after_par(src, pos_parent[1], after_par);
    int len = my_strlen(before_par) + my_strlen(after_par) + my_strlen(res);

    free(src);
    src = malloc(sizeof(char) * (len + 1));
    my_strcpy(src, before_par);
    my_strcat(src, res);
    my_strcat(src, after_par);
    free(before_par);
    free(res);
    free(after_par);
    return (src);
}

char *replace_parent(char *str, char const *sign)
{
    char *src = my_strdup(str);
    int pos_parent[2];
    int pos_first_parent = 0;
    int	pos_sec_parent = 0;
    char *my_calcp;
    char *res;

    find_first_parent_to_calc(src, pos_parent, sign);
    pos_first_parent = pos_parent[0];
    pos_sec_parent = pos_parent[1];
    my_calcp = my_strndup(str, pos_first_parent + 1, pos_sec_parent);
    while (there_is_op(my_calcp, sign) == 0)
        my_calcp = calc_my_str_withoutpar(my_calcp, res, sign);
    src = replace_parent_by_res(my_calcp, src, pos_parent);
    return (src);
}

void is_it_short_expr(char const *str, char const *sign)
{
    int count_nb_par = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sign[0])
            count_nb_par++;
    }
    if (count_nb_par >= 5) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
}

char *eval_expr(char const *str, char const *sign, char *key_base)
{
    char *calc = my_strdup(str);
    char *res;

    is_it_short_expr(str, sign);
    calc = decrypt_str_with_key(calc, key_base);
    while (is_there_parent_in_str(calc, sign[0]) == 0) {
        if (is_there_parent_in_str(calc, sign[0]) == 0) {
            calc = replace_parent(calc, sign);
        }
    }
    while (there_is_op(calc, sign) == 0)
        calc = calc_my_str_withoutpar(calc, res, sign);
    calc = encrypt_str_with_key(calc, key_base);
    return (calc);
}
