all: parse.o
	gcc -o program parse.o

dirinfo.o: parse.c parse.h
	gcc -c parse.c parse.h

run:
	./program

clean:
	rm *.o
	rm *~
