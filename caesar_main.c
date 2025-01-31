#include "caesar.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char plaintext[256];
	int key;
	char *encodedText, *decodedText;

	/* Input plaintext */
	printf("Enter plaintext: ");
	fgets(plaintext, sizeof(plaintext), stdin);
	plaintext[strcspn(plaintext, "\n")] = '\0'; /* Remove newline character */

	/* Input key */
	printf("Enter key: ");
	scanf("%d", &key);

	/* Encode the text */
	encodedText = encode(plaintext, key);
	printf("Encoded text: %s\n", encodedText);

	/* Decode the text */
	decodedText = decode(encodedText, key);
	printf("Decoded text: %s\n", decodedText);

	return 0;
}
