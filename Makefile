SOURCES=decoder.c
FORLIBRARY=stringutils.o
LIBRARY=lib.so 
TARGET=decoder

all: $(TARGET)

$(TARGET): decoder.o lib.so 
    gcc decoder.o -o $(TARGET)

decoder.o: decoder.c
    gcc $< -c -o $@ -std=c99

$(TARGET): $(FORLIBRARY)
    gcc stringutils.o -shared -o $(LIBRARY)

stringutils.o: stringutils.c 
    gcc -c -fPIC $< -std=c99

clean:
    rm -f *.o
    rm -f *.so
    rm -f decoder
