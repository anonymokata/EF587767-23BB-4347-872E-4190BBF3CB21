#include <check.h>
#include <NotationConversion.h>

#include "CheckSuites.h"

START_TEST(test_converts_infix_addition_1)
    {
        size_t buffer_size = 3;
        char result[buffer_size];

        const char *expected_rpn = "ab+";
        const char *infix = "a+b";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_rpn_addition_1)
    {
        size_t buffer_size = 3;
        char result[buffer_size];

        const char *expected_infix = "a+b";
        const char *rpn = "ab+";

        convert_to_infix(rpn, result, buffer_size);

        ck_assert_str_eq(result, expected_infix);
    }
END_TEST

START_TEST(test_converts_infix_addition_2)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "cd+e+";
        const char *infix = "c+d+e";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_rpn_addition_2)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_infix = "c+d+e";
        const char *rpn = "cd+e+";

        convert_to_infix(rpn, result, buffer_size);

        ck_assert_str_eq(result, expected_infix);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_add_sub_1)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "abc-+";
        const char *infix = "a+b-c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_rpn_order_of_operations_add_sub_1)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_infix = "a+b-c";
        const char *rpn = "abc-+";

        convert_to_infix(rpn, result, buffer_size);

        ck_assert_str_eq(result, expected_infix);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_add_sub_2)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "ab-c+";
        const char *infix = "a-b+c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_rpn_order_of_operations_add_sub_2)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_infix = "a-b+c";
        const char *rpn = "ab-c+";

        convert_to_infix(rpn, result, buffer_size);

        ck_assert_str_eq(result, expected_infix);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_add_sub_3)
    {
        size_t buffer_size = 7;
        char result[buffer_size];

        const char *expected_rpn = "ab-cd-+";
        const char *infix = "a-b+c-d";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_rpn_order_of_operations_add_sub_3)
    {
        size_t buffer_size = 7;
        char result[buffer_size];

        const char *expected_infix = "a-b+c-d";
        const char *rpn = "ab-cd-+";

        convert_to_infix(rpn, result, buffer_size);

        ck_assert_str_eq(result, expected_infix);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_add_sub_with_parens)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "ab+c-";
        const char *infix = "(a+b)-c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_sub_multi_1)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "abc*-";
        const char *infix = "a-b*c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_sub_multi_with_parens)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "ab-c*";
        const char *infix = "(a-b)*c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_multi_div_1)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "abc/*";
        const char *infix = "a*b/c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_multi_div_with_parens)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "ab*c/";
        const char *infix = "(a*b)/c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_div_exp_1)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "abc/*";
        const char *infix = "a*b/c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_div_exp_with_parens)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "ab/c^";
        const char *infix = "(a/b)^c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_all_operators_1)
    {
        size_t buffer_size = 11;
        char result[buffer_size];

        const char *expected_rpn = "lmn^/o*ap-+";
        const char *infix = "l/m^n*o+a-p";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_all_operators_2)
    {
        size_t buffer_size = 11;
        char result[buffer_size];

        const char *expected_rpn = "lmn^/oa+*p-";
        const char *infix = "l/m^n*(o+a)-p";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_order_of_operations_all_operators_3)
    {
        size_t buffer_size = 17;
        char result[buffer_size];

        const char *expected_rpn = "ag+ba-c+cedf^*+^*";
        const char *infix = "(a+g)*(b-a+c)^(c+e*d^f)";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_compare_precedence_addition_and_addition)
    {
        char addition_op = '+';

        ck_assert_int_eq(0, compare_precedence(addition_op, addition_op));
    }
END_TEST

START_TEST(test_compare_precedence_addition_and_subtraction)
    {
        char addition_op = '+';
        char subtraction_op = '-';

        ck_assert_int_eq(-1, compare_precedence(addition_op, subtraction_op));
        ck_assert_int_eq(1, compare_precedence(subtraction_op, addition_op));
    }
END_TEST

START_TEST(test_compare_precedence_subtraction_and_subtraction)
    {
        char subtraction_op = '-';

        ck_assert_int_eq(0, compare_precedence(subtraction_op, subtraction_op));
    }
END_TEST

START_TEST(test_compare_precedence_subtraction_and_multiplication)
    {
        char subtraction_op = '-';
        char multiplication_op = '*';

        ck_assert_int_eq(-1, compare_precedence(subtraction_op, multiplication_op));
        ck_assert_int_eq(1, compare_precedence(multiplication_op, subtraction_op));
    }
END_TEST

START_TEST(test_compare_precedence_multiplication_and_multiplication)
    {
        char multiplication_op = '*';

        ck_assert_int_eq(0, compare_precedence(multiplication_op, multiplication_op));
    }
END_TEST

START_TEST(test_compare_precedence_multiplication_and_division)
    {
        char multiplication_op = '*';
        char division_op = '/';

        ck_assert_int_eq(-1, compare_precedence(multiplication_op, division_op));
        ck_assert_int_eq(1, compare_precedence(division_op, multiplication_op));
    }
END_TEST


Suite *notation_conversion() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Notation Conversion");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_converts_infix_addition_1);
    tcase_add_test(tcase_core, test_converts_rpn_addition_1);

    tcase_add_test(tcase_core, test_converts_infix_addition_2);
    tcase_add_test(tcase_core, test_converts_rpn_addition_2);

    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_add_sub_1);
    tcase_add_test(tcase_core, test_converts_rpn_order_of_operations_add_sub_1);

    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_add_sub_2);
    tcase_add_test(tcase_core, test_converts_rpn_order_of_operations_add_sub_2);

    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_add_sub_3);
    tcase_add_test(tcase_core, test_converts_rpn_order_of_operations_add_sub_3);

    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_add_sub_with_parens);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_sub_multi_1);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_sub_multi_with_parens);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_multi_div_1);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_multi_div_with_parens);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_div_exp_1);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_div_exp_with_parens);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_all_operators_1);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_all_operators_2);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_all_operators_3);

    tcase_add_test(tcase_core, test_compare_precedence_addition_and_addition);
    tcase_add_test(tcase_core, test_compare_precedence_addition_and_subtraction);

    tcase_add_test(tcase_core, test_compare_precedence_subtraction_and_subtraction);
    tcase_add_test(tcase_core, test_compare_precedence_subtraction_and_multiplication);

    tcase_add_test(tcase_core, test_compare_precedence_multiplication_and_multiplication);
    tcase_add_test(tcase_core, test_compare_precedence_multiplication_and_division);

    suite_add_tcase(suite, tcase_core);

    return suite;
}