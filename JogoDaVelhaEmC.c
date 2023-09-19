#include <stdio.h>

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if the game is over
int isGameOver(char board[3][3]) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Column win
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Diagonal win

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Diagonal win

    // Check if the board is full (a draw)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // The game is not over yet
        }
    }

    return -1; // It's a draw
}

// Function to make a move
int makeMove(char board[3][3], int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        return 0; // Invalid move

    board[row][col] = player;
    return 1; // Valid move
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int currentPlayer = 1; // 1 for player X, 2 for player O

    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) {
        printf("Current board:\n");
        printBoard(board);

        int row, col;
        printf("Player %c, enter your move (row and column): ", (currentPlayer == 1) ? 'X' : 'O');
        scanf("%d %d", &row, &col);

        if (makeMove(board, row, col, (currentPlayer == 1) ? 'X' : 'O')) {
            int result = isGameOver(board);

            if (result == 1) {
                printf("Player %c wins!\n", (currentPlayer == 1) ? 'X' : 'O');
                break;
            } else if (result == -1) {
                printf("It's a draw!\n");
                break;
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
