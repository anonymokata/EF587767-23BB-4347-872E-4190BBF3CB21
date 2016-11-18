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

void push_node(ExpressionStack *stack, ExpressionNode *node) {
    set_child_node(node, stack->top);
    stack->top = node;
}

ExpressionNode *pop_node(ExpressionStack *stack) {
    ExpressionNode *top_child = get_child_node(stack->top);

    ExpressionNode *old_top_node = stack->top;
    set_child_node(old_top_node, NULL);

    stack->top = top_child;
    return old_top_node;
}

void set_child_node(ExpressionNode *parent, ExpressionNode *child) {
    set_left_node(parent, child);
}

ExpressionNode *get_child_node(ExpressionNode *parent) {
    return get_left_node(parent);
}
