SOURCES=$(wildcard *.cxx)
HEADERS=$(wildcard *.h)
CPP=gcc

all: $(SOURCES:.cxx=.o)
	

%.o: %.cxx $(HEADERS)
	$(CPP) -o $@ -c $<

clean:
	rm *.o

