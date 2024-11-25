CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
C_FILES = calc.c polish.c stack.c 

all: run


test:
	$(CC) $(CFLAGS) -lcheck -lm -lpthread *.c -o test
	./test
	rm test

gcov_report:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage *.c  -pthread -lcheck -pthread -lm -o test
	./test
	lcov -t "test_html" -o unit_test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o test_html unit_test.info
	open test_html/index.html

clean:
	rm -rf *.gc* *.o test unit_test.info test_html/ test latex/ html/ build/

uninstall: clean
	rm -Rf build

install:
	[ -d build ] || mkdir -p build
	cd build && qmake ../Calc
	make -C ./build/

dist: uninstall
	cd ../ && tar -cf Calc.tar src

run: install
	build/./Calc

beautify:
	clang-format -i *.c *.h --style=Google

style:
	clang-format -n *.c *.h --style=Google


