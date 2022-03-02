#include "pch.h"
#include "StringNum.h"
#include <iostream>


CStringNum::CStringNum() : _numbarray{ 0 },
_count(0), _numbpointarr{ _Sknumb.zero, _Sknumb.one, _Sknumb.two, _Sknumb.three, _Sknumb.four, _Sknumb.five, _Sknumb.six, _Sknumb.seven, _Sknumb.eight, _Sknumb.nine },
_decipointarr{ _Sknumb.ten, _Sknumb.hundred, _Sknumb.thousand, _Sknumb.tenthousd, _Sknumb.hundrdthsd, _Sknumb.million, _Sknumb.tenmili, _Sknumb.hundrdmili },
_showarrpt{ nullptr }
{
}


void CStringNum::NumbCheck(int input)
{
	int numbcount = 1;
	int temp = input;


	while (input != 0)
	{
		++_count;
		numbcount *= 10;
		input /= 10;
	}
	numbcount /= 10;

	for (int i = 0; i < _count; ++i)
	{
		if (i > 0)
		{

			_numbarray[i] = (temp / numbcount) - (temp / (numbcount * 10) * 10);
		}
		else
		{
			_numbarray[i] = temp / numbcount;
		}

		numbcount /= 10;
	}

	Convert();
}

void CStringNum::Convert()
{
	for (int i = 0; i < _count; ++i)
	{
		switch (_numbarray[i])
		{
		case 0:
		{
			_showarrpt[i] = _numbpointarr[0];
			break;
		}
		case 1:
		{
			_showarrpt[i] = _numbpointarr[1];
			break;
		}
		case 2:
		{
			_showarrpt[i] = _numbpointarr[2];
			break;
		}
		case 3:
		{
			_showarrpt[i] = _numbpointarr[3];
			break;
		}
		case 4:
		{
			_showarrpt[i] = _numbpointarr[4];
			break;
		}
		case 5:
		{
			_showarrpt[i] = _numbpointarr[5];
			break;
		}
		case 6:
		{
			_showarrpt[i] = _numbpointarr[6];
			break;
		}
		case 7:
		{
			_showarrpt[i] = _numbpointarr[7];
			break;
		}
		case 8:
		{
			_showarrpt[i] = _numbpointarr[8];
			break;
		}
		case 9:
		{
			_showarrpt[i] = _numbpointarr[9];
			break;
		}
		}
	}

}

void CStringNum::ShowConvert()
{
	for (int i = 0; i < _count; ++i)
	{

		if (_count - 2 - i < 0)
		{
			std::cout << _showarrpt[i];
		}
		else
		{
			if (_showarrpt[i] == _numbpointarr[0])
			{
				while (_showarrpt[i] == _numbpointarr[0])
				{
					++i;
					if (i == _count)
					{
						i -= 1;
						break;
					}
				}
			}
			if (_count - 2 - i < 0)
			{					
					std::cout << _showarrpt[i];			
			}
			else
			{
				std::cout << _showarrpt[i] << _decipointarr[(_count - 2) - i];
			}
		}
	}

}

CStringNum::~CStringNum()
{
}