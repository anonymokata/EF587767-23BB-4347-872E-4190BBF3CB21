#ifndef RPNCALC_NOTATIONCONVERSION_H
#define RPNCALC_NOTATIONCONVERSION_H

void convert_to_rpn(const char *infix, char *rpn_buffer, size_t buffer_size);

void convert_to_infix(const char *rpn, char *infix_buffer, size_t buffer_size);

int compare_precedence(const char op1, const char existing_op);

#endif
