//#include <iostream>
//using namespace std;
//
//class List {
//	class Node {
//	public:
//		int data;
//		Node* next;
//	};
//
//	Node* Head = new Node;
//	int count;
//
//public:
//	List();
//	void push(int data);
//	void pop();
//	void print();
//};
//
//
//List::List() {
//	Head->data = NULL;
//	Head->next = NULL;
//	count = 0;
//}
//
//void List::push(int data) {
//	Node* newNode = new Node;
//	newNode->data = data;
//
//	
//	if (Head->next == NULL) {
//		Head->next = newNode;
//		newNode->next = NULL;
//	}
//	else {
//		newNode->next = Head->next;
//		Head->next = newNode;
//	}
//	count++;
//	print();
//}
//
//void List::pop() {
//
//	Node* temp = Head->next;
//	Head->next = temp->next;
//	delete temp;
//
//	count--;
//	print();
//}
//
//
//void List::print() {
//	Node* temp = Head;
//
//	for (int i = 0; i < count; i++) {
//		temp = temp->next;
//		cout << temp->data << " ";
//
//	}
//
//	cout << endl;
//}
//
//
//void main() {
//	List test;
//	test.push(1);
//
//	test.push(2);
//	test.push(3);
//
//	test.pop();
//}
//
//
