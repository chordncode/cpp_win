#pragma once
#include "Node.h"

class Queue {
	int size;
	Node* rootNode;
public:
	Queue();
	int getSize() const;
	bool push(int value);
	int peek() const;
	int poll();
	bool isEmpty() const;
};