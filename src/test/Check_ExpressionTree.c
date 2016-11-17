#include <check.h>
#include <ExpressionTree.h>

#include "CheckSuites.h"

START_TEST(test_expression_tree_create)
    {
        ExpressionTree *tree = new_expression_tree();

        ck_assert_ptr_ne(NULL, tree);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_add_node_to_empty_tree)
    {
        char value = 'a';

        ExpressionTree *tree = new_expression_tree();
        add_node(tree, value);

        ExpressionNode *root = get_root(tree);
        ck_assert_ptr_eq(NULL, root);

        free_expression_tree(tree);


        value = '+';

        tree = new_expression_tree();
        add_node(tree, value);

        root = get_root(tree);
        ck_assert_int_eq(value, get_node_value(root));
        ck_assert_int_eq(OPERATOR, get_node_type(root));

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_size)
    {
        ExpressionTree *tree = new_expression_tree();
        add_node(tree, 'a');
        add_node(tree, '+');
        add_node(tree, 'b');

        ck_assert_int_eq(3, get_tree_size(tree));

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_print_post_order_addition)
    {
        const char *expected_rpn = "ab+";
        char result[4];

        ExpressionTree *tree = new_expression_tree();
        add_node(tree, 'a');
        add_node(tree, '+');
        add_node(tree, 'b');

        print_post_order(tree, result);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_print_post_order_subtraction)
    {
        const char *expected_rpn = "ab-";
        char result[4];

        ExpressionTree *tree = new_expression_tree();
        add_node(tree, 'a');
        add_node(tree, '-');
        add_node(tree, 'b');

        print_post_order(tree, result);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_print_post_order_addition_subtraction)
    {
        const char *expected_rpn = "ab-c+";
        char result[6];

        ExpressionTree *tree = new_expression_tree();
        add_node(tree, 'a');
        add_node(tree, '-');
        add_node(tree, 'b');
        add_node(tree, '+');
        add_node(tree, 'c');

        print_post_order(tree, result);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_order_of_ops_addition_subtraction)
    {
        const char *expected_rpn = "abc-+";
        char result[6];

        ExpressionTree *tree = new_expression_tree();
        add_node(tree, 'a');
        add_node(tree, '+');
        add_node(tree, 'b');
        add_node(tree, '-');
        add_node(tree, 'c');

        print_post_order(tree, result);

        ck_assert_str_eq(expected_rpn, result);

        free_expression_tree(tree);
    }
END_TEST

START_TEST(test_expression_tree_order_of_ops_addition_subtraction_complicated)
    {
        const char *expected_rpn = "ab-cd-+e+f+";
        char result[12];

        ExpressionTree *tree = new_expression_tree();
        add_node(tree, 'a');
        add_node(tree, '-');
        add_node(tree, 'b');
        add_node(tree, '+');
        add_node(tree, 'c');
        add_node(tree, '-');
        add_node(tree, 'd');
        add_node(tree, '+');
        add_node(tree, 'e');
        add_node(tree, '+');
        add_node(tree, 'f');

        print_post_order(tree, result);

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
    tcase_add_test(tcase_core, test_expression_tree_size);
    tcase_add_test(tcase_core, test_expression_tree_print_post_order_addition);
    tcase_add_test(tcase_core, test_expression_tree_print_post_order_subtraction);
    tcase_add_test(tcase_core, test_expression_tree_print_post_order_addition_subtraction);
    tcase_add_test(tcase_core, test_expression_tree_order_of_ops_addition_subtraction);
    tcase_add_test(tcase_core, test_expression_tree_order_of_ops_addition_subtraction_complicated);

    suite_add_tcase(suite, tcase_core);

    return suite;
}