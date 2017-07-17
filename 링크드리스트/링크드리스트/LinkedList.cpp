#include<iostream>
#include<string>
#include"List.h"

using namespace std;


/*
링크드리스트의 장점 : 동적으로 메모리를 사용할 수 있다.  배열의 단점을 극복 & 배열보다 삽입,삭제가 빠르다.
			   단점 : search 하는 데 있어서 best는 아니다. 다음 자료의 주소를 저장하는 메모리 공간을 추가적으로 사용한다. 

배열의 단점 : 삽입,삭제에 있어서 overhead가 크다.

삽입,삭제 : O(n)
search : O(nlogn)

원형/이중 장점 : 한 노드에서 다른 노드로 접근 가능 ( 양방향 )
원형 단점 : search 시 무한루프에 빠질 수 있다. -> 검색을 끝내는 노드를 두는 것이 좋다

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




