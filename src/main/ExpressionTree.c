#include <stddef.h>
#include <stdlib.h>

#include "ExpressionTree.h"

struct ExpressionTree {
    ExpressionNode *root;
    ExpressionNode *temp;
};

NodeType calculate_node_type(const char i);

void traverse_tree_post_order(ExpressionNode *node, char *buffer, int *pos);

void set_root(ExpressionTree *tree, ExpressionNode *new_node);

void set_temp(ExpressionTree *tree, ExpressionNode *new_node);

ExpressionTree *new_expression_tree() {
    ExpressionTree *tree = malloc(sizeof(ExpressionTree));

    if (tree) {
        tree->root = NULL;
        tree->temp = NULL;
    }

    return tree;
}

void free_expression_tree(ExpressionTree *tree) {
    if (tree->root) {
        free_expression_node(tree->root);
        tree->root = NULL;
    } else if (tree->temp) {
        free_expression_node(tree->temp);
        tree->temp = NULL;
    }

    free(tree);
}

void add_node(ExpressionTree *tree, const char value) {
    NodeType type = calculate_node_type(value);
    ExpressionNode *new_node = new_expression_node(value, type);

    if (!tree->root) {
        if (type == OPERATOR) {
            set_root(tree, new_node);
            set_right_node(new_node, tree->temp);
            set_temp(tree, NULL);
        } else {
            set_temp(tree, new_node);
        }
        return;
    }

    if (type == OPERATOR) {
        set_left_node(new_node, tree->root);
        set_right_node(new_node, tree->temp);

        set_root(tree, new_node);
        set_temp(tree, NULL);
    } else {
        if (get_left_node(tree->root) == NULL) {
            set_left_node(tree->root, new_node);
        } else if (get_right_node(tree->root) == NULL) {
            set_right_node(tree->root, new_node);
        } else {
            set_temp(tree, new_node);
        }
    }

}

void set_root(ExpressionTree *tree, ExpressionNode *new_node) {
    tree->root = new_node;
}

void set_temp(ExpressionTree *tree, ExpressionNode *new_node) {
    tree->temp = new_node;
}

NodeType calculate_node_type(const char value) {
    if (value == '+' || value == '-') {
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

void print_post_order(ExpressionTree *tree, char *buffer, size_t buffer_size) {
    int pos = 0;
    traverse_tree_post_order(tree->root, buffer, &pos);
    buffer[buffer_size - 1] = '\0';
}

void traverse_tree_post_order(ExpressionNode *node, char *buffer, int *pos) {
    if (node) {
        traverse_tree_post_order(get_left_node(node), buffer, pos);
        traverse_tree_post_order(get_right_node(node), buffer, pos);

        buffer[*pos] = get_node_value(node);
        (*pos)++;
    }
}
