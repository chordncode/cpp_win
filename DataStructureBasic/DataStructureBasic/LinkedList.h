#pragma once
#include "Node.h"

class LinkedList {
	int size;
	Node* head;
public:
	LinkedList();
	int getSize() const;
	int get(int index) const;
	void add(int value);
	void add(int index, int value);
	int remove(int index);
	bool isEmpty() const;
};