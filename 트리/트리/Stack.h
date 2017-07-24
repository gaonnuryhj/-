#include <iostream>

using namespace std;

class List {
	class Node {
	public:
		Node data;
		Node* next;
	};

	Node* Head = new Node;
	int count;

public:
	List();
	void push(Node* node);
	Node* pop();
};


List::List() {
	Head->data = NULL;
	Head->next = NULL;
	count = 0;
}

void List::push(Node* node) {
	Node* newNode = new Node;
	newNode->data=node;

	
	if (Head->next == NULL) {
		Head->next = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = Head->next;
		Head->next = newNode;
	}
	count++;
}

List::Node* List::pop() {

	Node* temp = Head->next;
	Head->next = temp->next;
	delete temp;

	count--;
}
