#include <iostream>
#include "Queue.h"
#include "Node.h"
using namespace std;

Queue::Queue() : size{ 0 }, rootNode{ nullptr } {};
int Queue::getSize() const {
	return size;
}

bool Queue::push(int value) {
	try {
		if (size == 0) {
			rootNode = new Node(value);
			size++;
			return true;
		}
		else {
			Node* current = rootNode;
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(new Node(value));
			size++;
			return true;
		}
	}
	catch (...) {
		return false;
	}
}

int Queue::peek() const {
	try {
		if (size <= 0) throw "QueueIsEmpty";
		return rootNode->getValue();
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return 0;
	}
	catch (...) {
		return 0;
	}
}

int Queue::poll() {
	try {
		if (size <= 0) throw "QueueIsEmpty";
		Node* temp = rootNode;
		int value = temp->getValue();
		rootNode = temp->getNext();
		delete temp;
		size--;
		return value;
	}
	catch (const char* s) {
		cout << "Exception : " << s << endl;
		return 0;
	}
	catch (...) {
		return 0;
	}
}

bool Queue::isEmpty() const {
	return size == 0;
}