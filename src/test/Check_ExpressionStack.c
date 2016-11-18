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

START_TEST(test_expression_stack_pop_returns_in_reverse_push_order)
    {
        ExpressionNode *node1 = new_expression_node('a', VARIABLE);
        ExpressionNode *node2 = new_expression_node('b', VARIABLE);
        ExpressionNode *node3 = new_expression_node('c', VARIABLE);

        ExpressionStack *stack = new_expression_stack();

        push_node(stack, node1);
        push_node(stack, node2);
        push_node(stack, node3);

        ck_assert_ptr_eq(node3, pop_node(stack));
        ck_assert_ptr_eq(node2, pop_node(stack));
        ck_assert_ptr_eq(node1, pop_node(stack));

        free_expression_stack(stack);

        free_expression_node(node1);
        free_expression_node(node2);
        free_expression_node(node3);
    }
END_TEST


Suite *expression_stack() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Expression Stack");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_expression_stack_create);
    tcase_add_test(tcase_core, test_expression_stack_pop_returns_in_reverse_push_order);

    suite_add_tcase(suite, tcase_core);

    return suite;
}