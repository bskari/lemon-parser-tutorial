# Use Lemon instead of Bison/YACC
YACC=lemon

all: shell

shell: main.o shellparser.o
	$(CXX) main.o shellparser.o -o shell

shellparser.cpp shellparser.hpp: shellparser.y
	lemon shellparser.y -s
	mv shellparser.c shellparser.cpp

