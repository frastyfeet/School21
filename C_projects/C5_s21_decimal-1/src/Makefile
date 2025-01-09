OS := $(shell uname)
CFLAGS = -Wall -Wextra -Werror
SOURCES = s21_arithmetic.c s21_helper.c s21_compare.c s21_other.c s21_converters.c

OBJECTS = $(SOURCES:.c=.o)
TARGET_LIB = s21_decimal.a

PREF_TEST_SRC=./unit_tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)*.c)

all: clean s21_decimal.a 

$(TARGET_LIB): $(OBJECTS)
	ar rcs s21_decimal.a $^
	ranlib $@



%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.a *.o *.gch main test *.gcda coverage.info unit_test
	rm -f *.gcno *.gcov
	rm -rf coverage_report

rebuild: clean all



install_brew:
	cd /opt/goinfre/grubbsas
	git clone https://github.com/Homebrew/brew homebrew
	eval "$(/opt/goinfre/$(grubbsas)/homebrew/bin/brew shellenv)"
	brew update --force --quiet
	chmod -R go-w "$(brew --prefix)/share/zsh"


lcov: 
	brew install lcov

style: clean
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h
	clang-format -n ./unit_tests/*.c ./unit_tests/*.h
	rm -rf .clang-format

push:
	git add .
	git commit -m "update code based on `date`"
	git push 

test:  $(TARGET_LIB) 
ifeq ($(OS), Darwin)
	gcc $(CFLAGS) -L. -I. ${TEST_SRC} $< -o unit_test -lcheck  s21_decimal.a || true
else ifeq ($(OS), Linux)
	gcc $(CFLAGS) -L. -I. ${TEST_SRC} -o  unit_test  -lcheck -lsubunit  -lpthread -lm -lrt s21_decimal.a -fprofile-arcs -ftest-coverage 

endif
	./unit_test

gcov_report: CFLAGS += --coverage
gcov_report: clean test
	gcov *.c
	mkdir coverage_report
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
ifeq ($(OS), Darwin)
	open coverage_report/index.html
endif
