#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void initializare_joc() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void afiseaza() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int verifica_starea_jocului() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
            return 1;
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-'))
        return 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-')
                return 0;
        }
    }
    return 2;
}

void mutare(char jucator) {
    int row, col;
    do {
        if (jucator == 'X') {
            printf("Este randul jucatorului %c. Insereaza mai intai randul si apoi coloana cu spatiu intre ele (0-2): ", jucator);
            if (scanf("%d %d", &row, &col) != 2) {
                printf("Input invalid. Te rog sa introduci doua numere separate prin spatiu.\n");
//                while (getchar() != '\n');
//                continue;
            }
        } else {
            srand(time(NULL));
            row = rand() % 3;
            col = rand() % 3;
        }
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
            printf("Miscare gresita! Incearca din nou.\n");
        }
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-');

    board[row][col] = jucator;
}

int main() {
//    srand(time(NULL));
    initializare_joc();
    char jucator = 'X';
    int game_over = 0;
    while (!game_over) {
        afiseaza();
        mutare(jucator);
        game_over = verifica_starea_jocului();
        if (game_over == 1) {
            printf("Jucatorul %c a castigat!\n", jucator);
        } else if (game_over == 2) {
            printf("Este egal!\n");
        }
        jucator = (jucator == 'X') ? 'O' : 'X';
    }
    afiseaza();
    return 0;
}
