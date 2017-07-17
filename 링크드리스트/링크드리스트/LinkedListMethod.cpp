#include <iostream>
#include "List.h"

using namespace std;

List::List() {
	Head->next = NULL;
	Head->data = NULL;
	count = 0;

}

void List::insert(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if (Head->next == NULL) {
		Head->next = newNode;
	}
	else
	{
		Node* temp = Head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	count++;
}

void List::insert(int cnt, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;


	if (Head->next == NULL) {
		Head->next = newNode;
	}
	else
	{

		Node* temp = Head;
		for (int i = 0; i < cnt-1; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	count++;
}

void List::printNode() {
	Node* temp = Head;
	cout << "Head";
	for (int i = 0; i < count; i++) {
		temp = temp->next;
		cout << "->" << temp->data;
	}
	cout << endl;
}

void List::printNode(int cnt) {
	if (cnt != 0) {
		cout << cnt << " 번째 노드에 데이터가 존재합니다.";
		cout << endl;
	}
	else {
		cout << " 해당하는 데이터가 존재하지 않습니다."<<endl;
	}
}


int List::search(int data) {
	Node* temp = Head;
	int cnt = 0;
	int check = 0;

	//검색 
	for (int i = 0; i<count; i++) {
		temp = temp->next;
		cnt++;
		if (temp->data == data) {        
			check = 1;
			printNode(cnt);
			return cnt;
			break;
		}
	}

	//끝까지 봤는데 데이터가 없을 경우
	if (check == 0) {
		printNode(0);
		return 0;
	}

}

void List::remove(int data) {
	///////////////해당 노드 찾기

	Node* temp = Head;
	int cnt = 0;
	int check = 0;
	for (int i = 0; i<count; i++) {
		temp = temp->next;
		cnt++;
		if (temp->data == data) {
			check = 1;
			break;
		}
	}

    //////////////해당 노드 삭제
	if (check == 0) {
		cout << " 해당하는 데이터가 존재하지 않습니다.";
	}
	else {
		Node* temp = Head;
		Node* cur = Head;

		if (cnt == count) {   //맨 마지막 노드를 삭제할 때
			for (int i = 0; i < cnt - 1; i++) {
				temp = temp->next;
			}
			temp->next = NULL;
			delete temp->next;
			count--;
		}
		else {				//중간에 있는 노드 삭제할 때 
			for (int i = 0; i < cnt - 1; i++) {
				temp = temp->next;
				cur = temp->next;
			}

			temp->next = cur->next;
			cur->next = NULL;
			delete cur;
			count--;
		}
	}
	

}

