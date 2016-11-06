SOURCE_DIR = ../main/

C_FLAGS =  -Wall -Werror
C_INCLUDES = -I$(SOURCE_DIR)


default: build

.PHONY : default


CheckMain.c.o: CheckMain.c
	$(CC) $(C_FLAGS) -o $@ -c $^

Check_NotationConversion.c.o: Check_NotationConversion.c
	$(CC) $(C_FLAGS) $(C_INCLUDES) -o $@ -c $^


test_rpn: Check_NotationConversion.c.o
test_rpn: CheckMain.c.o
	$(CC) $(C_FLAGS) $^ -o $@ `pkg-config --libs check` $(SOURCE_DIR)librpn_calc.a

build: test_rpn

.PHONY : build


clean:
	rm -f *.o
	rm -f test_rpn
.PHONY : clean