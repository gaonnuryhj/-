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
	void insert(int data);      //�������� ����
	void insert(int cnt, int data);      //�������� ������ ����
	void remove(int data);        //�ش� �����͸� ���� ��� ����
	void printNode();            //����Ʈ ���
	int search(int data);        // �ش� �����͸� ���� ��� �˻�
	void printNode(int cnt);      // search��� ���
	~List();
};