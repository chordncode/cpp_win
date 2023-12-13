#include <iostream>
#include "add.h"
using namespace std;

int main() {
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	cout << a << " + " << b << " = " << sum << endl;
	return 0;
}