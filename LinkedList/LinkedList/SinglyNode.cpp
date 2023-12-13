#include <iostream>
#include "SinglyNode.h"

Node::Node(int value) : value(value), nextNode(nullptr) {}

Node::Node(int value, Node* nextNode) : value(value), nextNode(nextNode) {}

int Node::getValue() const {
	return value;
}

Node* Node::getNextNode() const {
	return nextNode;
}

void Node::setNextNode(Node* node) {
	nextNode = node;
}