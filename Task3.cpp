#include <iostream>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        std::cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < SIZE - 1) {
            std::cout << "---|---|---\n";
        }
    }
}

bool checkWin(const char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }
    return false;
}

bool checkDraw(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(char board[SIZE][SIZE], int player) {
    int row, col;
    char mark = (player == 1) ? 'X' : 'O';
    while (true) {
        std::cout << "Player " << player << ", enter your move (row and column): ";
        std::cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = mark;
            break;
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    int player = 1;
    bool gameWon = false;
    bool gameDraw = false;

    initializeBoard(board);

    while (!gameWon && !gameDraw) {
        displayBoard(board);
        makeMove(board, player);
        gameWon = checkWin(board);
        if (gameWon) {
            displayBoard(board);
            std::cout << "Player " << player << " wins!\n";
            break;
        }
        gameDraw = checkDraw(board);
        if (gameDraw) {
            displayBoard(board);
            std::cout << "It's a draw!\n";
            break;
        }
        player = (player % 2) + 1;
    }
    return 0;
}
