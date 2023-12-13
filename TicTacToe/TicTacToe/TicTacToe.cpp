#include <iostream>
#include "tictactoe.hpp"
#include "ai.hpp"
using namespace std;

Ai ai{};
Tictactoe::Tictactoe() : turn(1), gameBoard(new int* [3]) {}

void Tictactoe::initGameBoard() {
    for (int i = 0; i < 3; i++) {
        gameBoard[i] = new int[3];
        gameBoard[i][0] = 0;
        gameBoard[i][1] = 0;
        gameBoard[i][2] = 0;
    }
}

void Tictactoe::doTictactoe() {
    cout << "Hello!" << endl;
    this->initGameBoard();
    int winner = 0;
    while (true) {
        printBoard(gameBoard);
        int* pos = nullptr;
        if (turn == 1) {
            pos = getPos();
            if (!canMove(pos)) {
                cout << "Invalid position" << endl;
                continue;
            }
        } else if (turn == -1) {
            int** copiedGameBoard = copyBoard();
            pos = ai.getBestMove(copiedGameBoard);
        }
        placePiece(pos);
        if (checkWinner(gameBoard, turn)) {
            printWinnerFlag();
            break;
        }
        if (isGameEnd(gameBoard)) {
            printDrawFlag();
            break;
        }
        changeTurn();
    }
    printBoard(gameBoard);
}

int* Tictactoe::getPos() {
    int input = 0;
    while (true) {
        cout << "Enter a position > ";
        cin >> input;
        if (input >= 1 && input <= 9) break;
        else cout << "Invalid input" << endl;
    }
    return changeToCoordinate(input);
}
int* Tictactoe::changeToCoordinate(int pos) {
    int* coordinate = new int[2];
    switch (pos) {
    case 1: coordinate[0] = 0; coordinate[1] = 0; break;
    case 2: coordinate[0] = 0; coordinate[1] = 1; break;
    case 3: coordinate[0] = 0; coordinate[1] = 2; break;
    case 4: coordinate[0] = 1; coordinate[1] = 0; break;
    case 5: coordinate[0] = 1; coordinate[1] = 1; break;
    case 6: coordinate[0] = 1; coordinate[1] = 2; break;
    case 7: coordinate[0] = 2; coordinate[1] = 0; break;
    case 8: coordinate[0] = 2; coordinate[1] = 1; break;
    case 9: coordinate[0] = 2; coordinate[1] = 2; break;
    }
    return coordinate;
}
void Tictactoe::placePiece(int* pos) {
    gameBoard[pos[0]][pos[1]] = turn;
}
bool Tictactoe::canMove(int* pos) {
    return gameBoard[pos[0]][pos[1]] == 0;
}

bool Tictactoe::isGameEnd(int** gameBoard) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == 0) return false;
        }
    }
    return true;
}

bool Tictactoe::checkWinner(int** gameBoard, int turn) {
    if (gameBoard[0][0] == turn && gameBoard[0][1] == turn && gameBoard[0][2] == turn) return true;
    if (gameBoard[1][0] == turn && gameBoard[1][1] == turn && gameBoard[1][2] == turn) return true;
    if (gameBoard[2][0] == turn && gameBoard[2][1] == turn && gameBoard[2][2] == turn) return true;
    if (gameBoard[0][0] == turn && gameBoard[1][0] == turn && gameBoard[2][0] == turn) return true;
    if (gameBoard[0][1] == turn && gameBoard[1][1] == turn && gameBoard[2][1] == turn) return true;
    if (gameBoard[0][2] == turn && gameBoard[1][2] == turn && gameBoard[2][2] == turn) return true;
    if (gameBoard[0][0] == turn && gameBoard[1][1] == turn && gameBoard[2][2] == turn) return true;
    if (gameBoard[0][2] == turn && gameBoard[1][1] == turn && gameBoard[2][0] == turn) return true;
    return false;
}
void Tictactoe::printBoard(int** gameBoard) {
    for (int i = 0; i < 3; i++) {
        if (i > 0) cout << "¦¡¦«¦¡¦«¦¡" << endl;
        for (int j = 0; j < 3; j++) {
            if (j > 0) cout << "¦¢";
            if (gameBoard[i][j] == 1) cout << "O";
            else if (gameBoard[i][j] == -1) cout << "X";
            else cout << " ";
        }
        cout << endl;
    }
}

void Tictactoe::printWinnerFlag() {
    if (turn == 1) cout << "Player Wins!" << endl;
    else if (turn == -1) cout << "CPU Wins!" << endl;
}

void Tictactoe::printDrawFlag() {
    cout << "Draw!" << endl;
}

void Tictactoe::changeTurn() {
    turn *= -1;
}

int** Tictactoe::copyBoard() {
    int** copiedGameBoard = new int* [3];
    for (int i = 0; i < 3; i++) {
        copiedGameBoard[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            copiedGameBoard[i][j] = gameBoard[i][j];
        }
    }
    return copiedGameBoard;
}