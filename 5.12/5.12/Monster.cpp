#include "Monster.h"
#include <iostream>
#include <ctime>



Monster::Monster():_random_val(0), _rcp('\0'), _percent_paper(35), _percent_scissor(30),
_percent_rock(35)
{
	SetName("Monster");
}

char Monster::MonRockPaperFunc()
{
	const int max_rand_limit = 1000;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < max_rand_limit; ++i)
	{
		_random_val = (rand() % 100) + 1;
	}


	if (_random_val <= _percent_rock)
	{
		_rcp = _rock;
	}
	else if (_random_val <= _percent_scissor + _percent_rock && _random_val > _percent_rock)
	{
		_rcp = _scissor;
	}
	else if (_random_val <= _percent_paper + _percent_scissor + _percent_rock && _random_val > _percent_scissor + _percent_rock)
	{
		_rcp = _paper;
	}

	return _rcp;
}

void Monster::SetPercentage(int r, int s, int p)
{
	_percent_rock = r;
	_percent_scissor = s;
	_percent_paper = p;
}

void Monster::Attack()
{
	char roscipap[20] = "\0";
	if (_rcp == _rock)
	{
		strcpy_s(roscipap, "Rock");
	}
	else if (_rcp == _scissor)
	{
		strcpy_s(roscipap, "Scissor");
	}
	else if (_rcp == _paper)
	{
		strcpy_s(roscipap, "Paper");
	}



	std::cout << _name << "  attacked with " << roscipap << std::endl;
}

void Monster::ShowHp()
{
	std::cout << '\n';
	std::cout <<"\t\t\t\t"<< _name << ' ';
	for (int i = 0; i < _hp; ++i)
	{
		std::cout << "*";
	}
	std::cout << '\n';

}

void Monster::ShowNarrative()
{
	std::cout << '\n';
	std::cout << _name << "approached with angry face\n";

}

Monster::~Monster()
{
	
}
