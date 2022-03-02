#include "RockPaper.h"
#include<iostream>


RockPaper::RockPaper() :_name{'\0'}, _hp(9), _paper('p'), _rock('r'), _scissor('c')
{
}

bool RockPaper::RockPaperFunc()
{
	return false;
}

bool RockPaper::Lose()
{
	_hp -= 3;
	if (_hp == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

 void RockPaper::ShowHp()
{
	 std::cout << '\n';
	 std::cout << _name << ' ';
	 for (int i = 0; i < _hp; ++i)
	 {
		 std::cout << "*";
	 }
	 std::cout << '\n';
}

void RockPaper::SetName(const char para[])
{
	strcpy_s(_name, para);
}

RockPaper::~RockPaper()
{
}
