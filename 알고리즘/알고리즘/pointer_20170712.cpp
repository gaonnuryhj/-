#include<iostream>
#include<string>
using namespace std;   
# define size_Y 10
# define size_X 3


//////////�迭�� ������////////
/*

������ :  �޸� �ּҰ��� ��� 
�迭 : ���� �޸𸮰� ����
������ : ����ó�� ���� ���� ó�� ���� , ���� �޸� �ּҰ� �̵��� �� �ִ�.

ptr = �ּҰ�
*ptr = �ּҰ� ����Ű�� ��

*ptr++, *(ptr++), --ptr, *(ptr++) : �ּҰ� + 1
*ptr++ -> ���� ����! ��� �� ���� ����ȴ�!

(*ptr)++ : �ּҰ� ����Ű�� �� + 1


call by value : value���� �Ķ���ͷ�
call by reference : �ּҰ��� �Ķ���ͷ�

func(int i , int *j) => i : value , j : reference

ȣ�� func( i, &j )

*/


void main() {
	string name;
	int i;
	cout << "�����K";
	cin >> i;
	getline(cin, name, '\n');

	////////2���� ���� �Ҵ�////////
	int** arr = new int*[size_Y];
	for (int i = 0; i < size_Y; i++) {
		arr[i] = new int[size_X];
	}

	for (int i = 0; i < size_Y; i++) {
		delete[] arr[i];
	}
	delete[] arr[i];

	

}