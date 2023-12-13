#include <iostream>
#include "DoublyNode.h"

Node::Node(int value) : value(value), prevNode(nullptr), nextNode(nullptr) {}
Node::Node(int value, Node* nextNode) : value(value), nextNode(nextNode), prevNode(nullptr) {}
Node::Node(Node* prevNode, int value, Node* nextNode) : prevNode(prevNode), value(value), nextNode(nextNode) {}

int Node::getValue() const {
	return value;
}

Node* Node::getPrevNode() const {
	return prevNode;
}

Node* Node::getNextNode() const {
	return nextNode;
}

void Node::setPrevNode(Node* node) {
	prevNode = node;
}

void Node::setNextNode(Node* node) {
	nextNode = node;
}