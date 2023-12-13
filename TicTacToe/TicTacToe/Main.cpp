#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string input;
		cout << "Continue? [y/n] > ";
		getline(cin, input);
		if (input[0] == 'y' || input[0] == 'Y') break;
		else cout << "Wrong Input" << endl;
	}
	return 0;
}