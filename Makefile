SOURCES=encoder.c
FORLIBRARY=stringutils.o
LIBRARY=lib.so 
TARGET=encoder

all: $(TARGET)

$(TARGET): encoder.o lib.so 
	gcc encoder.o -o $(TARGET)

encoder.o: encoder.c
	gcc $< -c -o $@ -std=c99

$(TARGET): $(FORLIBRARY)
	gcc stringutils.o -shared -o $(LIBRARY)

stringutils.o: stringutils.c 
	gcc -c -fPIC $< -std=c99

clean:
	rm -f *.o
	rm -f *.so
	rm -f encoder