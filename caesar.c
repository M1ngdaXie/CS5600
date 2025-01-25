#include "caesar.h"

// Helper function to check if the input contains only alphabetic characters
void validateInput(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (!isalpha(text[i]) && text[i] != ' ') { // Allow spaces
            fprintf(stderr, "Error: illegalArgument - Input contains non-alphabetic characters.\n");
            exit(EXIT_FAILURE); // Exit the program with an error code
        }
    }
}

// Encode function
char* encode(char *plaintext, int key) {
    static char encoded[256]; // Static array to hold the encoded string
    key = key % 26; // Handle keys greater than 26

    validateInput(plaintext); // Validate input before encoding

    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            encoded[i] = (char)((plaintext[i] - base + key + 26) % 26 + base);
        } else if (plaintext[i] == ' ') {
            encoded[i] = ' '; // Preserve spaces
        }
        encoded[i] = toupper(encoded[i]); // Convert to uppercase
    }
    encoded[strlen(plaintext)] = '\0'; // Null-terminate the string
    return encoded;
}

// Decode function
char* decode(char *ciphertext, int key) {
    validateInput(ciphertext); // Validate input before decoding
    return encode(ciphertext, -key); // Decoding is just encoding with a negative key
}