/*
	< 퀵 정렬 >
		: 임의의 Pivot을 잡고 맨 왼쪽과 맨 오른쪽에서부터 pivot값과 비교하여 왼쪽은 pivot보다 큰 값을 만났을 경우 stop하고 오른쪽은 pivot보다 작은 경우 stop한다 . 
		  양쪽 모두 멈췄을 때 양 쪽의 인덱스의 차이가 -1이상 일 경우 ( 서로 교차되지 않는 경우 ) 양쪽 값을 바꿔준후 계속하여 진행하다 인덱스가 교차되는 순간 그 자리에 pivot을 넣는다.
		  pivot을 기준으로 반으로 나누어 위의 과정을 반복하여 정렬한다. 
		< 장점 >
			- 이 정렬의 경우, 최소값이나 최대값을 pivot으로 정하는 최악의 경우 O(n^2)의 시간 복잡도를 가지게 되어 Pivot을 어떤 값으로 하느냐가 중요하다. 
			pivot을 랜덤하게 정할 경우 정렬 과정에서 한번이라도 해당 영역에서 최소,최대값이 아닌 수가 pivot으로 정해지는 경우 O(N log N)의 시간복잡도를 가지게 되므로 최악의 경우를 가지게 되는 경우를 최소화할 수 있다.
		    - in place 정렬이다. 
		< 단점 >
		    - 재귀로 호출 할 경우 시간이 오래 걸릴 수 있다.
			- Stable 하지 않다. 

	< 병합 정렬 >
	     : 배열을 2로 나누어 더 이상 쪼개질 수 없을 때까지 나누어 준 후 2개씩 비교하며 합쳐준다. ( Divide and Conqure )
		 < 장점 >
			- O( N log N )의 빠른 시간 복잡도를 가진다. 
			- Stable 하다. 
		 < 단점 >
			- 추가적인 메모리( 배열의 크기만큼 )가 많이 들기 때문에 많은 수를 정렬해야하는 큰 시스템에서는 잘 사용하지 않는다. 

	< 기수 정렬 >
		 : 제일 작은 자릿수의 값들을 기준으로 Queue를 이용하여 정렬한 후 자릿수를 한자리씩 앞으로 옮겨 Queue를 이용하여 정렬해준다. 
		 < 장점 >
			- O( Kn )
			- 같은 수일 경우 순서가 바뀌지 않는다. ( stable 하다. )

		 < 단점 >
			- 동일한 길이를 가지는 숫자나 문자열이여야한다.  ( 키가 특정한 형태를 지녀야 한다. )
			- 추가 메모리 공간이 필요하다.
		< 예시 >
			- 학번, 주민등록번호 등

	< 힙 정렬 >
		   Heap : 이진 트리로서 맨아래층을 제외하고는 완전히 채워져있고 맨 아래층은 왼쪽부터 채워지는 있는 트리 구조를 가지고 있다. 
			      최소힙 ( 각 노드는 자신의 자식의 값보다 작다. )
				  최대힙 ( 각 노드는 자신의 자식의 값보다 크다. )
		  
		  < 장점 >
			 - O(N log N)의 빠른 시간 복잡도를 가진다. 
			    -> 퀵 정렬의 경우 최악의 경우 n^2의 시간복잡도를 가지는 것에 비해 O(N log N)이 보장되어 있지만
				   실제 코드로써 비교해보면 퀵소트가 빠르게 동작하는 데 이는 원리 상 주변의 원소들과 교환이 잦은
				   퀵소트의 캐시적중률이 높기 때문에 교환 속도에서 이득을 보기 때문으로 알려져 있다.
			 - in place 정렬이다. ( 추가 메모리 필요 x )
			
		  < 단점 >
			 - Stable하지 않다. 

< 정렬 알고리즘 비교 >
			http://wonjayk.tistory.com/225
			http://tctt.tistory.com/47

*/


//////////////////////////////////////힙정렬//////////////////////////////////////////////////


#include <iostream>
#include <cmath>
using namespace std;
int num;

int* Max_heapify(int* heap,int size) {
	int t = size;
	int height = 0;
	while (t>1) {
		t = t / 2;
		height++;
	}

	int temp = 0;
	if (height == 1) {
		if (heap[2] > heap[3] && heap[1] < heap[2]) {
			temp = heap[2];
			heap[2] = heap[1];
			heap[1] = temp;
		}
		if (heap[2] < heap[3] && heap[1] < heap[3]) {
			temp = heap[3];
			heap[3] = heap[1];
			heap[1] = temp;
		}
	
	}

	else {
		height--;
		while (height >= 0) {
			for (int i = pow(2, height); i < pow(2, height + 1); i++) {
				if (heap[i] < heap[i * 2] && i * 2 <= num) {
					temp = heap[i * 2];
					heap[i * 2] = heap[i];
					heap[i] = temp;
				}
				if (heap[i] < heap[i * 2 + 1] && (i * 2 + 1) <= num) {
					temp = heap[i * 2 + 1];
					heap[i * 2 + 1] = heap[i];
					heap[i] = temp;
				}
			}
			height--;
		}
	}
	
	
	return heap;
}
void Heap_Sort(int* heap) {
	int temp = num;
	int replace = -1;
	while (temp > 0) {
		replace = heap[temp];
		heap[temp] = heap[1];
		heap[1] = replace;
		cout << heap[temp] << " ";
		heap[temp] = -1;
		temp--;
		Max_heapify(heap,temp);
	}
}

void main() {

	//cin >> num;
	//int temp = num;

	//while (temp % 2 == 1 || temp % 2 == 0) {
	//	temp = temp / 2;
	//	height++;
	//}
	//int* heap = new int[num + 1];
	//for (int i = 1; i < num + 1; i++) {
	//	cin >> heap[i];
	//}
	int heap[10] ={ 0,5, 89, 1, 6, 34,65 ,7, 3, 90 };
	num = 9;

	
	Max_heapify(heap,num);
	Heap_Sort(heap);

}
