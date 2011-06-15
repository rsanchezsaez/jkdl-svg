SOURCES=$(wildcard *.cxx)
HEADERS=$(wildcard *.h)
CPP=gcc
CFLAGS=-g -ggdb

all: objects so test
	
objects: $(SOURCES:.cxx=.o)

%.o: %.cxx $(HEADERS)
	$(CPP) -o $@ -c $< $(CFLAGS)

test: objects
	cd ../tests && make -f Makefile

so: objects
	gcc *.o -o geometry.so -shared -g -ggdb

clean:
	rm *.o

