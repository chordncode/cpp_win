#pragma once

class Node {
	Node* prevNode;
	int value;
	Node* nextNode;
public:
	void setPrevNode(Node* node);
	Node* getPrevNode() const;
	void setNextNode(Node* node);
	Node* getNextNode() const;
	void setValue(int value);
	int getValue() const;
};