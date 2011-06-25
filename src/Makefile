SOURCES=$(wildcard *.cxx)
HEADERS=$(wildcard *.h)
CPP=clang
CFLAGS?=-g -ggdb
RM?=rm

all: objects so test
	
objects: $(SOURCES:.cxx=.o)

%.o: %.cxx $(HEADERS)
	$(CPP) -o $@ -c $< $(CFLAGS)

test: objects
	cd ../tests && $(MAKE) -f Makefile

so: objects
	$(CPP) *.o -o geometry.so -shared -g -ggdb $(SO_LIBS)

clean:
	-$(RM) *.o

