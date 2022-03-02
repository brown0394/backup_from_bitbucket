#pragma once


struct SGoodList
{
	char _Itemname[20];
	int _value;
	int _amount;
};

class CVendingM
{
	int _cash;

	SGoodList _SgoodList[3];

	enum { Sottuck, Cider, Chunha};
public:
	CVendingM();
	void InputCash(int para);
	void ShowAvailList();
	void Purchase(int input);
	int ReturnChange();

	~CVendingM();
};

