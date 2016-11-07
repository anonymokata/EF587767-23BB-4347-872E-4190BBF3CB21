#include <stddef.h>
#include <stdlib.h>
#include "ExpressionTree.h"

struct ExpressionTree {
    ExpressionNode *root;
};

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
        tree->root = new_expression_node('a', VARIABLE);
    }
}

ExpressionNode *get_root(ExpressionTree *tree) {
    return tree->root;
}
