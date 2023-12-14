#pragma once

class Stack {
	int size;
	int capacity;
	int* stack;
public:
	Stack();
	Stack(int capacity);
	int getSize() const;
	int getCapacity() const;
	void push(int value);
	int pop();
	int top() const;
	bool isEmpty() const;
};