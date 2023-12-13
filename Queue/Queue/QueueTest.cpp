#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue q{};
	cout << "값을 저장 : ";
	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
		q.push(i);
	}
	cout << endl;
	cout << "Queue Size : " << q.getSize() << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Queue Poll : " << q.poll() << endl;
	}
	return 0;
}