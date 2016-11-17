#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ExpressionTree.h"

struct ExpressionTree {
    ExpressionNode *root;
    ExpressionNode *last;
};

NodeType calculate_node_type(const char i);

void traverse_tree_post_order(ExpressionNode *node, char *buffer, int *pos);

bool is_new_operator_higher_precedence(ExpressionNode *pNode, ExpressionNode *pExpressionNode);

int operator_precedence(ExpressionNode *node);

ExpressionTree *new_expression_tree() {
    ExpressionTree *tree = malloc(sizeof(ExpressionTree));

    if (tree) {
        tree->root = NULL;
        tree->last = NULL;
    }

    return tree;
}

void free_expression_tree(ExpressionTree *tree) {
    if (tree->root) {
        free_expression_node(tree->root);
        tree->root = NULL;
    } else if (tree->last) {
        free_expression_node(tree->last);
        tree->last = NULL;
    }

    free(tree);
}

void add_node(ExpressionTree *tree, const char value) {
    NodeType type = calculate_node_type(value);
    ExpressionNode *new_node = new_expression_node(value, type);

    if (!tree->root) {
        if (type == OPERATOR) {
            tree->root = new_node;
            set_left_node(new_node, tree->last);
        }
        tree->last = new_node;
        return;
    }

    if (type == OPERATOR) {
        if (is_new_operator_higher_precedence(tree->root, new_node)) {
            set_left_node(new_node, get_right_node(tree->root));
            set_right_node(tree->root, new_node);
        } else {
            ExpressionNode *old_root = tree->root;
            tree->root = new_node;
            set_left_node(tree->root, old_root);
        }
    } else {
        set_right_node(tree->last, new_node);
    }

    tree->last = new_node;
}

bool is_new_operator_higher_precedence(ExpressionNode *root_node, ExpressionNode *new_node) {
    if (get_node_type(root_node) == OPERATOR && get_node_type(new_node) == OPERATOR) {
        if (operator_precedence(new_node) > operator_precedence(root_node)) {
            return true;
        }
    }
    return false;
}

int operator_precedence(ExpressionNode *node) {
    const char operator = get_node_value(node);
    switch (operator) {
        case '+':
            return 1;
        case '-':
            return 2;
        default:
            return 0;
    }
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

void print_post_order(ExpressionTree *tree, char *buffer) {
    int pos = 0;
    traverse_tree_post_order(tree->root, buffer, &pos);
    buffer[get_tree_size(tree)] = '\0';
}

void traverse_tree_post_order(ExpressionNode *node, char *buffer, int *pos) {
    if (node) {
        traverse_tree_post_order(get_left_node(node), buffer, pos);
        traverse_tree_post_order(get_right_node(node), buffer, pos);

        buffer[*pos] = get_node_value(node);
        (*pos)++;
    }
}
