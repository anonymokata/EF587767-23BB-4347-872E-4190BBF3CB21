#include <stddef.h>
#include <stdlib.h>

#include "ExpressionStack.h"

#define EMPTY_POS -1

struct ExpressionStack {
    char *stack_buffer;
    int stack_pos;
};

ExpressionStack *new_expression_stack(const size_t stack_size) {
    ExpressionStack *stack = malloc(sizeof(ExpressionStack));

    if (stack) {
        stack->stack_buffer = malloc(sizeof(char) * stack_size);
        stack->stack_pos = EMPTY_POS;
    }

    return stack;
}

void free_expression_stack(ExpressionStack *stack) {
    free(stack->stack_buffer);
    free(stack);
}

void push(ExpressionStack *stack, char value) {
    stack->stack_buffer[++stack->stack_pos] = value;
}

char pop(ExpressionStack *stack) {
    return stack->stack_buffer[stack->stack_pos--];
}

bool is_empty(ExpressionStack *stack) {
    return stack->stack_pos == EMPTY_POS;
}

char peak(ExpressionStack *stack) {
    return stack->stack_buffer[stack->stack_pos];
}
