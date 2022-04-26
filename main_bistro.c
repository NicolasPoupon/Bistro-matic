/*
** EPITECH PROJECT, 2021
** main_bistro.c
** File description:
** main for bistromatic
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    if (read(0, expr, size) != size) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        write(2, "syntax error\n", 13);
        exit(84);
    }
}

static void print_usageh(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n\nDESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n- operators: ");
    my_putstr("the symbols for the parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usageh();
        return (0);
    }
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (84);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    check_error_bistro(expr, av[1], av[2]);
    my_putstr(eval_expr(expr, av[2], av[1]));
    return (0);
}
