#include "pch.h"
#include "StundentInfo.h"


CStundentInfo::CStundentInfo() : _filePt(nullptr), _fileName{ 0 }, _err(NULL), _fileString{0}, _dataCount(0)
{
}

void CStundentInfo::WriteFile()
{
	std::cout << "input file name : ";
	std::cin >> _fileName;
	_err = fopen_s(&_filePt, _fileName, "wt");
	fclose(_filePt);

}

void CStundentInfo::AddData()
{

	_err = fopen_s(&_filePt,_fileName , "at");


	std::cout << "학생 정보 입력 -   전화번호 4자리  이름  성적 순 : ";
	std::cin >> _stdata.phoneNumb >> _stdata.name >> _stdata.score;

	fprintf(_filePt, "%d %s %d \n", _stdata.phoneNumb, _stdata.name, _stdata.score);
	fclose(_filePt);
	_dataCount++;
}

void CStundentInfo::ReadData()
{
	_err = fopen_s(&_filePt, _fileName, "rt");
	for (int i = 0; i < _dataCount; ++i)
	{
		fgets(_fileString, sizeof(_fileString), _filePt);
		std::cout << _fileString;

	}

	fclose(_filePt);
}

void CStundentInfo::SearchData()
{
	int j = 0;
	bool compare = 0;

	std::cout << "찾고자 하는 학생의 이름 입력";
	std::cin >> _stdata.name;

	_err = fopen_s(&_filePt, _fileName, "rt");
	for (int i = 0; i < _dataCount; ++i)
	{

		fgets(_fileString, sizeof(_fileString), _filePt);
		while (1)
		{
			if (_fileString[5 + j] == _stdata.name[j])
			{
				compare = true;
			}
			else
			{
				compare = false;
			}
				++j;
				if (_fileString[5 + j] == ' ')
				{
					break;
				}
		}
		

		if (true == compare)
		{
			std::cout << _fileString;
			break;
		}
		j = 0;
	}

	fclose(_filePt);
}

CStundentInfo::~CStundentInfo()
{
}
