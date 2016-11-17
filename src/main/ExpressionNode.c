#include <stddef.h>
#include <stdlib.h>
#include "ExpressionNode.h"

struct ExpressionNode {
    NodeType type;
    char value;
    ExpressionNode *left;
    ExpressionNode *right;
};

ExpressionNode *new_expression_node(char value, NodeType type) {
    ExpressionNode *node = malloc(sizeof(ExpressionNode));

    if (node) {
        node->type = type;
        node->value = value;

        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void free_expression_node(ExpressionNode *node) {
    if (node->left) {
        free_expression_node(node->left);
        node->left = NULL;
    }
    if (node->right) {
        free_expression_node(node->right);
        node->right = NULL;
    }
    free(node);
}

NodeType get_node_type(ExpressionNode *node) {
    return node->type;
}

char get_node_value(ExpressionNode *node) {
    return node->value;
}

ExpressionNode *get_left_node(ExpressionNode *node) {
    return node->left;
}

void set_left_node(ExpressionNode *parent_node, ExpressionNode *left_node) {
    parent_node->left = left_node;
}

ExpressionNode *get_right_node(ExpressionNode *node) {
    return node->right;
}

void set_right_node(ExpressionNode *parent_node, ExpressionNode *right_node) {
    parent_node->right = right_node;
}

int get_node_count(ExpressionNode *node) {
    int count = 0;
    if (node->left) {
        count += get_node_count(node->left);
    }
    if (node->right) {
        count += get_node_count(node->right);
    }
    return count + 1;
}


