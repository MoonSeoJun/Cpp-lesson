#include <iostream>
#include "CMyList.h"

using namespace std;


class CMyListEx :public CMyList
{
public:
	CMyListEx() {}
	CMyListEx(int Param) : m_nData(Param){}
	CMyListEx(const CMyListEx& rhs) : m_nData(rhs.m_nData){}
	CMyListEx(const CMyListEx&& rhs) : m_nData(rhs.m_nData){}
	~CMyListEx() {}

	CMyListEx operator+(const CMyListEx& Param)
	{
		CMyListEx result(0);
		result.m_nData = this->Max_len + Param.m_nData;
		return result;
	}

	CMyListEx operator-(const CMyListEx& Param)
	{
		CMyListEx result(0);
		result.m_nData = this->Max_len - Param.m_nData;
		return result;
	}

	int Get_data() const
	{
		return m_nData;
	}

	void InsertFront(int num);

	void DeleteFront();
	void DeleteBack();
	void PrintData_From_Tail();

	bool Check_overlap(Node* list, int data) {
		while (list != nullptr) {
			if (list->data == data) {
				return false;
			}
			list = list->link;
		}
		return true;
	}

private:
	int m_nData = 0;
};