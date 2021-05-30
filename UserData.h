#pragma once


/// <summary>
/// USERDATA 구조체와 동일한 기능
/// </summary>
class CUserData
{
	friend class CMyList;

public:

	CUserData(const char* paramName, const char* paramPhone, CUserData* paramNext);
	~CUserData(void);

	const char* GetName(void) const { return szName; }
	const char* GetPhone(void) const { return szPhone; }
	const CUserData* GetNext(void) const { return pNext; }

	static int GetUserDataCounter(void) { return nUserDataCount; }

private:
	char szName[32];
	char szPhone[32];

	CUserData* pNext;

	static int nUserDataCount;
};

