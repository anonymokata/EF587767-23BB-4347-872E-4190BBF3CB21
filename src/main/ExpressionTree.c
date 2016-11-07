#include <stddef.h>
#include <stdlib.h>
#include "ExpressionTree.h"

struct ExpressionTree {
    ExpressionNode *root;
};

NodeType calculate_node_type(const char i);

ExpressionTree *new_expression_tree() {
    ExpressionTree *tree = malloc(sizeof(ExpressionTree));

    if (tree) {
        tree->root = NULL;
    }

    return tree;
}

void free_expression_tree(ExpressionTree *tree) {
    if (tree->root) {
        free_expression_node(tree->root);
    }

    free(tree);
}

void add_node(ExpressionTree *tree, const char value) {
    if (!tree->root) {
        tree->root = new_expression_node(value, calculate_node_type(value));
    }
}

ExpressionNode *get_root(ExpressionTree *tree) {
    return tree->root;
}


NodeType calculate_node_type(const char value) {
    if (value == '+') {
        return OPERATOR;
    }
    return VARIABLE;
}
