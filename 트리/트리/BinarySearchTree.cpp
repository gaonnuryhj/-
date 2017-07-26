#include <iostream>
#include<Queue>
using namespace std;

class BST {
	class Node {
	public:
		int data;
		Node* leftchild;
		Node* rightchild;
		Node* parent;
		int depth;
	};

public:
	Node* root = new Node;

	BST();
	void Insert(int data);
	Node* Search_insert(int data);
	Node* Search(int data);
	void Delete(int data);
	void Print();
};

BST::BST() {

	root->data = NULL;
	root->leftchild = NULL;
	root->rightchild = NULL;
	root->parent = NULL;
	root->depth = 1;

}

BST::Node* BST::Search_insert(int data) {

	Node* temp = root;
	Node* newNode = new Node;
	newNode->data = NULL;
	newNode->leftchild = NULL;
	newNode->rightchild = NULL;
	newNode->parent = NULL;


	int before = 1;


	while (1) {
		before = temp->depth;
		if (data > temp->data) {
			if (temp->rightchild == NULL) {
				temp->rightchild=newNode;
				newNode->depth = temp->depth + 1;
				newNode->parent = temp;
				return newNode;
			}
			else {
				temp = temp->rightchild;
				temp->depth = before + 1;
			}
		}
		else {
			if (temp->leftchild == NULL) {
				temp->leftchild=newNode;
				newNode->depth = temp->depth + 1;
				newNode->parent = temp;
				return newNode;
			}
			else {
				temp = temp->leftchild;
				temp->depth = before + 1;
			}
		}
	}
}


BST::Node* BST::Search(int data) {

	Node* temp = root;

	while (1) {
		
		if (data > temp->data) {			
			temp = temp->rightchild;
			
		}

		else if (data < temp->data) {
			temp = temp->leftchild;
			
		}
		else
			return temp;
		
	}
}


void BST::Insert(int data) {

	if (root->data == NULL) {
		root->data = data;
	}
	else {
		Node* newNode = Search_insert(data);
		newNode->data = data;
	}	

}

void BST::Delete(int data) {

	Node* temp = Search(data);
	Node* parent = temp->parent;
	Node* target = new Node;
	target=Search(data);

	if (temp->leftchild == NULL && temp->rightchild == NULL) {
		if (data > parent->data) {
			parent->rightchild = NULL;
			delete temp;
		}
		else {
			parent->leftchild = NULL;
			delete temp;
		}
	}
	else {
		if (data <= root->data) {
			target = temp->leftchild;
			int check = 0;
			while (target->rightchild != NULL) {
				target = target->rightchild;
				check = 1;
			}
			temp->data = target->data;
			if (check == 0) {
				temp->leftchild = NULL;
				delete target;
			}
			else {
				target->parent->rightchild = NULL;
				delete target;
			}
		}
		else {
			target = temp->rightchild;
			int check = 0;
			while (target->leftchild != NULL) {
				target = target->leftchild;
				check = 1;
			}
			temp->data = target->data;
			if (check == 0) {
				temp->rightchild = NULL;
				delete target;
			}
			else {
				target->parent->leftchild = NULL;
				delete target;
			}
		}	
	
	}
}


void BST::Print() {

	Node* temp = root;
	queue<Node*> queue;
	queue.push(temp);
	int before_depth = 1;
	while (!queue.empty()) {

		temp = queue.front();
		queue.pop();

		if (before_depth != temp->depth)
			cout << endl;

		cout << temp->data << "   ";

		if (temp->leftchild != NULL)
			queue.push(temp->leftchild);
		if (temp->rightchild != NULL)
			queue.push(temp->rightchild);

		before_depth = temp->depth;
	}
	cout << endl;

}

void main() {

	BST tree;
	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(1);
	tree.Insert(3);
	tree.Insert(5);
	tree.Insert(7);
	tree.Insert(6);

	tree.Print();

	cout << endl;
	

}