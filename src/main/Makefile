SOURCE_DIR = ../main
BUILD_DIR = ../../build

C_FLAGS =  -Wall -Werror


default: build

.PHONY : default

$(BUILD_DIR)/main/ExpressionNode.c.o: ExpressionNode.c
	$(CC) $(C_FLAGS) -o $@ -c $^

$(BUILD_DIR)/main/ExpressionStack.c.o: ExpressionStack.c
	$(CC) $(C_FLAGS) -o $@ -c $^

$(BUILD_DIR)/main/ExpressionTree.c.o: ExpressionTree.c
	$(CC) $(C_FLAGS) -o $@ -c $^

$(BUILD_DIR)/main/NotationConversion.c.o: NotationConversion.c
	$(CC) $(C_FLAGS) -o $@ -c $^

$(BUILD_DIR)/main/librpn_calc.a: $(BUILD_DIR)/main/ExpressionNode.c.o
$(BUILD_DIR)/main/librpn_calc.a: $(BUILD_DIR)/main/ExpressionStack.c.o
$(BUILD_DIR)/main/librpn_calc.a: $(BUILD_DIR)/main/ExpressionTree.c.o
$(BUILD_DIR)/main/librpn_calc.a: $(BUILD_DIR)/main/NotationConversion.c.o
	rm -f $@
	ar qc $@ $^

build: $(BUILD_DIR)/main/librpn_calc.a

.PHONY : build


clean:
	rm -rf $(BUILD_DIR)/main/*.o
	rm -rf $(BUILD_DIR)/main/*.a
.PHONY : clean
