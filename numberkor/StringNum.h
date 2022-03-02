
#pragma once
struct SKorNumb
{
	const char one[3] = "ÀÏ";
	const char two[3] = "ÀÌ";
	const char three[3] = "»ï";
	const char four[3] = "»ç";
	const char five[3] = "¿À";
	const char six[3] = "À°";
	const char seven[3] = "Ä¥";
	const char eight[3] = "ÆÈ";
	const char nine[3] = "±¸";
	const char zero[3] = "¿µ";

	const char ten[3] = "½Ê";
	const char hundred[3] = "¹é";
	const char thousand[3] = "Ãµ";
	const char tenthousd[3] = "¸¸";
	const char hundrdthsd[3] = "½Ê";
	const char million[3] = "¹é";
	const char tenmili[3] = "Ãµ";
	const char hundrdmili[3] = "¾ï";
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

