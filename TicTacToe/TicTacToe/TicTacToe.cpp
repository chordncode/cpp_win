#include <iostream>
#include <string>
#include "TicTacToe.h"
using namespace std;

void TicTacToe::initGameBoard() {
	if (gameBoard != nullptr) {
		delete gameBoard;
		gameBoard = nullptr;
	}
	gameBoard = new int* [3];
	gameBoard[0] = new int[3] {0, 0, 0};
	gameBoard[1] = new int[3] {0, 0, 0};
	gameBoard[2] = new int[3] {0, 0, 0};
}

void TicTacToe::doTicTacToe() {
	while (true) {
		int* pos = getPos();
		if (!canMove(pos)) {
			cout << "You can't place there" << endl;
			continue;
		}
		playerTurn(pos);
		printGameBoard();
		break;
	}
}

int* TicTacToe::getPos() {
	while (true) {
		int input = 0;
		try {
			cout << "Select position [1-9] > ";
			cin >> input;
			if (input < 1 || input > 9) throw "Wrong Number";
			cin.ignore();
			return changeToCoordinate(input);
		}
		catch (const char* s) {
			cout << s << endl;
			input = 0;
		}
		catch (...) {
			input = 0;
		}
	}
}

int* TicTacToe::changeToCoordinate(int pos) {
	int* posArr = new int[2] {0, 0};
	switch (pos) {
	case 1:
		posArr[0] = 0;
		posArr[1] = 0;
		break;
	case 2:
		posArr[0] = 0;
		posArr[1] = 1;
		break;
	case 3:
		posArr[0] = 0;
		posArr[1] = 2;
		break;
	case 4:
		posArr[0] = 1;
		posArr[1] = 0;
		break;
	case 5:
		posArr[0] = 1;
		posArr[1] = 1;
		break;
	case 6:
		posArr[0] = 1;
		posArr[1] = 2;
		break;
	case 7:
		posArr[0] = 2;
		posArr[1] = 0;
		break;
	case 8:
		posArr[0] = 2;
		posArr[1] = 1;
		break;
	case 9:
		posArr[0] = 2;
		posArr[1] = 2;
		break;
	}
	return posArr;
}

void TicTacToe::playerTurn(int* pos) {
	gameBoard[pos[0]][pos[1]] = 1;
}

void TicTacToe::cpuTurn() {

}

void TicTacToe::printGameBoard() {
	for (int i = 0; i < 3; i++) {
		if (i > 0) cout << "¦¡¦«¦¡¦«¦¡" << endl;
		for (int j = 0; j < 3; j++) {
			if (j > 0) cout << "¦¢";
			cout << gameBoard[i][j];
		}
		cout << endl;
	}
}

bool TicTacToe::canMove(int* pos) {
	return gameBoard[pos[0]][pos[1]] == 0;
}

int TicTacToe::checkWinner() {
	return 0;
}

bool TicTacToe::isEnd() {
	return true;
}