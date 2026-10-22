#include <stdio.h>
#include <string.h>

int main() {
    char cipher[] =
    "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83";

    char decrypted[500];
    char from[] = "‡†305)6*;482.)8¶";
    char to[]   = "theaionrsdcuplm";

    int i, j;

    for (i = 0; cipher[i] != '\0'; i++) {
        decrypted[i] = cipher[i];

        for (j = 0; from[j] != '\0'; j++) {
            if (cipher[i] == from[j]) {
                decrypted[i] = to[j];
                break;
            }
        }
    }

    decrypted[i] = '\0';

    printf("Ciphertext:\n%s\n\n", cipher);
    printf("Decrypted message:\n%s\n", decrypted);

    return 0;
}
