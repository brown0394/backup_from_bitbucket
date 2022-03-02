#pragma once

struct SstudentData
{
	int phoneNumb;
	char name[20];
	int score;
};


class CStundentInfo
{
	SstudentData _stdata;
	FILE* _filePt;
	errno_t _err;
	char _fileName[20];
	char _fileString[256];
	int _dataCount;

public:



	CStundentInfo();

	void WriteFile();
	void AddData();
	void ReadData();
	void SearchData();


	~CStundentInfo();
};

