#include <iostream>
using namespace std;
#define Max 100

class Tree {
	class Node {
	public:
		int data;
		Node* leftchild;
		Node* rightchild;
	};
	Node* root = new Node;
	int depth=1;
	int num = 1;
	Node* stack[Max];

public:
	Tree();
	void Insert(int data);
	Node* Search();
	void Search_Inorder(int data);
	void Search_Preorder(int data);
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
	Node* stack[Max];
	stack[0] = root;

	while (temp->leftchild != NULL) {
		

	
	}


}


void Tree::Insert(int data) {
	if (root->data == NULL) {
		root->data = data;
	}
	Node* newNode = new Node;
	newNode->data = data;
	newNode->leftchild = NULL;
	newNode->rightchild = NULL;

	Node* temp = root;

	for (temp; temp->leftchild == NULL; temp = temp->leftchild) {
		
	}
	


}