#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// void createCipherAlphabet(char alphabet[], int n) {
//     char *letter = alphabet;
//     while (*letter) {
//         *letter = toupper(*letter);
//         *letter = (((*letter) - 'A' + n) % 26) + 'A';
//         letter++;
//     }
// }

void encrypt(char msg[], int n) {
    char *letter = msg;
    while (*letter) {
        if (isalpha(*letter)) {
            *letter = toupper(*letter);
            int shifted = (*letter - 'A' + n) % 26;
            if (shifted < 0) {
                shifted += 26;
            }
            *letter = shifted + 'A';
        }
        letter++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: cipher shift str\n");
        exit(1);
    } else {
        int n = atoi(argv[1]);
        char *msg = argv[2];
        encrypt(msg, n);
        printf("%s\n", msg);
    }
    return 0;
}