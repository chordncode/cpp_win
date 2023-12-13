#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

LinkedList::LinkedList() : size(0), rootNode(nullptr) {}

int LinkedList::getSize() const {
	return size;
}

int LinkedList::get(int index) const {
	try {
		if (size == 0) throw "ListIsEmpty";
		if (index < 0 || index >= size) throw "IndexOutOfBounds";
		Node* current = rootNode;
		for (int i = 0; i < index; i++) {
			current = current->getNextNode();
		}
		return current->getValue();
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return 0;
	}
	catch (...) {
		cout << "Exception : Others" << endl;
		return 0;
	}
}

bool LinkedList::add(int value) {
	try {
		if (size == 0) {
			rootNode = new Node(value);
			size++;
			return true;
		}
		Node* current = rootNode;
		while (current->getNextNode() != nullptr) {
			current = current->getNextNode();
		}
		Node* newNode = new Node(current, value, nullptr);
		current->setNextNode(newNode);
		size++;
		return true;
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return false;
	}
	catch (...) {
		cout << "Exception : Others" << endl;
		return false;
	}
}

bool LinkedList::add(int index, int value) {
	try {
		if (index < 0 || index > size) throw "IndexOutOfBounds";
		if (index == 0) {
			rootNode = new Node(value, rootNode);
			size++;
			return true;
		}
		Node* current = rootNode;
		for (int i = 0; i < index - 1; i++) {
			current = current->getNextNode();
		}
		Node* newNode = new Node(current, value, current->getNextNode());
		current->setNextNode(newNode);
		size++;
		return true;
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return false;
	}
	catch (...) {
		cout << "Exception : Others" << endl;
		return false;
	}
}

int LinkedList::remove(int index) {
	try {
		if (index < 0 || index >= size) throw "IndexOutOfBounds";
		if (index == 0) {
			Node* targetNode = rootNode;
			rootNode = targetNode->getNextNode();
			int value = targetNode->getValue();
			delete targetNode;
			size--;
			return value;
		}
		Node* current = rootNode;
		for (int i = 0; i < index - 1; i++) {
			current = current->getNextNode();
		}
		Node* targetNode = current->getNextNode();
		if (targetNode->getNextNode() == nullptr) {
			int value = targetNode->getValue();
			delete targetNode;
			current->setNextNode(nullptr);
			size--;
			return value;
		}
		Node* nextNode = targetNode->getNextNode();
		nextNode->setPrevNode(current);
		current->setNextNode(nextNode);
		int value = targetNode->getValue();
		delete targetNode;
		size--;
		return value;
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return false;
	}
	catch (...) {
		cout << "Exception : Others" << endl;
		return false;
	}
}

bool LinkedList::isEmpty() const {
	return size == 0;
}