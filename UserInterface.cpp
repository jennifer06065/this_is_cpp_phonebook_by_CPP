#include "UserInterface.h"
#include "MyList.h"
#include <iostream>
#include <conio.h>
using namespace std;

CUserInterface::CUserInterface(CMyList& rList)
	:m_List(rList)
{
}

CUserInterface::~CUserInterface()
{
}

void CUserInterface::Add(void)
{
	char name[32];
	char phone[32];
	cout << "New name : ";
	cin >> name;
	cout << "New phone number : ";
	cin >> phone;
	int error = m_List.AddNewNode(name, phone);
	if (error == 1)
		cout << name << " already in." << endl;
}
void CUserInterface::Search(void)
{
	char name[32];
	cout << "name : ";
	cin >> name;
	CUserData* tmp = m_List.FindNode(name);
	if (tmp == NULL) {
		cout << "No such name in." << endl;
	}
	else {
		cout << "Name : " << tmp->GetName() << endl;
		cout << "Phone number : " << tmp->GetPhone() << endl;
	}
	_getch();
}
void CUserInterface::Remove(void)
{
	char name[32];
	cout << "name : ";
	cin >> name;
	if (m_List.RemoveNode(name) == 0)
		cout << "No such name." << endl;
	_getch();
}
int CUserInterface::PrintUI(void)
{
	int nInput = 0;

	system("cls");
	cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit" << endl;

	cin >> nInput;
	return nInput;
}
int CUserInterface::Run(void)
{
	int nMenu = 0;

	//메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu)
		{
		case 1: //Add
			Add();
			break;
		case 2: //Search
			Search();
			break;
		case 3: //Print all
			m_List.PrintAll();
			break;
		case 4: //Remove
			Remove();
			break;
		}
	}

	return nMenu;
}