/*
** EPITECH PROJECT, 2021
** error_handling_bistro.c
** File description:
** error handling for bistro expr
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

int check_if_my_char_is_in_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return (0);
    }
    return (1);
}

int it_is_char_bistro(char c, char const *n, char const *s)
{
    if (c == n[0] || c == n[1] || c == n[2] ||
        c == n[3] || c == n[4] || c == n[5] ||
        c == n[6] || c == n[7] || c == n[8] ||
        c == n[9])
        return (0);
    if (c == s[0] || c == s[1] || c == s[2] ||
        c == s[3] || c == s[4] || c == s[5] ||
        c == s[6])
        return (0);
    return (1);
}

int check_expr_base_ops(char *expr, char *base, char *ops)
{
    int i = 0;
    int j = 0;

    for (int k = 0; base[k] != '\0'; k++) {
        if (check_if_my_char_is_in_str(base[k], ops) == 0)
            return (1);
    }
    while (expr[i] != '\0') {
        if (it_is_char_bistro(expr[i], base, ops) == 0)
            j++;
        i++;
    }
    if (i != j)
        return (1);
    return (0);
}

void check_error_bistro(char *expr, char *base, char *ops)
{
    if (check_expr_base_ops(expr, base, ops) == 1) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    if (check_matching_parenthesis(expr, ops[0], ops[1]) == 1) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    if (two_same_nb(base) == 1) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    if (two_same_nb(ops) == 1) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    if (par_sign(expr, ops)) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
}
