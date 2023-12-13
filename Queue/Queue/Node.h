#pragma once

class Node {
	int value;
	Node* nextNode;
public:
	Node(int value);
	int getValue() const;
	Node* getNext() const;
	void setNext(Node* nextNode);
};