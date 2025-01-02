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
void generateKey(char *key, int length);

// Caesar cipher functions
void caesarEncrypt(char *text) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + CAESAR_KEY) % 26;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + CAESAR_KEY) % 26;
        }
    }
}

void caesarDecrypt(char *text) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' - CAESAR_KEY + 26) % 26;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' - CAESAR_KEY + 26) % 26;
        }
    }
}

// Vigenère cipher functions
void vigenereEncrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    for(int i = 0, j = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + (key[j % keyLen] - 'a')) % 26;
            j++;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + (key[j % keyLen] - 'a')) % 26;
            j++;
        }
    }
}

void vigenereDecrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    for(int i = 0, j = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' - (key[j % keyLen] - 'a') + 26) % 26;
            j++;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' - (key[j % keyLen] - 'a') + 26) % 26;
            j++;
        }
    }
}

// XOR encryption/decryption
void xorEncrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    for(int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ key[i % keyLen];
    }
}

// Key generation
void generateKey(char *key, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < length; i++) {
        key[i] = charset[rand() % 26];
    }
    key[length] = '\0';
}

int main() {
    char text[MAX_LENGTH], key[MAX_LENGTH];
    int choice, method;
    
    srand(time(NULL));

    printf("Select encryption method:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenère Cipher\n");
    printf("3. XOR Encryption\n");
    scanf("%d", &method);
    getchar();

    printf("Select operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);
    getchar();

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = 0;

    switch(method) {
        case 1:
            if(choice == 1) caesarEncrypt(text);
            else if(choice == 2) caesarDecrypt(text);
            printf("Result: %s\n", text);
            break;

        case 2:
            generateKey(key, 8);
            printf("Generated key: %s\n", key);
            if(choice == 1) vigenereEncrypt(text, key);
            else if(choice == 2) vigenereDecrypt(text, key);
            printf("Result: %s\n", text);
            break;

        case 3:
            generateKey(key, 16);
            printf("Generated key: %s\n", key);
            xorEncrypt(text, key);
            printf("Result: %s\n", text);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}
