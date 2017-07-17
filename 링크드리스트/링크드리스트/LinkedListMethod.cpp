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
		cout << cnt << " ��° ��忡 �����Ͱ� �����մϴ�.";
		cout << endl;
	}
	else {
		cout << " �ش��ϴ� �����Ͱ� �������� �ʽ��ϴ�."<<endl;
	}
}


int List::search(int data) {
	Node* temp = Head;
	int cnt = 0;
	int check = 0;

	//�˻� 
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

	//������ �ôµ� �����Ͱ� ���� ���
	if (check == 0) {
		printNode(0);
		return 0;
	}

}

void List::remove(int data) {
	///////////////�ش� ��� ã��

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

    //////////////�ش� ��� ����
	if (check == 0) {
		cout << " �ش��ϴ� �����Ͱ� �������� �ʽ��ϴ�.";
	}
	else {
		Node* temp = Head;
		Node* cur = Head;

		if (cnt == count) {   //�� ������ ��带 ������ ��
			for (int i = 0; i < cnt - 1; i++) {
				temp = temp->next;
			}
			temp->next = NULL;
			delete temp->next;
			count--;
		}
		else {				//�߰��� �ִ� ��� ������ �� 
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

