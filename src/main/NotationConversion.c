#include <stddef.h>
#include <string.h>

#include "ExpressionTree.h"
#include "NotationConversion.h"

void convert_to_rpn(const char *infix, char *rpn_buffer, size_t buffer_size) {
    char result[buffer_size + 1];
    ExpressionTree *tree = new_expression_tree();

    for (int i = 0; i < strlen(infix); ++i) {
        add_node(tree, infix[i]);
    }

    print_post_order(tree, result);
    result[buffer_size] = '\0';

    strncpy(rpn_buffer, result, buffer_size);

    free_expression_tree(tree);
}
