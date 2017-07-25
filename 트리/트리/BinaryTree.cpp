#include <iostream>
#include <queue>
using namespace std;
#define Max 100


class Tree {
	class Node {
	public:
		int data;
		Node* leftchild;
		Node* rightchild;
	};
public:
	Node* root = new Node;
	int depth=1;
	int num = 1;
	Node* stack[Max];


	Tree();
	void Insert(int data);
	Node* Search();
	void Inorder(Node* temp);
	void Preorder(Node* temp);
	void Delete();
	void PrintTree();

};

Tree::Tree() {
	root->data = NULL;
	root->leftchild = NULL;
	root->rightchild = NULL;

	for (int i = 0; i < Max; i++)
		stack[i] = NULL;

}

Tree::Node* Tree::Search() {
	Node* temp = root;
	Node* newNode = new Node;
	newNode->data = NULL;
	newNode->leftchild = NULL;
	newNode->rightchild = NULL;
	queue<Node*> queue;
	
	while (temp->leftchild != NULL && temp->rightchild != NULL ) {
		queue.push(temp->leftchild);
		queue.push(temp->rightchild);
		temp = queue.front();
		queue.pop();		
	}

	if (temp->leftchild == NULL)
		temp->leftchild = newNode;
	else
		temp->rightchild = newNode;
		
	return newNode;

}


void Tree::Insert(int data) {
	if (root->data == NULL) {
		root->data = data;
	}
	else {

		Node* newNode = Search();
		newNode->data = data;	
	}
}

void Tree::PrintTree() {

	Node* temp = root;
	queue<Node*> queue;
	queue.push(temp);

	while (!queue.empty()) {

		temp = queue.front();
		queue.pop();

		num++;
		if (num % 2 ^ depth == 0) {
			depth++;
			cout << endl;
		}

		cout <<temp->data << "   ";

		if(temp->leftchild!=NULL)
			queue.push(temp->leftchild);
		if(temp->rightchild!=NULL)
			queue.push(temp->rightchild);
		
	}

}

void Tree::Inorder(Node* temp) {

	cout << temp->data<< "   ";

	if (temp->leftchild != NULL)
		Inorder(temp->leftchild);

	if (temp->rightchild != NULL)
		Inorder(temp->rightchild);

}

void Tree::Preorder(Node* temp) {	

	if (temp->leftchild != NULL)
		Preorder(temp->leftchild);

	cout << temp->data << "   ";

	if (temp->rightchild != NULL)
		Preorder(temp->rightchild);

}


void main() {

	Tree tree;

	tree.Insert(1);
	tree.Insert(2);
	tree.Insert(3);
	tree.Insert(4);
	tree.Insert(5);
	tree.PrintTree();
	cout << endl;

	tree.Preorder(tree.root);
	cout << endl;

	tree.Inorder(tree.root);
}