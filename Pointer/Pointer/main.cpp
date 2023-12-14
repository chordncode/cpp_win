#include <iostream>
using namespace std;

int& func() {
	int a = 2;
	return a;
}

int main() {
	int b = func();
	return 0;
}