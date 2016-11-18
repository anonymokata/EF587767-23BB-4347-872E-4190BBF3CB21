#include <stddef.h>
#include <stdlib.h>

#include "ExpressionStack.h"

struct ExpressionStack {
    ExpressionNode *top;
};

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
    stack->top = node;
}

ExpressionNode *pop_node(ExpressionStack *stack) {
    return stack->top;
}
