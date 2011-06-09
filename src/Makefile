SOURCES=$(wildcard *.cxx)
HEADERS=$(wildcard *.h)
CPP=gcc
CFLAGS=-g -ggdb

all: $(SOURCES:.cxx=.o)
	

%.o: %.cxx $(HEADERS)
	$(CPP) -o $@ -c $< $(CFLAGS)

clean:
	rm *.o

