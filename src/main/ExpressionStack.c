#include <stddef.h>
#include <stdlib.h>

#include "ExpressionStack.h"

struct ExpressionStack {
};

ExpressionStack *new_expression_stack() {
    ExpressionStack *stack = malloc(sizeof(ExpressionStack));
    return stack;
}

void free_expression_stack(ExpressionStack *stack) {
    free(stack);
}
