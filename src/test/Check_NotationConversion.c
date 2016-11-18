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

START_TEST(test_converts_infix_order_of_operations_add_sub_1)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "bc-a+";
        const char *infix = "a+b-c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
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

/*START_TEST(test_converts_infix_order_of_operations_add_sub_3)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "ab-cd-+";
        const char *infix = "a-b+c-d";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST*/

START_TEST(test_converts_infix_order_of_operations_with_parens)
    {
        size_t buffer_size = 5;
        char result[buffer_size];

        const char *expected_rpn = "ab+c-";
        const char *infix = "(a+b)-c";

        convert_to_rpn(infix, result, buffer_size);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST


Suite *notation_conversion() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Notation Conversion");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_converts_infix_addition_1);
    tcase_add_test(tcase_core, test_converts_infix_addition_2);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_add_sub_1);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_add_sub_2);
//    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_add_sub_3);
    tcase_add_test(tcase_core, test_converts_infix_order_of_operations_with_parens);

    suite_add_tcase(suite, tcase_core);

    return suite;
}