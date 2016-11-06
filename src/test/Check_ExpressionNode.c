#include <check.h>
#include <ExpressionNode.h>

#include "CheckSuites.h"

START_TEST(test_expression_node_create_1)
    {
        char c = 'a';
        NodeType type = VARIABLE;
        ExpressionNode *expression_node = new_expression_node(c, type);

        ck_assert_int_eq(c, get_value(expression_node));
        ck_assert_int_eq(type, get_type(expression_node));

        free_expression_node(expression_node);
    }
END_TEST

START_TEST(test_expression_node_create_2)
    {
        char c = '+';
        NodeType type = OPERATOR;
        ExpressionNode *expression_node = new_expression_node(c, type);

        ck_assert_int_eq(c, get_value(expression_node));
        ck_assert_int_eq(type, get_type(expression_node));

        free_expression_node(expression_node);
    }
END_TEST

START_TEST(test_node_set_left_and_right_1)
    {
        ExpressionNode *left_node = new_expression_node('a', VARIABLE);
        ExpressionNode *right_node = new_expression_node('b', VARIABLE);

        ExpressionNode *root_node = new_expression_node('+', OPERATOR);
        set_left_node(root_node, left_node);
        set_right_node(root_node, right_node);

        ck_assert_ptr_eq(left_node, get_left_node(root_node));
        ck_assert_ptr_eq(right_node, get_right_node(root_node));

        free_expression_node(root_node);
    }
END_TEST

START_TEST(test_node_set_left_and_right_2)
    {
        ExpressionNode *left_node = new_expression_node('c', VARIABLE);
        ExpressionNode *right_node = new_expression_node('d', VARIABLE);

        ExpressionNode *root_node = new_expression_node('^', OPERATOR);
        set_left_node(root_node, left_node);
        set_right_node(root_node, right_node);

        ck_assert_ptr_eq(left_node, get_left_node(root_node));
        ck_assert_ptr_eq(right_node, get_right_node(root_node));

        free_expression_node(root_node);
    }
END_TEST

Suite *expression_node() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Expression Node");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_expression_node_create_1);
    tcase_add_test(tcase_core, test_expression_node_create_2);
    tcase_add_test(tcase_core, test_node_set_left_and_right_1);
    tcase_add_test(tcase_core, test_node_set_left_and_right_2);

    suite_add_tcase(suite, tcase_core);

    return suite;
}