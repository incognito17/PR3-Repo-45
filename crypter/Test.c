#include "Crypto.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int tests_run = 0;
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                 if (message) return message; } while (0)
static char* testEncrypt();
static char* testDecrypt();
static char* testKeyTooShort();
static char* testKeyIllegalChar();
static char* testMessageIllegalChar();
static char* testCypherIllegalChar();
static char* allTests();

static char* allTests() {
	mu_run_test(testEncrypt);
	mu_run_test(testDecrypt);
	mu_run_test(testKeyTooShort);
	mu_run_test(testKeyIllegalChar);
	mu_run_test(testMessageIllegalChar);
	mu_run_test(testCypherIllegalChar);
	return 0;
}
static char* testEncrypt() {
	KEY k = { 1, "TPERULES" };
	char* output = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	char* input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	encrypt(k, input, output);
	mu_assert("Error: method - encrypt() failed!",
			strcmp(output, "URFVPJB[]ZN^XBJCEBVF@ZRKMJ") == 0);
	free(output);
	return 0;
}
static char* testDecrypt() {
	KEY k = { 1, "TPERULES" };
	char* output = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	char* cypherText = "URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
	decrypt(k, cypherText, output);
	mu_assert("Error: method - decrypt() failed!",
			strcmp(output, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);
	free(output);
	return 0;
}
static char* testKeyTooShort() {
	KEY k = { 1, "" };
	char* output = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	char* input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int result = encrypt(k, input, output);
	mu_assert("Should be an error - key is too short!", result == 1);
	free(output);
	return 0;

}
static char* testKeyIllegalChar() {
	KEY k = { 1, "lala" };
	char* output = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	char* input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int result = encrypt(k, input, output);
	mu_assert("Should be an error - key contains illegal characters!",
			result == 2);
	free(output);
	return 0;
}
static char* testMessageIllegalChar() {
	KEY k = { 1, "TPERULES" };
	char* output = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	char* input = "tratata";
	int result = encrypt(k, input, output);
	mu_assert("Should be an error - message contains illegal characters!",
			result == 3);
	free(output);
	return 0;
}
static char* testCypherIllegalChar() {
	KEY k = { 1, "TPERULES" };
	char* output = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	char* cypherText = "lalala";
	int result = decrypt(k, cypherText, output);
	mu_assert("Should be an error - cypherText contains illegal characters!",
			result == 4);
	free(output);
	return 0;
}
int main(int argc, char* argv[]) {
	char *result = allTests();

	if (result != 0)
		printf("%s\n", result);
	else
		printf("ALL TESTS PASSED\n");

	printf("Tests run: %d\n", tests_run);

	return result != 0;
}

