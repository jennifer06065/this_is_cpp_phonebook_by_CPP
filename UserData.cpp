#define _CRT_SECURE_NO_WARNINGS
#include "UserData.h"
#include <iostream>
#include <cstring>

using namespace std;

int CUserData::nUserDataCount = 0;

CUserData::CUserData(const char* paramName, const char* paramPhone, CUserData* paramNext)
{
	if (paramName == NULL)
		szName[0] = '\0';
	else strcpy(this->szName, paramName);
	
	if (paramPhone == NULL)
		szPhone[0] = '\0';
	else strcpy(this->szPhone, paramPhone);
	this->pNext = paramNext;
	nUserDataCount++;
}

CUserData::~CUserData(void)
{
	nUserDataCount--;
}