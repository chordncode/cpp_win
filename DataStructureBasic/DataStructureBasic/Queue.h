#pragma once

class Queue {
	int size;
	int capacity;
	int* queue;
public:
	Queue();
	Queue(int capacity);
	int getSize() const;
	int getCapacity() const;
	void push(int value);
	int poll();
	int top() const;
	bool isEmpty();
};