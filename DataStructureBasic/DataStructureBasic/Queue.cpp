#include "Queue.h"

Queue::Queue() : size(0), capacity(10), queue(new int[10]) {}
Queue::Queue(int capacity) : size(0), capacity(capacity), queue(new int[capacity]) {}
int Queue::getSize() const {
	return size;
}
int Queue::getCapacity() const {
	return capacity;
}
void Queue::push(int value) {
	if (size >= capacity) return;
	queue[size++] = value;
}
int Queue::poll() {
	if (size == 0) return -1;
	int top = queue[0];
	for (int i = 1; i < size; i++) {
		queue[i - 1] = queue[i];
	}
	size--;
	return top;
}
int Queue::top() const {
	if (size == 0) return -1;
	return queue[0];
}
bool Queue::isEmpty() {
	return size == 0;
}