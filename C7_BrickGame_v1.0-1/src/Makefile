SHELL = /bin/sh 
OS := $(shell uname)
CFLAGS = -lncurses -std=c11 -Wall -Werror -Wextra
SOURCES = $(SRC_PATH)back.c ./gui/cli/gui.c $(SRC_PATH)fsm.c $(SRC_PATH)sql/sql.c $(SRC_PATH)game_loop.c $(SRC_PATH)sql/sqlite3.c
OBJECTS = $(SOURCES:.c=.o)
TARGET_LIB = s21_tetris.a
SRC_PATH = ./brick_game/tetris/


$(TARGET_LIB): $(OBJECTS)
	ar rcs s21_tetris.a $^
	ranlib $@

s21_tetris.a: $(TARGET_LIB)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

install: s21_tetris.a
	gcc -L. -I. -o ../build/tetris $(SRC_PATH)tetris.c s21_tetris.a -lncurses

unistall: clean

clean:
	rm -f *.a $(SRC_PATH)*.o $(SRC_PATH)sql/*.o ./gui/cli/*.o *.gch main test *.gcda coverage.info
	rm -f *.gcno *.gcov *.tar.gz $(SRC_PATH)/*.gcda $(SRC_PATH)/*.gcno $(SRC_PATH)sql/*.gcno $(SRC_PATH)sql/*.gcda ./gui/cli/*.gcno ./gui/cli/*.gcda
	rm -f ../build/tetris
	rm -rf coverage_report

rebuild : clean all

test: $(TARGET_LIB)
ifeq ($(OS), Darwin)
	gcc $(CFLAGS) -L. -I. -o test test.c -lcheck s21_tetris.a
else ifeq ($(OS), Linux)
	gcc $(CFLAGS) -L. -I. -o test test.c -lcheck -lsubunit s21_tetris.a -lpthread -lm -lrt -lncurses
endif
	./test

gcov_report: CFLAGS += --coverage
gcov_report: clean test
	gcov test-test.c
	mkdir coverage_report
	lcov --directory . --capture --output-file coverage.info
	lcov --remove coverage.info '*/sqlite3.c' --output-file coverage.info
	lcov --remove coverage.info '*/sql.c' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
ifeq ($(OS), Darwin)
	open coverage_report/index.html
endif

dvi:
	open Documentation.html

dist: install
	@rm -rf dist.tar.gz
	@tar -cvzf dist.tar.gz ../build/tetris
