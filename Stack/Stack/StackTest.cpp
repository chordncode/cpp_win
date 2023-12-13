#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	Stack stk{ 10 };
	cout << "Stack Capacity : " << stk.getCapacity() << endl;
	stk.push(10);
	stk.push(20);
	cout << "Size of Stack : " << stk.getSize() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.isEmpty() << endl;
	stk.pop(); // Exception!
	return 0;
}