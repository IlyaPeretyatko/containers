FLAGS_TEST = -coverage -lgtest -lgtest_main -pthread
SOURCES = $(wildcard s21_*.cc)
OS = $(shell uname -s)
CFLAGS = -Wall -Wextra -Werror -c -std=c++17

all: clean s21_containers.a test

test: clean s21_containers.a
	g++ $(SOURCES) test.cc $(FLAGS_TEST) -o test
	./test

s21_containers.a:
	g++ $(CFLAGS) s21_containers.h -o s21_containers.o
	ar rcs s21_containers.a s21_containers.o 
	ranlib s21_containers.a
	rm s21_containers.o

clean:
	rm -rf *.o *.a *.gc* test

clang:
	clang-format -n -style=google *.cc *.h

clang_update:
	clang-format -i -style=google *.cc *.h

leak:
ifeq ($(OS),Darwin)
	CK_FORK=no leaks -atExit -- ./test
else
	valgrind --leak-check=full -s --track-origins=yes ./test
endif

rebuild: all