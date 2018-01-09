/*
 * Crypto.c
 *
 *  Created on: 22.12.2017
 *      Author: Epiphan
 */
#include "Crypto.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int valid1(char* input) {
	char* strk;
	for (strk = input; *strk; strk++) {
		if (isupper(*strk) == 0) {
			return 0;
		}
	}
	return 1;
}
int valid2(char*v) {
	int length = strlen(v);
	char strk[length];
	strcpy(strk, v);
	for (int n = 0; n < length; n++) {
		char b = strk[n];
		int n = b - 'A' + 1;
		if (n < 0 || n > 31) {
			return 0;
		}
	}
	return 1;
}
int sizeOfArray(int v[]) {
	return (sizeof(v) / sizeof(v[0]));
}

int lengthOfPtr(char* vvod) {
	char kopia[32];
	strcpy(kopia, vvod);
	return strlen(kopia);
}

int *charToDigit(char v[], int length) {
	int *resultat = malloc(length * sizeof(int));
	if (!resultat) {
		return NULL;
	}
	for (int n = 0; n < length; n++) {
		char b = v[n];
		int nom = b - 'A' + 1;
		resultat[n] = nom;
	}
	return resultat;
}

char *digitToChar(int v[], int length) {
	char* resultat = malloc(length * sizeof(char));
	if (!resultat) {
		return NULL;
	}
	for (int n = 0; n < length; n++) {
		char b = v[n] + 'A' - 1;
		resultat[n] = b;
	}

	return resultat;
}
char *makeLonger(int length, char* v) {
	char *resultat = malloc(length * sizeof(char));
	if (!resultat) {
		return NULL;
	}
	strcpy(resultat, v);
	int nom1 = (int) (length / (strlen(v)));
	int nom2 = (int) (length % (strlen(v)));
	for (int n = 0; n < nom1 - 1; n++) {
		strcat(resultat, v);
	}
	strncat(resultat, v, nom2);
	return resultat;
}
int *xor(int a[], int b[], int length) {
	int *resultat = malloc(length * sizeof(int));
	if (!resultat) {
		return NULL;
	}
	for (int n = 0; n < length; n++) {
		resultat[n] = (a[n] ^ b[n]);
	}
	return resultat;
}

int decrypt(KEY key, const char* cypherText, char* output) {

	if (lengthOfPtr(key.chars) < 0) {
		return E_KEY_TOO_SHORT;
	} else if (valid1(key.chars) == 0) {
		return E_KEY_ILLEGAL_CHAR;
	} else if (valid2(cypherText) == 0) {
		return E_CYPHER_ILLEGAL_CHAR;
	} else {
		int length1 = strlen(cypherText), length2 = (int) strlen(key.chars);
		int *digits1, *digits2 = charToDigit(cypherText, length1), *digits3;
		char *chars1, *chars2;
		if (strlen(key.chars) < strlen(cypherText)) {
			chars1 = makeLonger(length1, key.chars);
			digits1 = charToDigit(chars1, length1);
			digits3 = xor(digits2, digits1, length1);
			chars2 = digitToChar(digits3, length1);
			strcpy(output, chars2);
			free(chars1);
		} else {
			digits1 = charToDigit(key.chars, length2);
			digits3 = xor(digits2, digits1, length1);
			chars2 = digitToChar(digits3, length1);
			strcpy(output, chars2);
		}
		free(chars2), free(digits1), free(digits2), free(digits3);
		return 0;
	}

}

int encrypt(KEY key, const char* input, char* output) {

	if (lengthOfPtr(key.chars) < 1) {
		return E_KEY_TOO_SHORT;
	} else if (valid1(key.chars) == 0) {
		return E_KEY_ILLEGAL_CHAR;
	} else if (valid1(input) == 0) {
		return E_MESSAGE_ILLEGAL_CHAR;
	} else {
		int length1 = (int) strlen(input), length2 = (int) strlen(key.chars);
		int *digits1 = charToDigit(input, length1), *digits2, *digits3;
		char *chars2, *chars3;

		if (strlen(key.chars) < length1) {
			chars2 = makeLonger(length1, key.chars);
			digits2 = charToDigit(chars2, length1);
			digits3 = xor(digits1, digits2, length1);
			chars3 = digitToChar(digits3, length1);
			strcpy(output, chars3);
			free(chars2);
		} else {
			digits2 = charToDigit(key.chars, length2);
			digits3 = xor(digits1, digits2, length1);
			chars3 = digitToChar(digits3, length1);
			strcpy(output, chars3);
		}
		free(digits1), free(digits2), free(digits3), free(chars3);

		return 0;

	}

}
