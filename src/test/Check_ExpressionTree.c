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
        ck_assert_int_eq(value, get_node_value(root));
        ck_assert_int_eq(VARIABLE, get_node_type(root));

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


Suite *expression_tree() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Expression Tree");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_expression_tree_create);
    tcase_add_test(tcase_core, test_expression_tree_add_node_to_empty_tree);

    suite_add_tcase(suite, tcase_core);

    return suite;
}