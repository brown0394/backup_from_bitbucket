#pragma once


struct Guest
{
	bool EntranceOrNot;
};

class CCounter
{
	int _counter;




public:
	CCounter();
	bool Enter(Guest &guest);
	void ShowCurrent();
	void ShowResult();
	~CCounter();
};

