all: decoder

decoder:  stringutils.a decoder.o
	gcc  decoder.o -L. -lstr -o decoder

stringutils.a: stringutils.o
	ar -rc stringutils.a stringutils.o

stringutils.o:
	gcc -c stringutils.c -std=c99

decoder.o:
	gcc -c decoder.c -std=c99

clean:
	rm -rf *.o *.a decoder