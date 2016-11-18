#include <stddef.h>
#include <stdlib.h>

#include "ExpressionStack.h"

struct ExpressionStack {
    ExpressionNode *top;
};

void set_child_node(ExpressionNode *parent, ExpressionNode *child);

ExpressionNode *get_child_node(ExpressionNode *parent);

ExpressionStack *new_expression_stack() {
    ExpressionStack *stack = malloc(sizeof(ExpressionStack));

    if (stack) {
        stack->top = NULL;
    }

    return stack;
}

void free_expression_stack(ExpressionStack *stack) {
    if (stack->top) {
        free_expression_node(stack->top);
    }
    free(stack);
}

void push(ExpressionStack *stack, char value) {
    ExpressionNode *node = new_expression_node(value, NO_OP);

    set_child_node(node, stack->top);
    stack->top = node;
}

char pop(ExpressionStack *stack) {
    ExpressionNode *top_child = get_child_node(stack->top);

    ExpressionNode *old_top_node = stack->top;
    stack->top = top_child;

    char value = get_node_value(old_top_node);

    set_child_node(old_top_node, NULL);
    free_expression_node(old_top_node);

    return value;
}

bool is_empty(ExpressionStack *stack) {
    return stack->top == NULL;
}

void set_child_node(ExpressionNode *parent, ExpressionNode *child) {
    set_left_node(parent, child);
}

ExpressionNode *get_child_node(ExpressionNode *parent) {
    return get_left_node(parent);
}
