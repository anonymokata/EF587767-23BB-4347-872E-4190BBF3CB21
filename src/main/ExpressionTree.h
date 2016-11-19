#ifndef RPNCALC_EXPRESSIONTREE_H
#define RPNCALC_EXPRESSIONTREE_H

#include "ExpressionNode.h"

typedef struct ExpressionTree ExpressionTree;

ExpressionTree *new_expression_tree(const size_t tree_size);

void free_expression_tree(ExpressionTree *tree);

void add_node(ExpressionTree *tree, const char value);

ExpressionNode *get_root(ExpressionTree *tree);

void print_post_order(ExpressionTree *tree, char *buffer, size_t buffer_size);

#endif
