#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe();
    void playGame();

private:
    vector<vector<char>> board;
    char currentPlayer;
    void displayBoard();
    bool makeMove(int row, int col);
    bool checkWin();
    bool checkDraw();
    void switchPlayer();
    void resetBoard();
};

TicTacToe::TicTacToe() {
    board = vector<vector<char>>(3, vector<char>(3, ' '));
    currentPlayer = 'X';
}

void TicTacToe::displayBoard() {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
}

bool TicTacToe::makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool TicTacToe::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool TicTacToe::checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void TicTacToe::resetBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void TicTacToe::playGame() {
    bool playing = true;
    while (playing) {
        resetBoard();
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(row - 1, col - 1)) {
                gameWon = checkWin();
                if (!gameWon) {
                    gameDraw = checkDraw();
                    if (!gameDraw) {
                        switchPlayer();
                    }
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        displayBoard();
        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (gameDraw) {
            cout << "The game is a draw!\n";
        }

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y') {
            playing = false;
        }
    }
}

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
