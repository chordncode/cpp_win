#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int capacity) : capacity(capacity), size(0), space(new int[capacity]) {};
int Stack::getCapacity() const {
	return capacity;
}
int Stack::getSize() const {
	return size;
}
bool Stack::push(int value) {
	try {
		if (size > capacity) throw "StackOutOfCapacity";
		space[size++] = value;
		return true;
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return false;
	}
	catch (...) {
		return false;
	}
}
int Stack::peek() const {
	try {
		if (size <= 0) throw "StackIsEmpty";
		return space[size - 1];
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return 0;
	}
	catch (...) {
		return 0;
	}
}
int Stack::pop() {
	try {
		if (size <= 0) throw "StackIsEmpty";
		return space[--size];
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return 0;
	}
	catch (...) {
		return 0;
	}
}
bool Stack::isEmpty() const {
	return size == 0;
}