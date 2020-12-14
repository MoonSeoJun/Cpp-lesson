#include <iostream>
#include "CMyList.h"

using namespace std;

int CMyList::NumOfNode = 0;
int CMyList::Max_len = 0;

void CMyList::InsertBack(int num)
{
	if (this->Check_Max() == true)
	{
		cout << "\n\t" << "<< �ִ� ���̿� �����߽��ϴ� >> " << "\n" << endl;

		return;
	}

	Node* newNode = new Node();
	Node* nextNode = pHead;

	newNode->data = num;
	newNode->link = nullptr;
	newNode->back = nullptr;

	if (pHead == nullptr)
	{
		pHead = newNode;
		pTail = newNode;
	}
	else
	{
		if (Check_overlap(nextNode, num) == false) {
			cout << "\n\t<< �ߺ��� ���� ������ �� �����ϴ�. >>\n" << endl;

			return;
		}
		newNode->back = pTail;
		pTail->link = newNode;

		pTail = newNode;
	}
	
	NumOfNode++;

}

void CMyList::PrintData()
{
	Node* nextNode;

	nextNode = pHead;

	if (pHead == nullptr)
	{
		cout << "\n\t<< ����� �����Ͱ� �����ϴ� >> \n" << endl;

		return;
	}

	cout << "����Ʈ ������ : " << "[ Head ] " << nextNode->data;

	nextNode = nextNode->link;

	while (nextNode)
	{
		cout << " - " << nextNode->data;

		nextNode = nextNode->link;
	}

	cout << " [ Tail ]" << endl;

	cout << "������ ���� : " << "  [ "  << NumOfNode << " ]" << endl;
}