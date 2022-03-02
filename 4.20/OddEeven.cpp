#include "pch.h"
#include "OddEeven.h"
#include <iostream>


COddEeven::COddEeven() : _odd{0}, _even{0}, _oddcount(0), _evencount(0)
{

}



void COddEeven::CheckEvenOdd(int arr[10])
{
	for (int i = 0; i < 10; ++i)
	{

		if (arr[i] % 2 == 0)
		{
			_even[_evencount] = arr[i];
			++_evencount;
		}
		else
		{
			_odd[_oddcount] = arr[i];
			++_oddcount;
		}
	}
}

void COddEeven::ShowAll()
{
	std::cout << "\n";
	for (int i = 0; i < _oddcount; ++i)
	{
		std::cout << _odd[i] << ' ';
	}
	std::cout << "\n";
	for (int i = 0; i < _evencount; ++i)
	{
		std::cout << _even[i] << ' ';
	}
}

COddEeven::~COddEeven()
{

}
