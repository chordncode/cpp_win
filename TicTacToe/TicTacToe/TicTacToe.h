#pragma once

class TicTacToe {
	int** gameBoard;
public:
	void doTicTacToe();
	void initGameBoard();
	int* getPos();
	int* changeToCoordinate(int pos);
	void playerTurn(int* pos);
	void cpuTurn();
	void printGameBoard();
	bool canMove(int* pos);
	int checkWinner();
	bool isEnd();
};