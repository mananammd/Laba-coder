#include <stdio.h>
#include "stringutils.h"

void mutableCaesarEncoder(char* str, int offset) {
    mutableFilter(str);
    mutableStrip(str);
    mutableToLower(str);
    int size = strlen(str);
    for (int i = 0; i < size ; ++i) {
	str[i] = (str[i] + (offset % 26));
    }
}
	    
char* immutableCaesarEncoder(const char* str, int offset) {
    char* result = immutableStrip(str);
    mutableToLower(result);
    mutableFilter(result);
    int size = strlen(result);
    for (int i = 0; i < size; ++i) {
	result[i] = (str[i] + (offset % 26));   
    }
    return result;
}

void mutableXorEncoder(char* str, const char* password) {
    mutableStrip(str);
    mutableToLower(str);
    mutableFilter(str);
    int size = strlen(str);
    int lenpassw = strlen(password);
    int k = 0;
    for (int i = 0; i < size; ++i) {
	str[i] = (str[i] ^ password[k]);
	k = (k + 1) % lenpassw;
    }
}

char* immutableXorEncoder(const char* str, const char* password) {
    char* result = immutableStrip(str);
    mutableToLower(result);
    mutableFilter(result);
    int size = strlen(result);
    int lenpassw = strlen(password);
    int k = 0;
    for (int i = 0; i < size; ++i) {
	result[i] = (result[i] ^ password[k]);
	k = (k + 1) % lenpassw ;
    }
    return result;
}



void mutableCaesarDecoder(char* str, int offset) {
    mutableCaesarEncoder(str, -offset);
}    

char* immutableCaesarDecoder(const char* str, int offset) { 
    return immutableCaesarEncoder(str, -offset);
}

void mutableXorDecoder(char* str, const char* password) {
    mutableStrip(str);
    mutableToLower(str);
    int size = strlen(str);
    int lenpassw = strlen(password);
    int k = 0;
    for (int i = 0; i < size; ++i) {
	str[i] = (str[i] ^ password[k]);
	k = (k + 1) % lenpassw;
    }
}

char* immutableXorDecoder(const char* str, const char* password) {
    int size = strlen(str);
    char* result = malloc((sizeof(char) * (size + 1)));
    mutableStrip(result);
    mutableToLower(result);
    int sizeres = strlen(result);
    int lenpassw = strlen(password);
    int k = 0;
    for (int i = 0; i < sizeres; ++i) {
	result[i] = (result[i] ^ password[k]);
	k = (k + 1) % lenpassw;
    }
    return result;
}
