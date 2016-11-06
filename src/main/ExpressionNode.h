#ifndef RPNCALC_EXPRESSIONTOKEN_H
#define RPNCALC_EXPRESSIONTOKEN_H

typedef struct ExpressionNode ExpressionNode;

typedef enum NodeType {
    VARIABLE, OPERATOR
} NodeType;

ExpressionNode *new_expression_node(char value, NodeType type);

void free_expression_node(ExpressionNode *node);

NodeType get_type(ExpressionNode *node);

char get_value(ExpressionNode *node);

ExpressionNode *get_left_node(ExpressionNode *node);

void set_left_node(ExpressionNode *left_node, ExpressionNode *root_node);

ExpressionNode *get_right_node(ExpressionNode *node);

void set_right_node(ExpressionNode *right_node, ExpressionNode *root_node);

#endif
