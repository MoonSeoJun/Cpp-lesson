#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* link;
	Node* back;
};

class CMyList {
public:
	CMyList() {}
	CMyList(int Num)
	{
		CMyList::Set_max_len(Num);
	}
	~CMyList() {
		cout << "\n";

		Node* nextNode;
		Node* delNode;

		delNode = pHead;

		if (delNode == nullptr)
		{
			return;
		}

		nextNode = pHead->link;

		

		while (delNode)
		{

			cout << delNode->data << "를 삭제했습니다" << endl;

			delete delNode;

			if (nextNode == nullptr) break;

			delNode = nextNode;
			nextNode = nextNode->link;
		}
	}

	void InsertBack(int num);
	void PrintData();
	void Print_menu();
	Node* GetpHead() const
	{
		return this->pHead;
	}
	Node* GetpTail() const
	{
		return this->pTail;
	}
	void SetHead(Node* phead)
	{
		this->pHead = phead;
	}
	void setTail(Node* ptail)
	{
		this->pTail = ptail;
	}
	void Set_max_len(int num)
	{
		Max_len = num;
	}
	int Return_max_len() const 
	{
		return Max_len;
	}
	bool Check_Max()
	{
		if (NumOfNode >= Max_len)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual bool Check_overlap(Node* list, int data) {
		while (list != nullptr) {
			if (list->data == data) {
				return false;
			}
			list = list->link;
		}
		return true;
	}

	static int NumOfNode;
	static int Max_len;

private:
	Node* pHead = nullptr;
	Node* pTail = nullptr;
};