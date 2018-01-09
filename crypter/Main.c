#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Crypto.h"

int main(int argc, char* argv[]) {
	if (argc < 2 || argc > 3) {
		fprintf(stderr, "Illegal input! \n");
		fprintf(stderr, "Usage: KEY [file name] \n");
		return 1;
	}
	KEY k = { 1, argv[1] };
	char* output = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	char* input = malloc(strlen(KEY_CHARACTERS) * (sizeof(char)));
	if (argc == 2) {
		if ((strstr(argv[0], "encrypt")) != 0) {
			printf("Insert your message: \n");
			fgets(input, 50, stdin);
			input[strlen(input) - 1] = '\0';
			int r = encrypt(k, input, output);
			if (r == 0) {
				fputs(output, stdout);
				free(input);
				free(output);
				return 0;
			} else if (r == 1) {
				fprintf(stderr, "Key is too short! \n");
				return 2;
			} else if (r == 2) {
				fprintf(stderr, "Key contains illegal characters! \n");
				return 3;
			} else if (r == 3) {
				fprintf(stderr, "Message contains illegal characters! \n");
				return 4;
			} else {
				fprintf(stderr, "Something went completely wrong! \n");
				return 5;
			}
		} else if ((strstr(argv[0], "decrypt")) != 0) {
			printf("Insert your message: \n");
			fgets(input, 50, stdin);
			input[strlen(input) - 1] = '\0';
			int r = decrypt(k, input, output);
			if (r == 0) {
				fputs(output, stdout);
				free(input);
				free(output);
				return 0;
			} else if (r == 1) {
				fprintf(stderr, "Key is too short! \n");
				return 6;
			} else if (r == 2) {
				fprintf(stderr, "Key contains illegal characters! \n");
				return 7;
			} else if (r == 4) {
				fprintf(stderr,
						"The cypher-message contains illegal characters! \n");
				return 8;
			}
		}
		free(input);
		free(output);
		return 0;
	}
	if (argc == 3) {
		FILE* in;
		if ((strstr(argv[0], "encrypt")) != 0) {
			in = fopen(argv[2], "r");
			if (in == NULL) {
				fprintf(stderr, "Error while opening the file! \n");
				free(input);
				free(output);
				return 9;
			}
			fgets(input, 50, in);
			int r = encrypt(k, input, output);
			if (r == 0) {
				fputs(output, stdout);
				free(input);
				free(output);
				fclose(in);
				return 0;
			} else if (r == 1) {
				fprintf(stderr, "Key is too short! \n");
				free(input);
				free(output);
				fclose(in);
				return 11;
			} else if (r == 2) {
				fprintf(stderr, "Key contains illegal characters! \n");
				free(input);
				free(output);
				fclose(in);
				return 12;
			} else if (r == 3) {
				fprintf(stderr, "Message contains illegal characters! \n");
				free(input);
				free(output);
				fclose(in);
				return 13;
			} else {
				fprintf(stderr, "Something went completely wrong! \n");
				free(input);
				free(output);
				fclose(in);
				return 14;
			}
		} else if ((strstr(argv[0], "decrypt")) != 0) {
			in = fopen(argv[2], "r");
			if (in == NULL) {
				fprintf(stderr, "Error while opening the file! \n");
				free(input);
				free(output);
				fclose(in);
				return 15;
			}
			fgets(input, 50, in);
			int r = decrypt(k, input, output);
			if (r == 0) {
				fputs(output, stdout);
				free(input);
				free(output);
				fclose(in);
				return 0;
			} else if (r == 1) {
				fprintf(stderr, "Key is too short! \n");
				free(input);
				free(output);
				fclose(in);
				return 16;
			} else if (r == 2) {
				fprintf(stderr, "Key contains illegal characters! \n");
				free(input);
				free(output);
				fclose(in);
				return 17;
			} else if (r == 4) {
				fprintf(stderr,
						"The cypher-message contains illegal characters! \n");
				free(input);
				free(output);
				fclose(in);
				return 18;
			}
			return 0;
			free(input);
			free(output);
			fclose(in);
		}

		free(input);
		free(output);
		return 0;

	}
	free(input);
	free(output);
	return 0;

}

