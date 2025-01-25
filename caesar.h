#ifndef CAESAR_H
#define CAESAR_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // For exit()

// Function prototypes
char* encode(char *plaintext, int key);
char* decode(char *ciphertext, int key);

#endif // CAESAR_H