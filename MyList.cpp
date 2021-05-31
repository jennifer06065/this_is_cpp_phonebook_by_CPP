#include "MyList.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#define pszFileName "cpp phone book"
using namespace std;

CMyList::CMyList()
	: m_Head(0, 0, 0)
{
	FILE* fp = NULL;
	fopen_s(&fp, pszFileName, "rb");

	if (fp == NULL) return;

	ReleaseList();

	char name[32], phone[32];

	while (1) {
		fgets(name, 32, fp);
		if (feof(fp)) break;
		name[strlen(name) - 1] = '\0';
		fgets(phone, 32, fp);
		phone[strlen(phone) - 1] = '\0';
		AddNewNode(name, phone);
	}

	fclose(fp);
}

CMyList::~CMyList()
{
	FILE* fp = NULL;
	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL) {
		cout << "ERROR : 리스트 파일을 쓰기 모드로 열지 못했습니다." << endl;
		return;
	}

	CUserData* temp = m_Head.pNext;
	while (temp != NULL) {
		fprintf(fp, "%s\n%s\n", temp->szName, temp->szPhone);
		temp = temp->pNext;
	}
	fclose(fp);
}

void CMyList::ReleaseList()
{
	CUserData* temp, *delete_node;
	temp = m_Head.pNext;
	while (temp != NULL) {
		delete_node = temp;
		temp = temp->pNext;
		delete delete_node;
	}
}

CUserData* CMyList::FindNode(const char* pszName)
{
	CUserData* temp;
	temp = m_Head.pNext;
	while (temp != NULL) {
		if (strcmp(temp->szName, pszName) == 0)
			return temp;
		temp = temp->pNext;
	}
	return NULL;
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	CUserData* tmp = m_Head.pNext;
	while (tmp != NULL) {
		if (strcmp(pszName, tmp->szName) == 0)
			return 1;
		tmp = tmp->pNext;
	}

	CUserData* new_node = new CUserData(pszName, pszPhone, 0);
	new_node->pNext = m_Head.pNext;
	m_Head.pNext = new_node;
	return 0;
}

void CMyList::PrintAll(void)
{
	CUserData* temp;
	temp = m_Head.pNext;
	while (temp != NULL) {
		cout << "Name : " << temp->szName << ", Phone number : " << temp->szPhone << endl;
		temp = temp->pNext;
	}
	_getch();
}

int CMyList::RemoveNode(const char* pszName)
{
	CUserData* prev, * delete_node;
	prev = &m_Head;
	while (prev->pNext != NULL) {
		if (strcmp(prev->pNext->szName, pszName) == 0) {
			delete_node = prev->pNext;
			prev->pNext = delete_node->pNext;
			delete delete_node;
			return 1;
		}
		prev = prev->pNext;
	}
	return 0;
}