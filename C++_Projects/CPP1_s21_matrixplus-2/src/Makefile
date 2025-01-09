OS := $(shell uname)
CFLAGS = -Wall -Wextra -Werror
SOURCES = s21_matrix_oop.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET_LIB = s21_matrix_oop.a

PREF_TEST_SRC = ./unit_tests/
TEST_SRC = $(wildcard $(PREF_TEST_SRC)*.cpp)

.PHONY: all clean rebuild install_brew lcov style push test gcov_report

all: clean $(TARGET_LIB) test

$(TARGET_LIB): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f *.a *.o *.gch s21_matrix_oop test *.gcda coverage.info unit_test
	rm -f *.gcno *.gcov
	rm -rf coverage_report

rebuild: clean all

install_brew:
	cd /opt/goinfre/grubbsas
	git clone https://github.com/Homebrew/brew homebrew
	eval "$(/opt/goinfre/$(eugeniee)/homebrew/bin/brew shellenv)"
	brew update --force --quiet
	chmod -R go-w "$(brew --prefix)/share/zsh"

lcov:
	brew install lcov

style: clean
	cp ../materials/linters/.clang-format .
	clang-format -n *.cpp *.h
	clang-format -n ./unit_tests/*.c
	rm -rf .clang-format

push:
	git add .
	git commit -m "update code based on `date`"
	git push origin develop

test: $(TARGET_LIB)
ifeq ($(OS), Darwin)
	g++ $(CFLAGS) -L. -I. $(TEST_SRC) -o unit_test -lgtest -lgtest -lgmock -pthread $(TARGET_LIB) || true
else ifeq ($(OS), Linux)
	g++ $(CFLAGS) $(TEST_SRC) -o unit_test -lgtest -lgtest -lgmock -pthread $(TARGET_LIB)
endif
	./unit_test

gcov_report: CFLAGS += --coverage
gcov_report: clean test
	gcov *.cpp
	mkdir coverage_report
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
ifeq ($(OS), Darwin)
	open coverage_report/index.html
endif
