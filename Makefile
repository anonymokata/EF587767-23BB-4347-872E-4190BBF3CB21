default: all

.PHONY : default


all: clean rpn_calc test_rpn
	src/test/test_rpn
.PHONY : all


rpn_calc:
	$(MAKE) -C src/main
.PHONY : rpn_calc


test_rpn:
	$(MAKE) -C src/test
.PHONY : test_rpn


clean:
	$(MAKE) -C src/main clean
	$(MAKE) -C src/test clean
.PHONY : clean