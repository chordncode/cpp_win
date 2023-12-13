#pragma once
#include "DoublyNode.h"

class LinkedList {
	int size;
	Node* rootNode;
public:
	LinkedList();
	int getSize() const;
	int get(int index) const;
	bool add(int value);
	bool add(int index, int value);
	int remove(int index);
	bool isEmpty() const;
};