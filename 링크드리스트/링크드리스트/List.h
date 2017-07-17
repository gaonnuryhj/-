class List
{
	class Node {
	public:
		int data;
		Node* next;
	};

	Node* Head = new Node;
	int count=0;

public:
	List();
	void insert(int data);      //마지막에 삽입
	void insert(int cnt, int data);      //지정해준 순서에 삽입
	void remove(int data);        //해당 데이터를 가진 노드 삭제
	void printNode();            //리스트 출력
	int search(int data);        // 해당 데이터를 가진 노드 검색
	void printNode(int cnt);      // search결과 출력
	~List();
};