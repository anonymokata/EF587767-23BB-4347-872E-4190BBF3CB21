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
    ExpressionNode *token = malloc(sizeof(ExpressionNode));

    if (token) {
        token->type = type;
        token->value = value;
    }

    return token;
}

void free_expression_node(ExpressionNode *token) {
    if (token->left) {
        free(token->left);
    }
    if (token->right) {
        free(token->right);
    }
    free(token);
}

NodeType get_type(ExpressionNode *token) {
    return token->type;
}

char get_value(ExpressionNode *token) {
    return token->value;
}

ExpressionNode *get_left_node(ExpressionNode *node) {
    return node->left;
}

void set_left_node(ExpressionNode *root_node, ExpressionNode *left_node) {
    root_node->left = left_node;
}

ExpressionNode *get_right_node(ExpressionNode *node) {
    return node->right;
}

void set_right_node(ExpressionNode *root_node, ExpressionNode *right_node) {
    root_node->right = right_node;
}


