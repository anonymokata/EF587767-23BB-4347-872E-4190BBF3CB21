#include <check.h>

#include <NotationConversion.h>
#include "CheckSuites.h"

START_TEST(test_converts_infix_addition_1)
    {
        char result[3];

        const char expected_rpn[] = "ab+";
        const char infix[] = "a+b";

        convert_to_rpn(infix, result, 3);

        ck_assert_str_eq(result, expected_rpn);
    }
END_TEST

START_TEST(test_converts_infix_addition_2)
    {
        char result[3];

        const char expected_rpn[] = "cb+f+";
        const char infix[] = "c+b+f";

        convert_to_rpn(infix, result, 5);

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

    suite_add_tcase(suite, tcase_core);

    return suite;
}