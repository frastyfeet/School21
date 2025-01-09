OS := $(shell uname)
CFLAGS = -Wall -Wextra -Werror
SOURCES = s21_string.c s21_sprintf.c C_sharp_funct.c
OBJECTS = $(SOURCES:.c=.o)
TARGET_LIB = s21_string.a

all: clean s21_string.a test

$(TARGET_LIB): $(OBJECTS)
	ar rcs s21_string.a $^
	ranlib $@

s21_string.a: $(TARGET_LIB)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.a *.o *.gch main test *.gcda coverage.info
	rm -f *.gcno *.gcov
	rm -rf coverage_report

rebuild: clean all

style: clean
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h
	rm -rf .clang-format

push:
	git add .
	git commit -m "update code based on `date`"
	git push

test: $(TARGET_LIB)
ifeq ($(OS), Darwin)
	gcc $(CFLAGS) -L. -I. -o test test.c -lcheck s21_string.a
else ifeq ($(OS), Linux)
	gcc $(CFLAGS) -L. -I. -o test test.c -lcheck -lsubunit s21_string.a -lpthread -lm -lrt
endif
	./test

gcov_report: CFLAGS += --coverage
gcov_report: clean test
	gcov test.c
	mkdir coverage_report
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
ifeq ($(OS), Darwin)
	open coverage_report/index.html
endif
