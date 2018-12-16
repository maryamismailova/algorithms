SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES: .c=.o)
INPUT=input2.txt

all: exec
	./exec input2.txt
exec: $(OBJECTS)
	cc $^ -o $@
%.o: %.c
	cc -c $^ -o $@
