#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

int currentPlayer = 1; // Player 1 starts
char currentMarker;

void drawBoard() {
    cout << "\n";
    cout << "-------------\n";
    for(int i=0; i<3; i++) {
        cout << "| ";
        for(int j=0; j<3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = currentMarker;
    return true;
}

int checkWinner() {
    // Rows & columns
    for(int i=0; i<3; i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return currentPlayer;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return currentPlayer;
    }
    // Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return currentPlayer;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return currentPlayer;

    return 0;
}

void swapPlayer() {
    if(currentPlayer == 1) {
        currentPlayer = 2;
        currentMarker = 'O';
    } else {
        currentPlayer = 1;
        currentMarker = 'X';
    }
}

void game() {
    currentMarker = 'X'; // Player 1 is always X
    drawBoard();
    int winnerPlayer;

    for(int i=0; i<9; i++) {
        int slot;
        cout << "\nPlayer " << currentPlayer << " (" << currentMarker << ") - Enter slot (1-9): ";
        cin >> slot;

        if(!placeMarker(slot)) {
            cout << "Invalid slot! Already taken or out of range. Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        winnerPlayer = checkWinner();
        if(winnerPlayer == 1 || winnerPlayer == 2) {
            cout << "🎉 Player " << winnerPlayer << " (" << currentMarker << ") wins! 🎉\n";
            return;
        }

        swapPlayer();
    }

    cout << "It's a tie! 🤝\n";
}

int main() {
    cout << "===========================\n";
    cout << "🎮 TIC TAC TOE (X vs O) 🎮\n";
    cout << "===========================\n";
    game();
}
