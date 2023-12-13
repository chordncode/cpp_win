#include <iostream>
#include <string>
#include "tictactoe.hpp"
using namespace std;

int main() {
    while (true) {
        Tictactoe game;
        game.doTictactoe();
        cin.ignore();
        string input;
        while (true) {
            cout << "Continue ? [y/n] > ";
            getline(cin, input);
            if (input == "n" || input == "N") return 0;
            else if (input == "y" || input == "Y") break;
            cout << "Invalid Answer" << endl;
        }
    }
    return 0;
}