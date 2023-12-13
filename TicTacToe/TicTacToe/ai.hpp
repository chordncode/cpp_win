#pragma once

class Ai {
public:
	int* getBestMove(int** gameBoard);
	int miniMax(int depth, int** gameBoard, bool isMax);
};