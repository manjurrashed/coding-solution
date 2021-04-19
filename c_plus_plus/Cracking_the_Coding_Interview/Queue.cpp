#include <iostream>
using namespace std;
class Node {
public:
	int value;
	Node *next;
	Node(int value) {
		this->value = value;
		next = nullptr;
	}
};

class Queue {
	Node *front;
	Node *back;
	int error;
public:
	Queue() {
		front = nullptr;
		back = nullptr;
		error = 0;
	}

	void push(int value) {
		Node *temp = new Node(value);
		if (!temp)
			error = 1;
		if (back == nullptr) {
			back = temp;
			front = temp;
		} else {
			back->next = temp;
			back = back->next;
		}
	}
	int pop() {
		int value;
		if (front == nullptr) {
			cout << "underflow";
			error = -1;
			return 0;	
		}
		if (front == back) {
			value = front->value;
			delete front;
			front = nullptr;
			back = nullptr;
		} else {
			value = front->value;
			Node *temp = front;
			front = front->next;
			delete temp;
		}
		return value;
	}
	int empty() {
		if (!front)
			return 1;
		else
			return 0;
	}
};
int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);

	while (!q.empty()) {
		cout << q.pop() << endl;
	}

	q.push(4);	
	q.push(5);
	q.push(6);

	while (!q.empty()) {
		cout << q.pop() << endl;
	}

	return 0;
}
