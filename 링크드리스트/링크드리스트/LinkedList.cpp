#include<iostream>
#include<string>
#include"List.h"

using namespace std;


/*
��ũ�帮��Ʈ�� ���� : �������� �޸𸮸� ����� �� �ִ�.  �迭�� ������ �غ� & �迭���� ����,������ ������.
			   ���� : search �ϴ� �� �־ best�� �ƴϴ�. ���� �ڷ��� �ּҸ� �����ϴ� �޸� ������ �߰������� ����Ѵ�. 

�迭�� ���� : ����,������ �־ overhead�� ũ��.

����,���� : O(n)
search : O(nlogn)

����/���� ���� : �� ��忡�� �ٸ� ���� ���� ���� ( ����� )
���� ���� : search �� ���ѷ����� ���� �� �ִ�. -> �˻��� ������ ��带 �δ� ���� ����

*/



void main() {
	List test;

	test.insert(10);
	test.insert(20);
	test.insert(30);
	test.printNode();
	
	
	test.insert(2, 15);
	test.printNode();
	test.search(20);
	test.remove(20);
	test.printNode();
	test.search(20);
	
}




