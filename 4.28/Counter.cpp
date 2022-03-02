#include "pch.h"
#include "Counter.h"


CCounter::CCounter():_counter(0)
{
}

bool CCounter::Enter(Guest &guest)
{
	if (_counter >= 10)
	{
		std::cout << "입장 가능인원 초과\n";
		return false;
	}
	if (guest.EntranceOrNot == true)
	{
		++_counter;
	}


	return true;
}

void CCounter::ShowCurrent()
{
	std::cout << "현 입장자 수 " << _counter << std::endl;
}

void CCounter::ShowResult()
{
	std::cout << "총 입장자 수 " << _counter << std::endl;
}


CCounter::~CCounter()
{
}
