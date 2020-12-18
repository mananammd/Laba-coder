#include "stringutils.h"

//Является ли название шифром
int WhatCipher(const char* type, const char* ciph) {
    if (strlen(type) == strlen(ciph)) {
        return 1;
    }
    for (int i = 0; i < strlen(ciph); ++i) {
        if (type[i] == ciph[i]) {
            return 1;
        }
    }
    return 0;
}


void mutableToUpper(char* str) {
    int size = strlen(str);
    for (int i = 0; i < size; ++i) {
	    if ((str[i] >= 'a') && (str[i] <= 'z')) {
	        str[i] += ('A' - 'a');
	    }
    }
}

char* immutableToUpper(const char* str) {
    int size = strlen(str);
    char* StrRes = malloc((sizeof(char) * (size + 1)));
    for (int i = 0; i < size; ++i) {
	    if ((str[i] >= 'a') && (str[i] <= 'z')) {
	        StrRes[i] = str[i] + ('A' - 'a');
	    }
        else {
	        StrRes[i] = str[i];
	    }
    }
    return StrRes;
}


void mutableToLower(char* str) {
    int size = strlen(str);
    for (int i = 0; i < size; ++i) {
	    if ((str[i] >= 'A') && (str[i] <= 'Z')) {
	        str[i] += ('a' - 'A');
	    }
    }
}

char* immutableToLower(const char* str) {
    int size = strlen(str);
    char* StrRes = malloc((sizeof(char) * (size + 1)));
    for (int i = 0; i < size; ++i) {
	    if ((str[i] >= 'A') && (str[i] <= 'Z')) {
	        StrRes[i] = str[i] + ('a' - 'A');
	    }
	    else {
	        StrRes[i] = str[i];
	    }
        }
    return StrRes;
}


void mutableStrip(char* str) {
    int size = strlen(str);
    int left = 0;
    while (str[left] == ' ') {
	    left++;
    }
    int right = 0;
    while (str[size - 1 - right] == ' ') {
	    right++;
    }
    int LenText = size - left - right;
    for (int i = 0; i < LenText; ++i) {
	    str[i] = str[left + i];
    }
    str[LenText] = '\0';
}

char* immutableStrip(const char* str) {
    int size = strlen(str);
    int left = 0;
    while (str[left] == ' ') {
	    left++;
    }
    int right = 0;
    while (str[size - 1 - right] == ' ') {
	    right++;
    }
    int LenText = size - left - right;
    char* StrRes = malloc((sizeof(char) * (size + 1)));
    for (int i = 0; i < LenText; ++i) {
	    StrRes[i] = str[left + i];
    }
    StrRes[LenText] = '\0';
    return StrRes;
}


void mutableAllStrip(char* str) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; ++i) {
	if (str[i] != ' ') {
            str[j] = str[i];
            ++j;
	    }
    }
    str[j] = '\0';
}

char* immutableAllStrip(const char* str) {
    int size = strlen(str);
    char* StrRes = malloc((sizeof(char) * (size + 1)));
    int j = 0;
    for (int i = 0; i < size; ++i) {
	    if (str[i] != ' ') {
	        StrRes[j] = str[i];
	        ++j;
	    }
    }
    StrRes[j] = '\0';
    return StrRes;
}


void mutableFilter(char* str) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; ++i) {
	    if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))
 	        || ((str[i] >= '0') && (str[i] <= '9')) || (str[i] == ' '))
            {
	        str[j] = str[i];
	        ++j;
	    }
    }
    str[j] = '\0';
}

char* immutableFilter(const char* str) {
    int size = strlen(str);
    int j = 0;
    char* StrRes = malloc((sizeof(char) * (size + 1)));
    for (int i = 0; i < strlen(str); ++i) {
	    if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))
	        || ((str[i] >= '0') && (str[i] <= '9')) || (str[i] == ' '))
        {
            StrRes[j] = str[i];
	        ++j;
	    }
    }
    StrRes[j] = '\0';
    return StrRes;
}


int Number(const char* str) {
    int size = strlen(str);
    int SumNumber = 0;
    while ((str[SumNumber] >= '0') && (str[SumNumber] <= '9')) {
	    ++SumNumber;
    }
    if (SumNumber == size) {
	    return 1;
    }
    else {
        return 0;
    }
}

int Word(const char* str) {
    int size = strlen(str);
    int SumLetter = 0;
    while (((str[SumLetter] >= 'a') && (str[SumLetter] <= 'z'))
        || ((str[SumLetter] >= 'A') && (str[SumLetter] <= 'Z')))
    {
	    ++SumLetter;
    }
    if (SumLetter == size) {
	    return 1;
    }
    else {
	    return 0;
    }
}
