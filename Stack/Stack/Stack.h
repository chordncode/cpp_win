#pragma once

class Stack {
	int capacity;
	int size;
	int* space;
public:
	Stack(int capacity);
	int getCapacity() const;
	int getSize() const;
	bool push(int value);
	int peek() const;
	int pop();
	bool isEmpty() const;
};