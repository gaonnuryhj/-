#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

/*
AVL 트리 : 이진 트리의 Search 시간복잡도는 평균 O(log n)이지만 편향트리로 만들어지는 최악의 경우 search시간이 O(n)이 걸리게 되어 O(log n)을 보장해주지 못하기 때문에
			이를 보완하기 위해 왼쪽 자식의 높이와 오른쪽 자식의 높이의 차이가 2이상이 되는 경우 Rotation을 이용하여
			Search의 시간복잡도를 O(log n)으로 보장해주는 트리

Rotation : LL - 왼쪽 자식의 높이가 2이고 오른쪽 자식의 높이는 0인데 왼쪽 자식에도 왼쪽 자식만 달려있는 경우로 ,
                리프노드를 차일드라 하고 그 부모를 부모 노드 , 그 부모의 부모노드가 조부모 노드가 될때
	            부모 노드의 오른쪽 차일드에 조부모를 넣고 왼쪽 차일드에 차일드가 오게 로테이션 시켜준다. 
		   LR - 왼쪽 자식의 높이가 2인 경우 중 왼쪽 자식의 오른쪽 자식이 존재하는 경우
		        리프노드와 리프노드의 부모노드를 LL로테이션 시켜준 후 RR로테이션 시켜준다. 


단점 : Insert,Delete할 때 Balance체크와 로테이션에 걸리는 오버헤드가 크다 . 최악의 경우 트리를 재구성해야하는 경우가 생길 수 있다. 

정적인 데이터 good, 동적인 데이터 좋지 않음

예시 : 정적인 데이터 관리하는 경우

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
			cout << "중복된 값이 있습니다";
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
	
		cout << "삽입 실패";

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