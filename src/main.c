#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000
#define CAESAR_KEY 3

// Function prototypes
void caesarEncrypt(char *text);
void caesarDecrypt(char *text);
void vigenereEncrypt(char *text, const char *key);
void vigenereDecrypt(char *text, const char *key);
void xorEncrypt(char *text, const char *key);
void generateRandomKey(char *key, int length);
void promptForKey(char *key, int maxLength, const char *method);

// Caesar cipher functions
void caesarEncrypt(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + CAESAR_KEY) % 26;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + CAESAR_KEY) % 26;
        }
    }
}

void caesarDecrypt(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' - CAESAR_KEY + 26) % 26;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' - CAESAR_KEY + 26) % 26;
        }
    }
}

// Vigenère cipher functions
void vigenereEncrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + (key[j % keyLen] - 'a')) % 26;
            j++;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + (key[j % keyLen] - 'A')) % 26;
            j++;
        }
    }
}

void vigenereDecrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' - (key[j % keyLen] - 'a') + 26) % 26;
            j++;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' - (key[j % keyLen] - 'A') + 26) % 26;
            j++;
        }
    }
}

// XOR encryption/decryption
void xorEncrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] ^= key[i % keyLen];
    }
}

// Key generation
void generateRandomKey(char *key, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[length] = '\0';
}

// Prompt for custom key
void promptForKey(char *key, int maxLength, const char *method) {
    printf("Enter a key for %s encryption (max %d characters): ", method, maxLength);
    fgets(key, maxLength, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline
}

int main() {
    char text[MAX_LENGTH], key[MAX_LENGTH];
    int choice, method;

    srand(time(NULL));

    printf("Select encryption method:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenère Cipher\n");
    printf("3. XOR Encryption\n");
    printf("Enter choice: ");
    if (scanf("%d", &method) != 1) return 1;
    getchar();

    printf("Select operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) return 1;
    getchar();

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = 0;

    switch (method) {
        case 1:
            (choice == 1) ? caesarEncrypt(text) : caesarDecrypt(text);
            break;
        case 2:
            promptForKey(key, MAX_LENGTH, "Vigenère");
            (choice == 1) ? vigenereEncrypt(text, key) : vigenereDecrypt(text, key);
            break;
        case 3:
            promptForKey(key, MAX_LENGTH, "XOR");
            xorEncrypt(text, key);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    printf("Result: %s\n", text);
    return 0;
}
