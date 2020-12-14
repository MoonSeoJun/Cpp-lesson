#include <iostream>
#include "CMyListEx.h"

void CMyListEx::DeleteBack()
{
	Node* pTail = this->GetpTail();

	if (pTail == nullptr)
	{
		cout << "\n\t" << "<< 삭제할 데이터가 없습니다 >>" << "\n" << endl;
		return;
	}

	Node* delNode = pTail;

	Node* backNode = pTail->back;

	this->setTail(backNode);

	backNode->link = nullptr;

	delete delNode;

	CMyList::NumOfNode--;

}

void CMyListEx::DeleteFront()
{
	Node* pHead = this->GetpHead();

	if (pHead == nullptr)
	{
		cout << "\n\t" << "<< 삭제할 데이터가 없습니다 >>" << "\n" << endl;
		return;
	}

	Node* delNode = pHead;

	Node* FrontNode = pHead->link;

	SetHead(FrontNode);

	cout << pHead->data << endl;

	pHead->back = nullptr;

	delete delNode;

	CMyList::NumOfNode--;
}


void CMyListEx::InsertFront(int num)
{
	if (this->Check_Max() == true)
	{
		cout << "\n\t" << "<< 최대 길이에 도달했습니다 >> " << "\n" << endl;

		return;
	}

	Node* pHead = this->GetpHead();

	Node* pTail = this->GetpTail();

	Node* newNode = new Node();

	newNode->data = num;

	newNode->link = nullptr;

	newNode->back = nullptr;

	Node* nextNode = pHead;
	if (pHead == nullptr) // 리스트가 비엇을때... 처음 노드
	{

		SetHead(newNode);
//		pHead = newNode;

		setTail(newNode);
//		pTail = newNode;
	}
	else
	{
		if (Check_overlap(nextNode, num) == false) {
			cout << "\n\t<< 중복된 값은 저장할 수 없습니다. >>\n" << endl;

			return;
		}
		newNode->link = pHead;

		pHead->back = newNode;

		SetHead(newNode);

	}

	CMyList::NumOfNode++;
}

void CMyListEx::PrintData_From_Tail()
{
	Node* backNode = this->GetpTail();

	if (backNode == nullptr)
	{
		cout << "\t\n" << "<< 출력할 데이터가 없습니다 >> " << "\n" << endl;

		return;
	}

	cout << "리스트 데이터 : [ Tail ] " << backNode->data;

	backNode = backNode->back;

	while (backNode)
	{

		cout << " - " << backNode->data;

		backNode = backNode->back;
	}

	cout << " [ Head ]" << endl;

	cout << "데이터 개수 : " << "  [ "  << CMyList::NumOfNode << " ]" << endl;
}

void Plus_LEN_TO_MAX(int Param)
{
	CMyListEx Add(CMyList::Max_len + Param);

	CMyList::Max_len = Add.Get_data();

	cout << "\n\t" << "최대 길이가 " << CMyList::Max_len << "으로 바뀌었습니다" << "\n" << endl;
}

void Minus_LEN_TO_MAX(int Param)
{
	CMyListEx Minus(CMyList::Max_len - Param);

	CMyList::Max_len = Minus.Get_data();

	if (CMyList::Max_len <= 0)
	{
		cout << "\n\t" << "<< 길이가 0 또는 0보다 작습니다 >>" << "\n" << endl;
		cout << "\n\t" << "<< 길이를 1로 재설정합니다 >> " << "\n" << endl;

		CMyList::Max_len = 1;

		return;
	}

	cout << "\n\t" << "최대 길이가 " << CMyList::Max_len << "으로 바뀌었습니다" << "\n" << endl;
}


void CMyList::Print_menu()
{
	cout << "--------------------------" << endl;
	cout << "\t" << "CMyList Menu" << endl;
	cout << "\t" << "1. 삽입 Head" << endl; // Complete
	cout << "\t" << "2. 삽입 Tail" << endl; // Complete
	cout << "\t" << "3. 삭제 Head" << endl; // Complete
	cout << "\t" << "4. 삭제 Tail" << endl;
	cout << "\t" << "5. 출력 Head -> Tail" << endl; // Complete
	cout << "\t" << "6. 출력 Tail -> Head" << endl; // Complete
	cout << "\t" << "7. 길이 설정 +" << endl;
	cout << "\t" << "8. 길이 설정 -" << endl;
	cout << "\t" << "0. 종료" << endl;
	cout << "--------------------------" << endl;
}

int main()
{
	int select;
	int insert_node;
	int Set_Max;
	int Edit_Max_len;


	CMyListEx* myListex = new CMyListEx;
	while (1) {
		cout << "최대 길이를 설정하세요 >> ";
		cin >> Set_Max;
		if (Set_Max <= 0)
		{
			cout << "\n\t" << "<< 0보다 큰 정수를 입력해주세요 >>" << "\n" << endl;
		}
		else 
		{
			CMyList Max_Set(Set_Max);
			break;
		}
	}
	while (1)
	{
		myListex->Print_menu();
		cout << "메뉴를 선택하세요 >> ";
		cin >> select;
		switch (select)
		{
			// Head에 삽입
		case 1:
			cout << "삽입할 노드를 입력하세요 >> ";
			cin >> insert_node;

			myListex->InsertFront(insert_node);

			myListex->PrintData();

			break;

			// Tail에 삽입
		case 2:
			cout << "삽입할 노드를 입력하세요 >> ";
			cin >> insert_node;

			myListex->InsertBack(insert_node);

			myListex->PrintData();

			break;

		case 3:

			myListex->DeleteFront();

			myListex->PrintData();

			break;

		case 4:
			myListex->DeleteBack();

			myListex->PrintData();

			break;

		case 5:
			myListex->PrintData();

			break;

		case 6:
			myListex->PrintData_From_Tail();

			break;

		case 7:
			cout << "추가하고 싶은 만큼의 길이를 입력하세요 >> ";
			cin >> Edit_Max_len;

			if (Edit_Max_len < 0)
			{
				cout << "\t\n" << "<< 정수를 입력하세요! >>" << "\n" << endl;

				break;
			}

			Plus_LEN_TO_MAX(Edit_Max_len);
			
			break;

		case 8:
			cout << "삭제하고 싶은 만큼의 길이를 입력하세요 >>";
			cin >> Edit_Max_len;

			if (Edit_Max_len < 0)
			{
				cout << "\t\n" << "<< 정수를 입력하세요! >>" << "\n" << endl;

				break;
			}

			Minus_LEN_TO_MAX(Edit_Max_len);

			break;

		case 0:
			cout << "종료하였습니다!" << endl;
			delete myListex;
			return 0;

		default:
			break;
		}
	}
}