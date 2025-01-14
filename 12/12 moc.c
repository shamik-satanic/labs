#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

void encrypt(const char* input, const char* output, char key) {
    int byte;
    FILE* inFile = fopen(input, "rb");
    FILE* outFile = fopen(output, "wb");
    if (inFile == NULL || outFile == NULL) {
        printf("\nFile open fault!");
        exit(1);
    }
    while ((byte = fgetc(inFile)) != EOF) {
        fputc(byte ^ key, outFile);
    }
    fclose(inFile);
    fclose(outFile);
}

int main() {
    char input[100], output[100], key;
    printf("Enter input file name: ");
    scanf("%s", input);
    printf("Enter output file name: ");
    scanf("%s", output);
    printf("Enter char key: ");
    scanf(" %c", &key);
    encrypt(input, output, key);
    printf("File succesfully encrypted/decrypted.\n");
    return 0;
}