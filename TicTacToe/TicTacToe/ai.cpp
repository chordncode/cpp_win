#include <iostream>
#include "ai.hpp"
#include "tictactoe.hpp"

Tictactoe t{};

int* Ai::getBestMove(int** gameBoard) {
	int depth = 15;
	int bestScore = -999;
	int* bestMove = new int[2] {0, 0};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameBoard[i][j] == 0) {
				gameBoard[i][j] = -1;
				int score = miniMax(depth - 1, gameBoard, false);
				gameBoard[i][j] = 0;

				if (score > bestScore) {
					bestMove[0] = i;
					bestMove[1] = j;
					bestScore = score;
				}
			}
		}
	}
	return bestMove;
}

int Ai::miniMax(int depth, int** gameBoard, bool isMax) {
	int turn = isMax ? 1 : -1;
	if (t.checkWinner(gameBoard, turn)) return turn * -1;
	if (t.isGameEnd(gameBoard)) return 0;
	if (depth == 0) return 0;

	if (isMax) {
		int bestScore = -999;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (gameBoard[i][j] == 0) {
					gameBoard[i][j] = -1;
					int score = miniMax(depth - 1, gameBoard, false);
					gameBoard[i][j] = 0;

					if (score > bestScore) {
						bestScore = score;
					}
				}
			}
		}
		return bestScore;
	}
	else {
		int worstScore = 999;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (gameBoard[i][j] == 0) {
					gameBoard[i][j] = 1;
					int score = miniMax(depth - 1, gameBoard, true);
					gameBoard[i][j] = 0;

					if (score < worstScore) {
						worstScore = score;
					}
				}
			}
		}
		return worstScore;
	}

}