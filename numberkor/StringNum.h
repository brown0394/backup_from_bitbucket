
#pragma once
struct SKorNumb
{
	const char one[3] = "��";
	const char two[3] = "��";
	const char three[3] = "��";
	const char four[3] = "��";
	const char five[3] = "��";
	const char six[3] = "��";
	const char seven[3] = "ĥ";
	const char eight[3] = "��";
	const char nine[3] = "��";
	const char zero[3] = "��";

	const char ten[3] = "��";
	const char hundred[3] = "��";
	const char thousand[3] = "õ";
	const char tenthousd[3] = "��";
	const char hundrdthsd[3] = "��";
	const char million[3] = "��";
	const char tenmili[3] = "õ";
	const char hundrdmili[3] = "��";
};


class CStringNum
{
	SKorNumb _Sknumb;
	int _numbarray[10];
	int _count;
	const char* _numbpointarr[10];
	const char* _decipointarr[8];
	const char* _showarrpt[20];

public:
	CStringNum();

	void Convert();
	void NumbCheck(int input);


	void ShowConvert();

	~CStringNum();
};

