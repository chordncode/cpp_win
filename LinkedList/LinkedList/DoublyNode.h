#pragma once

class Node {
	int value;
	Node* prevNode;
	Node* nextNode;
public:
	Node(int value);
	Node(int value, Node* nextNode);
	Node(Node* prevNode, int value, Node* nextNode);
	int getValue() const;
	Node* getPrevNode() const;
	Node* getNextNode() const;
	void setPrevNode(Node* node);
	void setNextNode(Node* node);
};