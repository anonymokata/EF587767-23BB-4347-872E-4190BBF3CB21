#include <stddef.h>
#include <string.h>

#include "ExpressionStack.h"
#include "ExpressionTree.h"
#include "NotationConversion.h"

void add_expression_to_tree(ExpressionTree *tree, ExpressionStack *var_stack, char op);

int compare_precedence(const char op1, const char existing_op);

int operator_precedence(const char op);

void convert_to_rpn(const char *infix, char *rpn_buffer, size_t buffer_size) {
    char result[buffer_size + 1];
    ExpressionTree *tree = new_expression_tree();
    ExpressionStack *op_stack = new_expression_stack(buffer_size);
    ExpressionStack *var_stack = new_expression_stack(buffer_size);

    int i;
    for (i = 0; i < strlen(infix); ++i) {
        char value = infix[i];
        switch (value) {
            case '(':
                push(op_stack, value);
                break;

            case ')':
                while (!is_empty(op_stack)) {
                    char popped_value = pop(op_stack);
                    if (popped_value == '(') {
                        break;
                    } else {
                        add_expression_to_tree(tree, var_stack, popped_value);
                    }
                }
                break;

            case '+':
            case '-':
                while (!is_empty(op_stack) && peak(op_stack) != '(') {
                    if (compare_precedence(value, peak(op_stack)) <= 0) {
                        add_expression_to_tree(tree, var_stack, pop(op_stack));
                    } else {
                        break;
                    }
                }
                push(op_stack, value);
                break;

            default:
                push(var_stack, value);
                break;
        }
    }

    while (!is_empty(op_stack)) {
        add_expression_to_tree(tree, var_stack, pop(op_stack));
    }

    print_post_order(tree, result, buffer_size + 1);

    strcpy(rpn_buffer, result);

    free_expression_tree(tree);
    free_expression_stack(op_stack);
    free_expression_stack(var_stack);
}

void add_expression_to_tree(ExpressionTree *tree, ExpressionStack *var_stack, char op) {
    char value;
    if ((value = pop(var_stack)) != ' ') {
        add_node(tree, value);
    }

    add_node(tree, op);

    if ((value = pop(var_stack)) != ' ') {
        add_node(tree, value);
    }

    push(var_stack, ' ');
}

int compare_precedence(const char new_op, const char existing_op) {
    if (operator_precedence(new_op) > operator_precedence(existing_op)) {
        return 1;
    } else if (operator_precedence(new_op) < operator_precedence(existing_op)) {
        return -1;
    }
    return 0;
}

int operator_precedence(const char op) {
    switch (op) {
        case '+':
            return 1;
        case '-':
            return 2;
        default:
            return 0;
    }
}
