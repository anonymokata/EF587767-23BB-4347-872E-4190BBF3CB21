# RPN Converter

This is a Kata written in C builds a library to convert between infix and postfix notation.
Infix is the notation used to describe mathematical functions, such as when using a graphing calculator.
It is identified by the operator being positioned between two operands. Parentheses are used to define order of operations

    (a + b) ^ c

Postfix is also known as Reverse Polish Notation.
It is used in some calculators, and is common among persons who see equations as number manipulation

    a b + c ^

Order of operators is defined by the grouping of operands preceding the operator.

## Library details

The main notation conversion API exists in the NotationConversion.h
The application is compiled to 'librpn_calc.c', which is output in the 'build/main' folder in the top level directory.
The test executable output to the 'build/test' folder.

## Running the application

This application is written to compile on GNU CC on Ubuntu 14.04, but should work on any modern C compiler.
GNU Make is assumed installed, as its part of the 'build-essential' package on Ubuntu.

To build the application and run all unit tests, run:

    make all

To build the application and run the unit tests with memory coverage, run:

    make mem_tests

A docker image is provided to allow for compilation on any system capable of running docker.
To build the application and run all unit tests with memory coverage in the provided docker image, run:

    make docker

### Implementation Details

This solution is implemented using a simple abstract syntax tree, a data structure often used in compilers.
I found this a simple approach, as the same tree can be read in-order for infix notion, and post-order for postfix notion.

The input to the functions does not allow for spaces, and requires the user to know the size of the output buffer.
There is minimal error checking, so any invalid input - including mismatched parentheses for an infix - will result in bizarre output and memory errors.
