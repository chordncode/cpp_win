#include "Node.h"

void Node::setPrevNode(Node* node) {
	prevNode = node;
}
Node* Node::getPrevNode() const {
	return prevNode;
}
void Node::setNextNode(Node* node) {
	nextNode = node;
}
Node* Node::getNextNode() const {
	return nextNode;
}
void Node::setValue(int value) {
	this->value = value;
}
int Node::getValue() const {
	return value;
}