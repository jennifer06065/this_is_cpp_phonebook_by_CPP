#include "MyList.h"
#include <iostream>

using namespace std;

CMyList::CMyList()
	: m_Head(0, 0, 0)
{
}

CMyList::~CMyList()
{

}

void CMyList::ReleaseList()
{

}

CUserData* CMyList::FindNode(const char* pszName)
{
	return NULL;
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	return 0;
}

void CMyList::PrintAll(void)
{

}

int CMyList::RemoveNode(const char* pszName)
{
	return 0;
}