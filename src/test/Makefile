SOURCE_DIR = ../main
BUILD_DIR = ../../build

C_FLAGS =  -Wall -Werror
C_INCLUDES = -I$(SOURCE_DIR)


default: build

.PHONY : default


$(BUILD_DIR)/test/Check_ExpressionNode.c.o: Check_ExpressionNode.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

$(BUILD_DIR)/test/Check_ExpressionTree.c.o: Check_ExpressionTree.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

$(BUILD_DIR)/test/Check_NotationConversion.c.o: Check_NotationConversion.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^

$(BUILD_DIR)/test/CheckMain.c.o: CheckMain.c
	$(CC) $(C_FLAGS) -o $@ -c $^

$(BUILD_DIR)/test/test_rpn: $(BUILD_DIR)/test/Check_ExpressionNode.c.o
$(BUILD_DIR)/test/test_rpn: $(BUILD_DIR)/test/Check_ExpressionTree.c.o
$(BUILD_DIR)/test/test_rpn: $(BUILD_DIR)/test/Check_NotationConversion.c.o
$(BUILD_DIR)/test/test_rpn: $(BUILD_DIR)/test/CheckMain.c.o
	$(CC) $(C_FLAGS) $^ -o $@ `pkg-config --libs check` $(BUILD_DIR)/main/librpn_calc.a

build: $(BUILD_DIR)/test/test_rpn

.PHONY : build


clean:
	rm -rf $(BUILD_DIR)/test/*.o
	rm -rf $(BUILD_DIR)/test/test_rpn*
.PHONY : clean