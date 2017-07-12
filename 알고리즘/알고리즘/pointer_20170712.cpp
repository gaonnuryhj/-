#include<iostream>
#include<string>
using namespace std;   
# define size_Y 10
# define size_X 3


//////////배열과 포인터////////
/*

공통점 :  메모리 주소값을 사용 
배열 : 시작 메모리가 고정
포인터 : 변수처럼 직접 연산 처리 가능 , 시작 메모리 주소가 이동될 수 있다.

ptr = 주소값
*ptr = 주소가 가리키는 값

*ptr++, *(ptr++), --ptr, *(ptr++) : 주소값 + 1
*ptr++ -> 후위 연산! 출력 후 값이 변경된다!

(*ptr)++ : 주소가 가리키는 값 + 1


call by value : value값을 파라미터로
call by reference : 주소값을 파라미터로

func(int i , int *j) => i : value , j : reference

호출 func( i, &j )

*/


void main() {
	string name;
	int i;
	cout << "하하핳";
	cin >> i;
	getline(cin, name, '\n');

	////////2차원 동적 할당////////
	int** arr = new int*[size_Y];
	for (int i = 0; i < size_Y; i++) {
		arr[i] = new int[size_X];
	}

	for (int i = 0; i < size_Y; i++) {
		delete[] arr[i];
	}
	delete[] arr[i];

	

}