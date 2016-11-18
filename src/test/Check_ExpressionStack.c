#include <check.h>
#include <ExpressionStack.h>

#include "CheckSuites.h"

START_TEST(test_expression_stack_create)
    {
        ExpressionStack *stack = new_expression_stack();

        ck_assert_ptr_ne(NULL, stack);

        free_expression_stack(stack);
    }
END_TEST


Suite *expression_stack() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Expression Stack");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_expression_stack_create);

    suite_add_tcase(suite, tcase_core);

    return suite;
}