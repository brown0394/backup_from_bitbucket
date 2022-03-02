#include "pch.h"
#include "Coord.h"
#include <Windows.h>

CCoord::CCoord():_xCoord(0), _yCoord(0), _input(' ')
{
}

void CCoord::SetPosition(int x, int y)
{
	_xCoord = x;
	_yCoord = y;
	GoToXY(_xCoord, _yCoord);
}

void CCoord::Move(int x, int y)
{
	GoToXY(_xCoord, _yCoord);

	for (int i = _xCoord; i <= x; ++i)
	{
		_xCoord = i;
		for (int j = _yCoord; j <= y; ++j)
		{
			_yCoord = j;
			GoToXY(_xCoord, _yCoord);
			Update(100000000);
			if (_xCoord != x || _yCoord != y)
				GoToTrace(_xCoord, _yCoord);
		}
	}
}

void CCoord::GoToTrace(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ' ' << std::endl;
}


void CCoord::GoToXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << '*' << std::endl;
}

void CCoord::Show()
{
	std::cout << "\n" << _xCoord << ' ' << _yCoord << std::endl;
}

void CCoord::Update(int thick)
{
	int count = 0;

	while (count != thick)
	{
		++count;
	}
}

void CCoord::KeyboardInput()
{
	char q = '0';
	GoToXY(_xCoord, _yCoord);
	while (q != 'q')
	{
		std::cin >> _input;
		switch (_input)
		{
			case 'w':
			{
				GoToTrace(_xCoord, _yCoord);
				_yCoord -= 1;
				GoToXY(_xCoord, _yCoord);
				break;
			}
			case's':
			{
				GoToTrace(_xCoord, _yCoord);
				_yCoord += 1;
				GoToXY(_xCoord, _yCoord);
				break;
			}
			case'a':
			{
				GoToTrace(_xCoord, _yCoord);
				_xCoord -= 1;
				GoToXY(_xCoord, _yCoord);
				break;
			}
			case'd':
			{
				GoToTrace(_xCoord, _yCoord);
				_xCoord += 1;
				GoToXY(_xCoord, _yCoord);
				break;
			}
			case'q':
				q = _input;
				break;
		}

	}

}

CCoord::~CCoord()
{
}
