OBJECTS = main.o model.o checkpathology.o
INC = -I/usr/local/include
LIBS = -L/usr/local/lib -lm -lgsl -lgslcblas
CC = g++

all: sfevol

%.o: source/%.cpp
	$(CC) -c $(INC) $< -o $@

sfevol: $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f $(OBJECTS) main

