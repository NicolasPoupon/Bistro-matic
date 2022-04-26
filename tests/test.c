/*
** EPITECH PROJECT, 2021
** evalexp_rep
** File description:
** test_eval_epr
*/

#include <criterion/criterion.h>
#include "../include/my.h"

int check_matching_parenthesis(char *str, char open_par, char end);

int check_expr_base_ops(char *expr, char *base, char *ops);

int check_if_my_char_is_in_str(char c, char *str);

int it_is_char_bistro(char c, char const *n, char const *s);

char *replace_parent(char *str, char const *sign);

Test(there_is_op, one_sign)
{
    cr_assert_eq(there_is_op("30+30", "()+-*/%"), 0);
}

Test(there_is_op, one_sign_mod)
{
    cr_assert_eq(there_is_op("30c30", "abcdefg"), 0);
}

Test(there_is_op, no_sign)
{
    cr_assert_eq(there_is_op("3030", "()+-*/%"), 1);
}

Test(there_is_op, no_sign_mod)
{
    cr_assert_eq(there_is_op("30+30", "abcdefg"), 1);
}

Test(there_is_op, sign_start_of_str)
{
    cr_assert_eq(there_is_op("+3030", "()+-*/%"), 1);
}

Test(check_expr_base_ops, test01)
{
    char *expr = "2+4*7";
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert_eq(check_expr_base_ops(expr, base, ops), 0);
}

Test(check_expr_base_ops, test02)
{
    char *expr = "2+4*a";
    char *base = "0123456789";
    char *ops = "(+-)*/%";

    cr_assert_eq(check_expr_base_ops(expr, base, ops), 1);
}

Test(check_if_my_char_is_in_str, test01)
{
    char c = 'i';
    char *str = "titi";

    cr_assert_eq(check_if_my_char_is_in_str(c, str), 0);
}

Test(check_if_my_char_is_in_str, test02)
{
    char c = 'i';
    char *str = "hello";

    cr_assert_eq(check_if_my_char_is_in_str(c, str), 1);
}

Test(it_is_char_bistro, test01)
{
    char c = 'a';
    char const *n = "0123456789";
    char const *s = "()+-%*/";

    cr_assert_eq(it_is_char_bistro(c, n, s), 1);
}

Test(it_is_char_bistro, test02)
{
    char c = '2';
    char const *n = "0123456789";
    char const *s = "()+-%/*";

    cr_assert_eq(it_is_char_bistro(c, n, s), 0);
}

Test(check_par, test01)
{
    char *str = "(6+4)*(4-7%2)";
    char open_par = '(';
    char end = ')';

    cr_assert_eq(check_par(str, open_par, end), 0);
}

Test(check_par, test02)
{
    char *str = "((2+3)";
    char open_par = '(';
    char end = ')';

    cr_assert_eq(check_par(str, open_par, end), 1);
}

Test(check_matching_parenthesis, test01)
{
    char *str = "2+3)";
    char open_par = '(';
    char end = ')';

    cr_assert_eq(check_matching_parenthesis(str, open_par, end), 1);
}

Test(check_matching_parenthesis, test02)
{
    char *str = "((2+3))";
    char open_par = '(';
    char end = ')';

    cr_assert_eq(check_matching_parenthesis(str, open_par, end), 0);
}

Test(two_same_nb, test01)
{
    char *base = "0123476789";

    cr_assert_eq(two_same_nb(base), 1);
}

Test(two_same_nb, test02)
{
    char *base = "0123456789";

    cr_assert_eq(two_same_nb(base), 0);
}

Test(par_sign, test01)
{
    char *str = "(4-2)(9+4)";
    char *ops = "()+-/%*";

    cr_assert_eq(par_sign(str, ops), 1);
}

Test(par_sign, test02)
{
    char *str = "(2+3)-(4*3)";
    char *ops = "()+-/%*";

    cr_assert_eq(par_sign(str, ops), 0);
}

Test(is_there_parent_in_str, test01)
{
    char *str = "abcde";
    char sign = 'a';

    cr_assert_eq(is_there_parent_in_str(str, sign), 0);
}

Test(is_there_parent_in_str, test02)
{
    char *str = "abcde";
    char sign = 'g';

    cr_assert_eq(is_there_parent_in_str(str, sign), 1);
}

Test(where_is_sign, test01)
{
    char *src = "2-6";
    char const *sign = "()+-%/*";

    cr_assert_eq(where_is_sign(src, sign), 1);
}

Test(where_is_sign, test02)
{
    char *src = "2*7";
    char const *sign = "()+-/*%";

    cr_assert_eq(where_is_sign(src, sign), 0);
}

Test(it_is_prio_sign_bistro, test01)
{
    char c = '(';
    char const *s = "()+-*/%";

    cr_assert_eq(it_is_prio_sign_bistro(c, s), 1);
}

Test(it_is_prio_sign_bistro, test02)
{
    char c = '*';
    char const *s = "()+-*/%";

    cr_assert_eq(it_is_prio_sign_bistro(c, s), 0);
}

Test(it_is_a_sign_bistro, test01)
{
    char c = '(';
    char const *s = "()+-/*%";

    cr_assert_eq(it_is_a_sign_bistro(c, s), 1);
}

Test(it_is_a_sign_bistro, test02)
{
    char c = '+';
    char const *s = "()+-/*%";

    cr_assert_eq(it_is_a_sign_bistro(c, s), 0);
}

Test(find_my_sign, test01)
{
    char c = 'v';
    char const *s = "[]vmf%s";

    cr_assert_eq(find_my_sign(c , s), '+');
}

Test(find_my_sign, test02)
{
    char c = 'f';
    char const *s = "[]vmf%s";

    cr_assert_eq(find_my_sign(c , s), '*');
}

Test(find_smallest_strm, test01)
{
    char *str1 = "helloooo";
    char *str2 = "world";

    cr_assert_eq(find_smallest_strm(str1, str2), str2);
}

Test(find_smallest_strm, test02)
{
    char *str1 = "hello";
    char *str2 = "worldahahah";

    cr_assert_eq(find_smallest_strm(str1, str2), str1);
}

Test(find_bigger_str_min, test01)
{
    char *str1 = "hello";
    char *str2 = "worldddd";

    cr_assert_eq(find_bigger_str_min(str1, str2), str2);
}

Test(find_bigger_str_min, test02)
{
    char *str1 = "helloooo";
    char *str2 = "world";

    cr_assert_eq(find_bigger_str_min(str1, str2), str1);
}
