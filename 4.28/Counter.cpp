#include "pch.h"
#include "Counter.h"


CCounter::CCounter():_counter(0)
{
}

bool CCounter::Enter(Guest &guest)
{
	if (_counter >= 10)
	{
		std::cout << "���� �����ο� �ʰ�\n";
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
	std::cout << "�� ������ �� " << _counter << std::endl;
}

void CCounter::ShowResult()
{
	std::cout << "�� ������ �� " << _counter << std::endl;
}


CCounter::~CCounter()
{
}
