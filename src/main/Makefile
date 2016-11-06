C_FLAGS =  -Wall -Werror
C_INCLUDES = -I../src


default: build

.PHONY : default

NotationConversion.c.o: NotationConversion.c
	$(CC) $(C_FLAGS) -o $@ -c $^

librpn_calc.a: NotationConversion.c.o
	rm -f $@
	ar qc $@ $^

build: librpn_calc.a

.PHONY : build


clean:
	rm -f *.o
.PHONY : clean
