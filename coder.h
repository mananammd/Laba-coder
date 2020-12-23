#ifndef CODER
#define CODER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mutableCaesarEncoder(char* str, int offset);
char* immutableCaesarEncoder(const char* str, int offset);

void mutableXorEncoder(char* str, const char* password);
char* immutableXorEncoder(const char* str, const char* password);

void mutableCaesarDecoder(char* str, int offset);
char* immutableCaesarDecoder(const char* str, int offset);

void mutableXorDecoder(char* str, const char* password);
char* immutableXorDecoder(const char* str, const char* password);

#endif
