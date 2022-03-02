/*

#include "pch.h"
#include <iostream>
#include "Counter.h"


int main()
{
	CCounter counter;
	bool limitCheck = true;
	int input = 0;
	std::cout << "입장 1   미입장 0\n현 입장자 수 확인 3  종료 4 이상의 수";
	Guest guest;


	while (limitCheck == true)
	{
		std::cin >> input;
		if (input < 2)
		{
			guest.EntranceOrNot = input;
			limitCheck = counter.Enter(guest);
		}
		else if (input == 3)
		{
			counter.ShowCurrent();
		}
		else
			break;
	}


	counter.ShowResult();
}
*/