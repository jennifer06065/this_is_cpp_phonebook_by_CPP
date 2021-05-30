#pragma once

class CMyList;

class CUserInterface
{
public:
	CUserInterface(CMyList &rList);
	~CUserInterface(void);

protected:
	CMyList& m_List;

public:
	void Add(void);
	void Search(void);
	void Remove(void);
	int PrintUI(void);
	int Run(void);
};

