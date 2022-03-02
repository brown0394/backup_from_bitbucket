#include "pch.h"
#include "StundentInfo.h"

int main()
{

	CStundentInfo stddata;
	stddata.WriteFile();
	int input = 0;
	while (true)
	{
		printf_s("1. 학생 데이터 추가\n2. 학생 데이터 읽어들이기\n3. 학생 데이터 검색\n4. 종료    ");
		std::cin >> input;


		switch (input)
		{
		case 1:	stddata.AddData(); break;
		case 2:	stddata.ReadData(); break;
		case 3: stddata.SearchData(); break;
		case 4:
			std::cout << "\n종료\n";
			return 0;
		}

	}

}