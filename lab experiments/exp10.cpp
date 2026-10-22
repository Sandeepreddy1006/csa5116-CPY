#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char matrix[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };

    char text[] = "Must see you over Cadogan West. Coming at once.";
    char msg[200], a, b;
    int i, j, r1, c1, r2, c2, n = 0;

    for (i = 0; text[i]; i++)
        if (isalpha((unsigned char)text[i])) {
            a = toupper(text[i]);
            if (a == 'J') a = 'I';
            msg[n++] = a;
        }

    if (n % 2 != 0) msg[n++] = 'X';

    printf("Encrypted message: ");

    for (i = 0; i < n; i += 2) {
        a = msg[i];
        b = msg[i + 1];

        for (r1 = 0; r1 < 5; r1++)
            for (c1 = 0; c1 < 5; c1++)
                if (matrix[r1][c1] == a) goto found1;
        found1:;

        for (r2 = 0; r2 < 5; r2++)
            for (c2 = 0; c2 < 5; c2++)
                if (matrix[r2][c2] == b) goto found2;
        found2:;

        if (r1 == r2) {
            printf("%c%c", matrix[r1][(c1+1)%5],
                            matrix[r2][(c2+1)%5]);
        } else if (c1 == c2) {
            printf("%c%c", matrix[(r1+1)%5][c1],
                            matrix[(r2+1)%5][c2]);
        } else {
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}
