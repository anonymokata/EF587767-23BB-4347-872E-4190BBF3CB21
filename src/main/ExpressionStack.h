#ifndef RPNCALC_EXPRESSIONSTACK_H
#define RPNCALC_EXPRESSIONSTACK_H

#include <stdbool.h>
#include "ExpressionNode.h"

typedef struct ExpressionStack ExpressionStack;

ExpressionStack *new_expression_stack();

void free_expression_stack(ExpressionStack *stack);

void push(ExpressionStack *stack, char value);

char pop(ExpressionStack *stack);

bool is_empty(ExpressionStack *stack);

#endif
