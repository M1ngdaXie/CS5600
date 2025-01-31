#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 256 // Define max length for input strings

// Validate input: return 1 if valid, 0 if invalid
int validate_input(const char *text)
{
	int i;

	for (i = 0; text[i] != '\0'; i++) {
		if (!isalpha(text[i]) && text[i] != ' ') {
			fprintf(stderr, "Error: illegalArgument - Input contains non-alphabetic characters.\n");
			return 0; // Return failure
		}
	}
	return 1; // Valid input
}

// Encode function
char *encode(const char *plaintext, int key)
{
	static char encoded[MAX_LEN]; // Static buffer (thread-unsafe)
	int i;
	
	if (!validate_input(plaintext))
		return NULL; // Return NULL if invalid

	key = key % 26; // Normalize key

	for (i = 0; plaintext[i] != '\0'; i++) {
		if (isalpha(plaintext[i])) {
			char base = islower(plaintext[i]) ? 'a' : 'A';
			encoded[i] = (char) (((plaintext[i] - base + key + 26) % 26) + base);
			encoded[i] = toupper(encoded[i]); // Convert to uppercase
		} else {
			encoded[i] = plaintext[i]; // Preserve spaces
		}
	}
	encoded[i] = '\0'; // Null-terminate string
	return encoded;
}

// Decode function
char *decode(const char *ciphertext, int key)
{
	if (!validate_input(ciphertext))
		return NULL; // Return NULL if invalid
	
	return encode(ciphertext, -key); // Decoding is just encoding with -key
}

// Main function for testing
int main(void)
{
	char text[MAX_LEN];
	int key;

	printf("Enter text: ");
	fgets(text, MAX_LEN, stdin);
	text[strcspn(text, "\n")] = '\0'; // Remove newline

	printf("Enter key: ");
	scanf("%d", &key);

	char *cipher = encode(text, key);
	if (cipher)
		printf("Encoded: %s\n", cipher);

	char *plain = decode(cipher, key);
	if (plain)
		printf("Decoded: %s\n", plain);

	return 0;
}
