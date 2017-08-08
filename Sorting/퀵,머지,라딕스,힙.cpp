/*




*/


//////////////////////////////////////ÈüÁ¤·Ä//////////////////////////////////////////////////


#include <iostream>
#include <cmath>
using namespace std;
int num;
int height = 0;
/*
class Heap {
	class Node {
	public:
		int data;
		Node* leftchild;
		Node* rightchild;

	};
public:
	Node* root = new Node;
	Heap();
	void Insert(int data);
	Node* Search();
	void HeapSort();
	Node* Sort(Node* temp);

};

Heap::Heap() {
	root->data = NULL;
	root->leftchild = NULL;
	root->rightchild = NULL;
}

void Heap::Insert(int data) {
	if (root->data == NULL) {
		root->data = data;
	}
	else {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->leftchild = NULL;
		newNode->rightchild = NULL;
		Node* temp = Search();

			if (temp->leftchild == NULL)
				temp->leftchild = newNode;
			else if (temp->rightchild == NULL)
				temp->rightchild = newNode;
		
	}
}

Heap::Node* Heap::Search() {
	Node* temp = root;

	queue<Node*> queue;

	while (temp->leftchild != NULL && temp->rightchild != NULL) {
		queue.push(temp->leftchild);
		queue.push(temp->rightchild);
		temp = queue.front();
		queue.pop();
	}

	return temp;
}

Heap::Node* Heap::Sort(Node* temp) {



}

void Heap::HeapSort() {




}

*/    // Èü Æ®¸® ÇÏ´Ù ¸¸°Å

int* Max_heapify(int* heap) {
	int temp = 0;
	while (height > 0) {
		for (int i = pow(2, height - 1); i < pow(2, height + 1); i++) {
			if (heap[i] < heap[i * 2] && i*2<=num) {
				temp = heap[i * 2];
				heap[i * 2] = heap[i];
				heap[i] = temp;
			}
			if(heap[i] < heap[i * 2+1] && (i * 2+1) <= num) {
				temp = heap[i * 2+1];
				heap[i * 2+1] = heap[i];
				heap[i] = temp;
			}		
		}	
		height--;
	}
	return heap;
}
void Heap_Sort(int* heap) {
	int temp = num;
	int replace=-1;
	while (temp > 0) {
		replace = heap[temp];
		heap[temp] = heap[1];
		heap[1] = replace;
		cout << heap[temp];
		Max_heapify(heap);
		temp--;	
	}
}

void main() {
	
	cin >> num;
	int temp = num;
	
	while (temp % 2 == 1 || temp % 2 == 0) {
		temp = temp / 2;
		height++;
	}
	int* heap = new int[num+1];
	for (int i = 1; i < num + 1; i++) {
		cin >> heap[i];
	}

	Max_heapify(heap);
	Heap_Sort(heap);

}
