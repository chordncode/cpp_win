#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
using namespace std;

int main() {
	/*
	Queue q{ 5 };
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	cout << "Now Queue Size : " << q.getSize() << endl;
	cout << "Queue poll() : " << q.poll() << endl;
	cout << "Queue poll() : " << q.poll() << endl;
	cout << "Now Queue Size : " << q.getSize() << endl;
	cout << "Queue top() : " << q.top() << endl;
	cout << "Now Queue Size : " << q.getSize() << endl;
	cout << "Queue poll() : " << q.poll() << endl;
	cout << "Queue poll() : " << q.poll() << endl;
	cout << "Queue poll() : " << q.poll() << endl;
	cout << "Now Queue Size : " << q.getSize() << endl;
	cout << "Queue poll() : " << q.poll() << endl;

	cout << endl;
	cout << "------------------------------------" << endl;
	cout << endl;

	Stack s{ 5 };
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	cout << "Now Stack Size : " << s.getSize() << endl;
	cout << "Stack pop() : " << s.pop() << endl;
	cout << "Stack pop() : " << s.pop() << endl;
	cout << "Now Stack Size : " << s.getSize() << endl;
	cout << "Stack top() : " << s.top() << endl;
	cout << "Now Stack Size : " << s.getSize() << endl;
	cout << "Stack pop() : " << s.pop() << endl;
	cout << "Stack pop() : " << s.pop() << endl;
	cout << "Stack pop() : " << s.pop() << endl;
	cout << "Now Stack Size : " << s.getSize() << endl;
	cout << "Stack pop() : " << s.pop() << endl;
	*/
	LinkedList l{};
	l.add(0, 300);
	l.add(10);
	l.add(20);
	l.add(30);
	cout << "Now List : ";
	for (int i = 0; i < l.getSize(); i++) {
		cout << l.get(i) << " ";
	}
	cout << endl;
	l.add(0, 100);
	cout << "Now List : ";
	for (int i = 0; i < l.getSize(); i++) {
		cout << l.get(i) << " ";
	}
	cout << endl;
	l.remove(1);
	cout << "Now List : ";
	for (int i = 0; i < l.getSize(); i++) {
		cout << l.get(i) << " ";
	}
	cout << endl;
	cout << "Now List Size is : " << l.getSize() << endl;
	l.add(2, 200);
	cout << "Now List : ";
	for (int i = 0; i < l.getSize(); i++) {
		cout << l.get(i) << " ";
	}
	cout << endl;
	return 0;
}