#include "LinkedList.h"

LinkedList::LinkedList() : size(), head(nullptr) {}

int LinkedList::getSize() const {
	return size;
}
int LinkedList::get(int index) const {
	if (size <= index) return -1;
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->getNextNode();
	}
	return current->getValue();
}
void LinkedList::add(int value) {
	if (head == nullptr) {
		Node* newNode = new Node();
		newNode->setValue(value);
		head = newNode;
		size++;
		return;
	}
	Node* current = head;
	while (current->getNextNode() != nullptr) {
		current = current->getNextNode();
	}
	Node* newNode = new Node();
	newNode->setValue(value);
	newNode->setPrevNode(current);
	current->setNextNode(newNode);
	size++;
}

void LinkedList::add(int index, int value) {
	if (index < 0 || size < index) return;
	if (head == nullptr) {
		Node* newNode = new Node();
		newNode->setValue(value);
		head = newNode;
		size++;
		return;
	}
	Node* current = head;
	for (int i = 0; i < index - 1; i++) {
		current = current->getNextNode();
	}
	Node* newNode = new Node();
	newNode->setValue(value);
	Node* nextNode = current->getNextNode();
	newNode->setPrevNode(current);
	newNode->setNextNode(nextNode);
	current->setNextNode(newNode);
	size++;
}
int LinkedList::remove(int index) {
	if (size <= index) return -1;
	Node* current = head;
	for (int i = 0; i < index - 1; i++) {
		current = current->getNextNode();
	}
	Node* targetNode = current->getNextNode();
	Node* nextNode = targetNode->getNextNode();
	current->setNextNode(nextNode);
	nextNode->setPrevNode(current);
	int value = targetNode->getValue();
	delete targetNode;
	targetNode = nullptr;
	size--;
	return value;
}
bool LinkedList::isEmpty() const {
	return size == 0;
}