#ifndef STRINGUTILS
#define STRINGUTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int WhatCipher(const char* type, const char* ciph);

void mutableToUpper(char* str);
char* immutableToUpper(const char* str);

void mutableToLower(char* str);
char* immutableToLower(const char* str);

void mutableStrip(char* str);
char* immutableStrip(const char* str);

void mutableAllStrip(char* str);
char* immutableAllStrip(const char* str);

void mutableFilter(char* str);
char* immutableFilter(const char* str);

int Number(const char* str);
int Word(const char* str); 

#endif