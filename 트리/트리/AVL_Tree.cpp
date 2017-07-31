#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

/*
AVL Ʈ�� : ���� Ʈ���� Search �ð����⵵�� ��� O(log n)������ ����Ʈ���� ��������� �־��� ��� search�ð��� O(n)�� �ɸ��� �Ǿ� O(log n)�� ���������� ���ϱ� ������
			�̸� �����ϱ� ���� ���� �ڽ��� ���̿� ������ �ڽ��� ������ ���̰� 2�̻��� �Ǵ� ��� Rotation�� �̿��Ͽ�
			Search�� �ð����⵵�� O(log n)���� �������ִ� Ʈ��

Rotation : LL - ���� �ڽ��� ���̰� 2�̰� ������ �ڽ��� ���̴� 0�ε� ���� �ڽĿ��� ���� �ڽĸ� �޷��ִ� ���� ,
                ������带 ���ϵ�� �ϰ� �� �θ� �θ� ��� , �� �θ��� �θ��尡 ���θ� ��尡 �ɶ�
	            �θ� ����� ������ ���ϵ忡 ���θ� �ְ� ���� ���ϵ忡 ���ϵ尡 ���� �����̼� �����ش�. 
		   LR - ���� �ڽ��� ���̰� 2�� ��� �� ���� �ڽ��� ������ �ڽ��� �����ϴ� ���
		        �������� ��������� �θ��带 LL�����̼� ������ �� RR�����̼� �����ش�. 


���� : Insert,Delete�� �� Balanceüũ�� �����̼ǿ� �ɸ��� ������尡 ũ�� . �־��� ��� Ʈ���� �籸���ؾ��ϴ� ��찡 ���� �� �ִ�. 

������ ������ good, ������ ������ ���� ����

���� : ������ ������ �����ϴ� ���

http://egloos.zum.com/printf/v/913998

*/






class AVL {
	class Node {
	public:
		int data;
		Node* leftchild;
		Node* rightchild;
		int balance;		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

	};
public:
	Node* root = new Node;


	AVL();
	Node* Insert(Node* root,int data);
	Node* Search(int data);
	void Delete(int data);
	Node* LL(Node* node);
	Node* LR(Node* node);
	Node* RL(Node* node);
	Node* RR(Node* node);
	int Check_Height(Node* node);
	int Check_Balance(Node* node);
	Node* Get_Balance(Node* node);
	void Print();

};


AVL::AVL(){
	root->data = NULL;
	root->balance = 0;
	root->leftchild = NULL;
	root->rightchild = NULL;

}
//
//void AVL::Insert(int data) {
//	if (root->data == NULL) {
//		root->data = data;
//	}
//	else{
//		Node* parent = Search(data);
//
//		Node* temp = new Node;
//		temp->data = data;
//		temp->leftchild = NULL;
//		temp->rightchild = NULL;
//		temp->balance = 0;
//
//		if (data > parent->data) {
//			parent->rightchild = temp;
//			Check_Balance(root);
//		}
//		else {
//			parent->leftchild = temp;
//			Check_Balance(root);
//		}
//	
//	}
//	
//}

AVL::Node* AVL::Search(int data) {

	Node* temp = root;

	while (1) {

		if (data > temp->data) {
			if (temp->rightchild != NULL)
				temp = temp->rightchild;
			else
				return temp;

		}

		else if (data < temp->data) {
			if (temp->leftchild != NULL)
				temp = temp->leftchild;
			else
				return temp;
		}
		else {
			cout << "�ߺ��� ���� �ֽ��ϴ�";
			break;
		}
	}
}

int AVL::Check_Height(Node* node) {

	int depth = 0;

	if (node != NULL)
		depth = 1 + max(Check_Height(node->leftchild), Check_Height(node->rightchild));

	return depth;

}

int AVL::Check_Balance(Node* node) {
	if (node == NULL)
		return 0;

	return Check_Height(node->leftchild) - Check_Height(node->rightchild);
}


AVL::Node* AVL::LL(Node* node) {

	Node* child = node->leftchild;
	node->leftchild = child->rightchild;
	child->rightchild = node;
	return child;


}
AVL::Node* AVL::LR(Node* node) {
	Node* child = node->leftchild;
	node->leftchild = RR(child);
	return RR(node);
}


AVL::Node* AVL::RL(Node* node) {
	Node* child = node->rightchild;
	node->rightchild = LL(child);
	return LL(node);
}

AVL::Node* AVL::RR(Node* node) {

	Node* child = node->rightchild;
	node->rightchild = child->leftchild;
	child->leftchild = node;

	return child;
}

AVL::Node* AVL::Get_Balance(Node* node) {

	int depth = Check_Balance(node);

	if (depth > 1) {

		if (Check_Balance(node->leftchild) > 0)
			node = LL(node);
		else
			node = LR(node);
	}
	else if (depth < -1) {
		if (Check_Balance(node->rightchild) > 0)
			node = RR(node);
		else
			node = RL(node);
	
	}
	return node;
}

AVL::Node* AVL::Insert(Node* root, int data) {

	if (root == NULL)
		root->data = data;

	else if (data < root->data) {
		root->leftchild = Insert(root->leftchild, data);
		root = Get_Balance(root);
	}

	else if (data > root->data) {
		root->leftchild = Insert(root->leftchild, data);
		root = Get_Balance(root);
	}
	else {
	
		cout << "���� ����";

	}

	return root;
}

void AVL::Print() {

	Node* temp = root;
	queue<Node*> queue;
	queue.push(temp);
	int before_depth = 1;
	while (!queue.empty()) {

		temp = queue.front();
		queue.pop();

		cout << temp->data << "   ";

		if (temp->leftchild != NULL)
			queue.push(temp->leftchild);
		if (temp->rightchild != NULL)
			queue.push(temp->rightchild);

	}
	cout << endl;

}

void main() {
	AVL tree;
	tree.Insert(tree.root, 1);
	tree.Print();
	tree.Insert(tree.root, 2);
	tree.Print();
	tree.Insert(tree.root, 3);
	tree.Print();
	tree.Insert(tree.root, 4);
	tree.Print();
	tree.Insert(tree.root, 5);
	tree.Print();
	tree.Insert(tree.root, 6);
	tree.Print();

}