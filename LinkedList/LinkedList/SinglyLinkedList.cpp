#include <iostream>
#include "SinglyNode.h"
#include "SinglyLinkedList.h"
using namespace std;

LinkedList::LinkedList() : size(0), rootNode(nullptr) {}

int LinkedList::getSize() const {
	return size;
}

int LinkedList::get(int index) const {
	try {
		if (rootNode == nullptr) throw "ListIsEmpty";
		if (index >= size) throw "IndexOutOfBounds";

		int count = 0;
		Node* current = rootNode;
		while (current != nullptr) {
			if (count == index) return current->getValue();
			current = current->getNextNode();
			count++;
		}
		return 0;
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
		current->setNextNode(new Node(value));
		size++;
		return true;
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
			Node* newNextNode = new Node(value, rootNode);
			rootNode = newNextNode;
			size++;
			return true;
		}
		Node* current = rootNode;
		for (int i = 0; i < index - 1; i++) {
			current = current->getNextNode();
		}
		Node* oldNextNode = current->getNextNode();
		Node* newNextNode = new Node(value, oldNextNode);
		current->setNextNode(newNextNode);
		size++;
		return true;
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return 0;
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
			size--;
			return value;
		}
		Node* nextNode = targetNode->getNextNode();
		current->setNextNode(nextNode);
		int value = targetNode->getValue();
		delete targetNode;
		size--;
		return value;
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

bool LinkedList::isEmpty() const {
	return size == 0;
}