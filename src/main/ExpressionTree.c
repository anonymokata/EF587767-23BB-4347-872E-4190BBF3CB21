#include <stddef.h>
#include <stdlib.h>
#include "ExpressionTree.h"

struct ExpressionTree {
    ExpressionNode *root;
};

NodeType calculate_node_type(const char i);

void traverse_tree_post_order(ExpressionNode *node, char **buffer);

ExpressionTree *new_expression_tree() {
    ExpressionTree *tree = malloc(sizeof(ExpressionTree));

    if (tree) {
        tree->root = NULL;
    }

    return tree;
}

void free_expression_tree(ExpressionTree *tree) {
    if (tree->root != NULL) {
        free_expression_node(tree->root);
    }

    free(tree);
}

void add_node(ExpressionTree *tree, const char value) {
    NodeType type = calculate_node_type(value);
    ExpressionNode *new_node = new_expression_node(value, type);

    if (!tree->root) {
        tree->root = new_node;
        return;
    }

    if (type == OPERATOR) {
        ExpressionNode *old_root = tree->root;
        tree->root = new_node;
        set_left_node(tree->root, old_root);
    } else {
        set_right_node(tree->root, new_node);
    }
}

NodeType calculate_node_type(const char value) {
    if (value == '+') {
        return OPERATOR;
    }
    return VARIABLE;
}

ExpressionNode *get_root(ExpressionTree *tree) {
    return tree->root;
}

int get_tree_size(ExpressionTree *tree) {
    return get_node_count(tree->root);
}

void print_post_order(ExpressionTree *tree, char *buffer) {
    traverse_tree_post_order(tree->root, &buffer);
}

void traverse_tree_post_order(ExpressionNode *node, char **buffer) {
    if (node) {
        traverse_tree_post_order(get_left_node(node), buffer);
        traverse_tree_post_order(get_right_node(node), buffer);

        (**buffer) = get_node_value(node);
        (*buffer)++;
    }
}
