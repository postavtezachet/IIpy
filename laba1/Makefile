CC= g++
FLAGS= -c -Wall -std=c++11

all: lab

lab: main func
	$(CC)  lab.o func.o -o lab
main: lab.cpp
	$(CC) $(FLAGS) lab.cpp -o lab.o
func: func.cpp
	$(CC) $(FLAGS) func.cpp -o func.o
