#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[] =
    "KXJEYUREBEZWEHEWRYTUHEYFS"
    "KREHEGOYFIWTTTUOLKSYCAJPO"
    "BOTEIZONTXBYBNTGONEYCUZWR"
    "GDSONSXBOUYWRHEBAAHYUSEDQ";

    char key[] = "KENNEDY";
    char matrix[5][5];
    int used[26] = {0}, i, j, k = 0;
    int a, b, r1, c1, r2, c2;
    char ch;

    used['J' - 'A'] = 1;

    for (i = 0; key[i]; i++) {
        ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }

    printf("Decrypted message:\n");

    for (i = 0; text[i] && text[i + 1]; i += 2) {
        a = text[i] - 'A';
        b = text[i + 1] - 'A';

        for (r1 = 0; r1 < 5; r1++)
            for (c1 = 0; c1 < 5; c1++)
                if (matrix[r1][c1] == (a + 'A')) goto found1;

        found1:
        for (r2 = 0; r2 < 5; r2++)
            for (c2 = 0; c2 < 5; c2++)
                if (matrix[r2][c2] == (b + 'A')) goto found2;

        found2:
        if (r1 == r2) {
            putchar(matrix[r1][(c1 + 4) % 5]);
            putchar(matrix[r2][(c2 + 4) % 5]);
        } else if (c1 == c2) {
            putchar(matrix[(r1 + 4) % 5][c1]);
            putchar(matrix[(r2 + 4) % 5][c2]);
        } else {
            putchar(matrix[r1][c2]);
            putchar(matrix[r2][c1]);
        }
    }

    putchar('\n');
    return 0;
}
