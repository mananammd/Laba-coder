#include "stringutils.h"

//Является ли название шифром
int whatCipher(const char* type, const char* ciph) {
    int sizeciph = strlen(ciph);
    for (int i = 0; i < sizeciph; ++i) {
        if (type[i] == ciph[i]) {
            return 1;
        }
	else {
	    return 0;
	}
    }
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
    char* result = malloc((sizeof(char) * (size + 1)));
    strcpy(result, str);
    mutableToUpper(result);  
    return result;
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
    char* result = malloc((sizeof(char) * (size + 1)));
    strcpy(result, str);
    mutableToLower(result);  
    return result;
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
    char* result = malloc((sizeof(char) * (size + 1)));
    strcpy(result, str);
    mutableStrip(result);  
    return result;
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
    char* result = malloc((sizeof(char) * (size + 1)));
    strcpy(result, str);
    mutableAllStrip(result);  
    return result;
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
    char* result = malloc((sizeof(char) * (size + 1)));
    strcpy(result, str);
    mutableFilter(result);  
    return result;
}


int isNumber(const char* str) {
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

int isWord(const char* str) {
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
