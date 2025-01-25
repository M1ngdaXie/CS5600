#include "caesar.h"

int main() {
    char plaintext[256];
    int key;

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    // Input key
    printf("Enter key: ");
    scanf("%d", &key);

    // Encode the text
    char *encodedText = encode(plaintext, key);
    printf("Encoded text: %s\n", encodedText);

    // Decode the text
    char *decodedText = decode(encodedText, key);
    printf("Decoded text: %s\n", decodedText);

    return 0;
}