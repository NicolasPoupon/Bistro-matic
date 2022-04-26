/*
** EPITECH PROJECT, 2021
** calc_str_without_parent.c
** File description:
** calc str and return int
*/

#include "include/my.h"
#include <stdlib.h>

char find_pos_calc_and_sign(char *src, int *pos_my_calc, char const *sign)
{
    int pos_op = 0;
    char my_sign;

    for (int i = 0; src[i] != '\0'; i++) {
        if (it_is_prio_sign_bistro(src[i], sign) == 0 && pos_op == 0)
            pos_op = i;
    }
    if (pos_op == 0)
        pos_op = where_is_sign(src, sign);
    my_sign = find_my_sign(src[pos_op], sign);
    pos_my_calc[0] = pos_start_nb1(src, pos_op, sign[3]);
    pos_my_calc[1] = pos_end_nb2(src, pos_op, sign[3]);
    pos_my_calc[2] = pos_op;
    return (my_sign);
}

char *do_my_op(char sign, int *pos_my_calc, char *res, char *src)
{
    char *nb1 = my_strndup(src, pos_my_calc[0], pos_my_calc[2]);
    char *nb2 = my_strndup(src, pos_my_calc[2] + 1, pos_my_calc[1] + 1);

    if (sign == '+')
        res = my_infin_add(nb1, nb2, res);
    if (sign == '-')
        res = my_true_infin_sub(nb1, nb2, res);
    if (sign == '*')
        res = my_infin_mult(nb1, nb2, res);
    if (sign == '/')
        res = my_infin_div(nb1, nb2, res);
    if (sign == '%')
        res = my_infin_modulo(nb1, nb2, res);
    return (res);
}

char *replace_op_by_res(char *src, char *res, int *pos_my_calc)
{
    int len_op = pos_my_calc[1] - pos_my_calc[0];
    int len_newsrc = my_strlen(src) - len_op + my_strlen(res);
    char *n_src = my_strdup(src);

    free(src);
    src = malloc(sizeof(char) * (len_newsrc + 1));
    src = my_strncpy(src, n_src, pos_my_calc[0]);
    src = my_strcat(src, res);
    src = my_strcat(src, my_strncpy_rev(n_src, n_src, pos_my_calc[1] + 1));
    free(n_src);
    return (src);
}

int there_is_op(char *str, char const *sign)
{
    for (int i = 1; str[i] != '\0'; i++) {
        if (it_is_a_sign_bistro(str[i], sign) == 0)
            return (0);
    }
    return (1);
}

char *calc_my_str_withoutpar(char *my_calcp, char *res, char const *sign)
{
    char *src = my_strdup(my_calcp);
    int pos_my_calc[3];
    char my_sign = find_pos_calc_and_sign(src, pos_my_calc, sign);

    free(my_calcp);
    res = do_my_op(my_sign, pos_my_calc, res, src);
    src = replace_op_by_res(src, res, pos_my_calc);
    free(res);
    return (src);
}
