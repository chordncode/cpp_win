#pragma once

class Tictactoe {
public:
    Tictactoe();
    int turn;
    int** gameBoard;
    void initGameBoard();
    void doTictactoe();
    int* getPos();
    int* changeToCoordinate(int pos);
    void placePiece(int* pos);
    bool canMove(int* pos);
    bool isGameEnd(int** gameBoard);
    bool checkWinner(int** gameBoard, int turn);
    void printBoard(int** gameBoard);
    void printWinnerFlag();
    void printDrawFlag();
    void changeTurn();
    int** copyBoard();
};