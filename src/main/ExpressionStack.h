#ifndef RPNCALC_EXPRESSIONSTACK_H
#define RPNCALC_EXPRESSIONSTACK_H

typedef struct ExpressionStack ExpressionStack;

ExpressionStack *new_expression_stack();

void free_expression_stack(ExpressionStack *stack);

#endif
