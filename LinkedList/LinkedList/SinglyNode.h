#pragma once

class Node {
	int value;
	Node* nextNode;
public:
	Node(int value);
	Node(int value, Node* nextNode);
	int getValue() const;
	Node* getNextNode() const;
	void setNextNode(Node* node);
};