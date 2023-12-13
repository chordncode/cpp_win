#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

void printList(LinkedList list);

int main() {
	LinkedList list{};
	cout << "Data added  : ";
	for (int i = 1; i <= 3; i++) {
		cout << i * 10 << " ";
		list.add(i * 10);
	}
	cout << endl;
	cout << "List Size : " << list.getSize() << endl;
	printList(list);
	cout << "Add New Data : index[3] = 50" << endl;
	list.add(3, 50);
	printList(list);
	cout << "Add New Data : index[0] = 100" << endl;
	list.add(0, 100);
	printList(list);
	cout << "Remote Data : index[2] = 20" << endl;
	list.remove(2);
	printList(list);
}

void printList(LinkedList list) {
	for (int i = 0; i < list.getSize(); i++) {
		cout << "List[" << i << "] : " << list.get(i) << endl;
	}
}