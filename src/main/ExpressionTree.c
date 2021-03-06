#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "NotationConversion.h"
#include "ExpressionTree.h"

#define EMPTY_POS -1

struct ExpressionTree {
    ExpressionNode **tree_buffer;
    int tree_pos;
};

NodeType calculate_node_type(const char i);

void traverse_tree_post_order(ExpressionNode *node, char *buffer, int *pos);

void traverse_tree_in_order(ExpressionNode *node, char *buffer, int *pos);

void print_child_node(ExpressionNode *node, char *buffer, int *pos, ExpressionNode *child_node);

ExpressionTree *new_expression_tree(const size_t tree_size) {
    ExpressionTree *tree = malloc(sizeof(ExpressionTree));

    if (tree) {
        tree->tree_buffer = malloc(sizeof(ExpressionNode *) * tree_size);
        tree->tree_pos = EMPTY_POS;
    }

    return tree;
}

void free_expression_tree(ExpressionTree *tree) {
    if (tree->tree_pos != EMPTY_POS) {
        free_expression_node(tree->tree_buffer[tree->tree_pos]);
    }
    free(tree->tree_buffer);
    free(tree);
}

void add_node(ExpressionTree *tree, const char value) {
    NodeType type = calculate_node_type(value);
    ExpressionNode *new_node = new_expression_node(value, type);

    ExpressionNode *right_node = NULL;
    if (type == OPERATOR && tree->tree_pos != EMPTY_POS) {
        right_node = tree->tree_buffer[tree->tree_pos--];
    }

    ExpressionNode *left_node = NULL;
    if (type == OPERATOR && tree->tree_pos != EMPTY_POS) {
        left_node = tree->tree_buffer[tree->tree_pos--];
    }

    set_right_node(new_node, right_node);
    set_left_node(new_node, left_node);
    tree->tree_buffer[++tree->tree_pos] = new_node;
}

NodeType calculate_node_type(const char value) {
    if (value == '+' || value == '-' || value == '*' || value == '/' || value == '^') {
        return OPERATOR;
    }
    return VARIABLE;
}

ExpressionNode *get_root(ExpressionTree *tree) {
    return tree->tree_buffer[tree->tree_pos];
}

void print_post_order(ExpressionTree *tree, char *buffer, size_t buffer_size) {
    int pos = 0;
    traverse_tree_post_order(tree->tree_buffer[tree->tree_pos], buffer, &pos);
    buffer[buffer_size - 1] = '\0';
}

void traverse_tree_post_order(ExpressionNode *node, char *buffer, int *pos) {
    if (node) {
        traverse_tree_post_order(get_left_node(node), buffer, pos);
        traverse_tree_post_order(get_right_node(node), buffer, pos);

        buffer[(*pos)++] = get_node_value(node);
    }
}

void print_in_order(ExpressionTree *tree, char *buffer, size_t buffer_size) {
    int pos = 0;
    traverse_tree_in_order(tree->tree_buffer[tree->tree_pos], buffer, &pos);
    buffer[buffer_size - 1] = '\0';
}

void traverse_tree_in_order(ExpressionNode *node, char *buffer, int *pos) {
    if (node) {
        print_child_node(node, buffer, pos, get_left_node(node));

        buffer[(*pos)++] = get_node_value(node);

        print_child_node(node, buffer, pos, get_right_node(node));
    }
}

void print_child_node(ExpressionNode *node, char *buffer, int *pos, ExpressionNode *child_node) {
    bool needs_parentheses = false;

    if (child_node && get_node_type(child_node) == OPERATOR) {
        if (compare_precedence(get_node_value(node), get_node_value(child_node)) == 1) {
            needs_parentheses = true;
        }
    }

    if (needs_parentheses) {
        buffer[(*pos)++] = '(';
    }
    traverse_tree_in_order(child_node, buffer, pos);
    if (needs_parentheses) {
        buffer[(*pos)++] = ')';
    }
}
