#include "Stack.h"

Stack::Stack() : size(0), capacity(10), stack(new int[10]) {}
Stack::Stack(int capacity) : size(0), capacity(capacity), stack(new int[capacity]) {}

int Stack::getSize() const {
	return size;
}
int Stack::getCapacity() const {
	return capacity;
}
void Stack::push(int value) {
	if (size >= capacity) return;
	stack[size++] = value;
}
int Stack::pop() {
	if (size == 0) return -1;
	return stack[--size];
}
int Stack::top() const {
	if (size == 0) return -1;
	return stack[size - 1];
}
bool Stack::isEmpty() const {
	return size == 0;
}