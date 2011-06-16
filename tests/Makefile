CC=gcc
CFLAGS=-fpermissive -g -ggdb
LIBS=-lstdc++
VALGRIND?=valgrind

all: geometry.test run

geometry.test: geometry.cxx ../src/*.o ../src/*.h
	$(CC) geometry.cxx -o geometry.test ../src/*.o -I../src/ $(CFLAGS) $(LIBS)

run: geometry.test
	-$(VALGRIND) ./geometry.test	

