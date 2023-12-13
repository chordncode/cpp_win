#include <iostream>
#include "Node.h"

Node::Node(int value) : value{ value }, nextNode{ nullptr } {};
int Node::getValue() const {
	return value;
}
Node* Node::getNext() const {
	return nextNode;
}
void Node::setNext(Node* nextNode) {
	this->nextNode = nextNode;
}