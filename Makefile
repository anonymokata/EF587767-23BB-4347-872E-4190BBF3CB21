BUILD_DIR = build


default: all

.PHONY : default


all: clean build_main build_test
	$(BUILD_DIR)/test/test_rpn
.PHONY : all

mem_test: clean build_main build_test
	CK_FORK=no valgrind --trace-children=yes --track-origins=yes --leak-check=full $(BUILD_DIR)/test/test_rpn
.PHONY : all


build_main:
	$(MAKE) -C src/main
.PHONY : build_main


build_test:
	$(MAKE) -C src/test
.PHONY : build_test


clean:
	mkdir -p $(BUILD_DIR)
	$(MAKE) -C src/main clean
	$(MAKE) -C src/test clean
.PHONY : clean

docker:
	@docker-compose -f src/docker/test-app.yml up --build
.PHONY : docker