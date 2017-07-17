#include<iostream>
#include<string>
#include"List.h"

using namespace std;



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




