#include <stdio.h>
#include "coder.h"
#include "stringutils.h"

int main(int argc, char** argv) {
    if (argc == 4) {
	if (whatCipher(argv[1], "--caesar") == 1) {
	    if (isNumber(argv[3]) == 1) {
		int offset = atoi(argv[3]);
		printf("%s\n", immutableCaesarEncoder(argv[2], offset));
	    }
	    else {
		printf("Incorrect data");
	    }
	}

	else if (whatCipher(argv[1], "--xor") == 1) {
	    printf("%s\n", immutableXorEncoder(argv[2], argv[3]));
	}
	
	else {
	  printf("Incorrect data");
	}
    }
    
    else if (argc == 1) {

	char cipher[6];
    	printf("Enter cipher (caesar or xor): "); 
    	scanf("%s", cipher);
    	char text[200];
    	printf("Enter text: ");
    	scanf("%s", text);

    	if (whatCipher(cipher, "caesar") == 1) {
	    int offset;
	    printf("Enter offset: ");
	    scanf("%d", &offset);
	    printf("%s\n", immutableCaesarEncoder(text, offset));
    	}
    	else if (whatCipher(cipher, "xor") == 1) {
	    char password[200];
	    printf("Enter password: ");
       	    scanf("%s", password);
            printf("%s\n", immutableXorEncoder(text, password));
    	}   
    	else {
	    printf("Incorrect data");
	}
    }


    else {
	printf("Incorrect data");
    }  		
    return 0;
}
