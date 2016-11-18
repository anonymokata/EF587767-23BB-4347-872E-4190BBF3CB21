#ifndef RPNCALC_EXPRESSIONNODE_H
#define RPNCALC_EXPRESSIONNODE_H

typedef struct ExpressionNode ExpressionNode;

typedef enum NodeType {
    VARIABLE, OPERATOR, NO_OP
} NodeType;

ExpressionNode *new_expression_node(char value, NodeType type);

void free_expression_node(ExpressionNode *node);

NodeType get_node_type(ExpressionNode *node);

char get_node_value(ExpressionNode *node);

ExpressionNode *get_left_node(ExpressionNode *node);

void set_left_node(ExpressionNode *parent_node, ExpressionNode *left_node);

ExpressionNode *get_right_node(ExpressionNode *node);

void set_right_node(ExpressionNode *parent_node, ExpressionNode *right_node);

int get_node_count(ExpressionNode *node);

#endif
