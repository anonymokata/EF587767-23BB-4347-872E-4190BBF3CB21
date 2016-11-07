SOURCE_DIR = ../main/

C_FLAGS =  -Wall -Werror
C_INCLUDES = -I$(SOURCE_DIR)


default: build

.PHONY : default


Check_ExpressionNode.c.o: Check_ExpressionNode.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

Check_ExpressionTree.c.o: Check_ExpressionTree.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

Check_NotationConversion.c.o: Check_NotationConversion.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

CheckMain.c.o: CheckMain.c
	$(CC) $(C_FLAGS) -o $@ -c $^

test_rpn: Check_ExpressionNode.c.o
test_rpn: Check_ExpressionTree.c.o
test_rpn: Check_NotationConversion.c.o
test_rpn: CheckMain.c.o
	$(CC) $(C_FLAGS) $^ -o $@ `pkg-config --libs check` $(SOURCE_DIR)librpn_calc.a

build: test_rpn

.PHONY : build


clean:
	rm -f *.o
	rm -rf test_rpn*
.PHONY : clean