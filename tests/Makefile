CC=clang
CFLAGS=-g -ggdb
LIBS=-lstdc++ -lfreeimage -lfreeimageplus -lboost_unit_test_framework
VALGRIND?=valgrind
TESTS=$(wildcard *.cxx)

all: $(TESTS:.cxx=.test)

%.test: %.cxx ../src/*.o ../src/*.h
	$(CC) $< -o $@ ../src/*.o -I../src/ $(CFLAGS) $(LIBS)

run: $(TESTS:.cxx=.run)

%.run: %.test
	-$(VALGRIND) ./$<

