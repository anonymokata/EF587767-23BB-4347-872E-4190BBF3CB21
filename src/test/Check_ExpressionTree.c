#include <check.h>
#include <ExpressionTree.h>

#include "CheckSuites.h"

START_TEST(test_expression_tree_create)
    {
        ExpressionTree *tree = new_expression_tree(0);

        ck_assert_ptr_ne(NULL, tree);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_add_node_to_empty_tree)
    {
        char value1 = 'a';

        ExpressionTree *tree = new_expression_tree(2);
        add_node(tree, value1);

        ExpressionNode *root1 = get_root(tree);
        ck_assert_int_eq(value1, get_node_value(root1));
        ck_assert_int_eq(VARIABLE, get_node_type(root1));

        char value2 = '+';

        add_node(tree, value2);

        ExpressionNode *root2 = get_root(tree);
        ck_assert_int_eq(value2, get_node_value(root2));
        ck_assert_int_eq(OPERATOR, get_node_type(root2));

        ck_assert_ptr_eq(NULL, get_left_node(root2));
        ck_assert_ptr_eq(root1, get_right_node(root2));

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_print_post_order_addition)
    {
        const char *expected_rpn = "ab+";
        size_t buffer_size = 4;
        char result[buffer_size];

        ExpressionTree *tree = new_expression_tree(buffer_size - 1);
        add_node(tree, 'a');
        add_node(tree, 'b');
        add_node(tree, '+');

        print_post_order(tree, result, buffer_size);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_print_post_order_subtraction)
    {
        const char *expected_rpn = "ab-";
        size_t buffer_size = 4;
        char result[buffer_size];

        ExpressionTree *tree = new_expression_tree(buffer_size - 1);
        add_node(tree, 'a');
        add_node(tree, 'b');
        add_node(tree, '-');

        print_post_order(tree, result, buffer_size);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_print_post_order_addition_subtraction)
    {
        const char *expected_rpn = "ab-c+";
        size_t buffer_size = 6;
        char result[buffer_size];

        ExpressionTree *tree = new_expression_tree(buffer_size - 1);
        add_node(tree, 'a');
        add_node(tree, 'b');
        add_node(tree, '-');
        add_node(tree, 'c');
        add_node(tree, '+');

        print_post_order(tree, result, buffer_size);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_order_of_insertion_addition_subtraction)
    {
        const char *expected_rpn = "ab+c-";
        size_t buffer_size = 6;
        char result[buffer_size];

        ExpressionTree *tree = new_expression_tree(buffer_size - 1);
        add_node(tree, 'a');
        add_node(tree, 'b');
        add_node(tree, '+');
        add_node(tree, 'c');
        add_node(tree, '-');

        print_post_order(tree, result, buffer_size);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_order_of_ops_addition_subtraction_complicated)
    {
        const char *expected_rpn = "ab-cd-+";
        size_t buffer_size = 8;
        char result[buffer_size];

        ExpressionTree *tree = new_expression_tree(buffer_size - 1);
        add_node(tree, 'a');
        add_node(tree, 'b');
        add_node(tree, '-');
        add_node(tree, 'c');
        add_node(tree, 'd');
        add_node(tree, '-');
        add_node(tree, '+');

        print_post_order(tree, result, buffer_size);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_print_post_order_subtraction_multiplication)
    {
        const char *expected_rpn = "ab*c-";
        size_t buffer_size = 6;
        char result[buffer_size];

        ExpressionTree *tree = new_expression_tree(buffer_size - 1);
        add_node(tree, 'a');
        add_node(tree, 'b');
        add_node(tree, '*');
        add_node(tree, 'c');
        add_node(tree, '-');

        print_post_order(tree, result, buffer_size);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

Suite *expression_tree() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Expression Tree");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_expression_tree_create);
    tcase_add_test(tcase_core, test_expression_tree_add_node_to_empty_tree);
    tcase_add_test(tcase_core, test_expression_tree_print_post_order_addition);
    tcase_add_test(tcase_core, test_expression_tree_print_post_order_subtraction);
    tcase_add_test(tcase_core, test_expression_tree_print_post_order_addition_subtraction);
    tcase_add_test(tcase_core, test_expression_tree_order_of_insertion_addition_subtraction);
    tcase_add_test(tcase_core, test_expression_tree_order_of_ops_addition_subtraction_complicated);
    tcase_add_test(tcase_core, test_expression_tree_print_post_order_subtraction_multiplication);

    suite_add_tcase(suite, tcase_core);

    return suite;
}