#include "pch.h"
#include "StundentInfo.h"

int main()
{

	CStundentInfo stddata;
	stddata.WriteFile();
	int input = 0;
	while (true)
	{
		printf_s("1. �л� ������ �߰�\n2. �л� ������ �о���̱�\n3. �л� ������ �˻�\n4. ����    ");
		std::cin >> input;


		switch (input)
		{
		case 1:	stddata.AddData(); break;
		case 2:	stddata.ReadData(); break;
		case 3: stddata.SearchData(); break;
		case 4:
			std::cout << "\n����\n";
			return 0;
		}

	}

}