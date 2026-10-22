#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[100], key[] = "CIPHER";
    char cipher[27];
    int i, j, k = 0, used[26] = {0};

    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (!used[ch - 'A']) {
            cipher[k++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i])
            cipher[k++] = 'A' + i;
    }
    cipher[26] = '\0';

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Ciphertext: ");
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            j = toupper(text[i]) - 'A';
            printf("%c", cipher[j]);
        } else {
            printf("%c", text[i]);
        }
    }

    return 0;
}
