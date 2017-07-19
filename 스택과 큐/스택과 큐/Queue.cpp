/*
탐색에서 사용

 큐 : BFS
 스택 : DFS
 
*/






#include <iostream>
using namespace std;

class List {
	class Node {
	public:
		int data;
		Node* next;
	};

	Node* Head= new Node;
	Node* Tail = new Node;
	int count;

public:
	List();
	void push(int data);
	void pop();
	void print();
};


List::List() {
	Head->data = NULL;
	Head->next = NULL;
	Tail->data = NULL;
	Tail->next = NULL;
	count = 0;
}

void List::push(int data) {
	Node* newNode = new Node;
	newNode->data = data;

	if (Tail->next == NULL) {
		Tail->next = newNode;
		newNode->next = NULL;
		Head->next = newNode;
	}
	else {
		Node* temp = Tail->next;
		temp->next = newNode;
		Tail->next = newNode;
		newNode->next = NULL;

	}
	count++;
	print();
}

void List::pop() {
	if (count == 1) {
		Node* temp = Head->next;
		Head->next = NULL;
		Tail->next = NULL;
		delete temp;
		count--;
		print();
		
	}
	else if (count == 0) {}

	else{
	Node* temp = Head->next;
	Head->next = temp->next;
	delete temp;
	count--;
	print();
	}
}


void List::print() {
	Node* temp = Head;

	for (int i = 0; i < count; i++) {
		temp = temp->next;
		cout << temp->data << " ";

	}

	cout << endl;
}

void main() {
	List test;
	test.push(1);
	test.push(2);
	test.pop();
}
