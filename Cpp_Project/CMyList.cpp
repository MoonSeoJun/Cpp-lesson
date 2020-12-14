#include <iostream>
#include "CMyList.h"

using namespace std;

int CMyList::NumOfNode = 0;
int CMyList::Max_len = 0;

void CMyList::InsertBack(int num)
{
	if (this->Check_Max() == true)
	{
		cout << "\n\t" << "<< 최대 길이에 도달했습니다 >> " << "\n" << endl;

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
			cout << "\n\t<< 중복된 값은 저장할 수 없습니다. >>\n" << endl;

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
		cout << "\n\t<< 출력할 데이터가 없습니다 >> \n" << endl;

		return;
	}

	cout << "리스트 데이터 : " << "[ Head ] " << nextNode->data;

	nextNode = nextNode->link;

	while (nextNode)
	{
		cout << " - " << nextNode->data;

		nextNode = nextNode->link;
	}

	cout << " [ Tail ]" << endl;

	cout << "데이터 개수 : " << "  [ "  << NumOfNode << " ]" << endl;
}