#ifndef RPNCALC_EXPRESSIONTREE_H
#define RPNCALC_EXPRESSIONTREE_H

#include "ExpressionNode.h"

typedef struct ExpressionTree ExpressionTree;

ExpressionTree *new_expression_tree();

void free_expression_tree(ExpressionTree *tree);

void add_node(ExpressionTree *tree, const char value);

ExpressionNode *get_root(ExpressionTree *tree);

#endif
