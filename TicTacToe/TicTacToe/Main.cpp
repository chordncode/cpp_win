#include <iostream>
#include <string>
#include "TicTacToe.h"
using namespace std;

int main() {
	while (true) {
		TicTacToe t{};
		t.doTicTacToe();
		string input;
		cout << "Continue? [y/n] > ";
		getline(cin, input);
		if (input[0] == 'n' || input[0] == 'N') break;
		else cout << "Wrong Input" << endl;
	}
	return 0;
}