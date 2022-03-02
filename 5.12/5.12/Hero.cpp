#include "Hero.h"

#include <iostream>
#include <ctime>


Hero::Hero()
{
	SetName("Me");
}

char Hero::RockPaperFunc(char input, char opponentinpt)
{
	if (input == 'r' && opponentinpt == 'c')
	{
		return 'w';
	}
	else if (input == 'p' && opponentinpt == 'r')
	{
		return 'w';
	}
	else if (input == 'c' && opponentinpt == 'p')
	{
		return 'w';
	}
	else if (input == opponentinpt)
	{
		return 'd';
	}
	else
	{
		return 'l';
	}
}

void Hero::RetoreEnergy()
{
	std::cout << "\nRestored energy\n";
	if (_hp < 9)
	{
		_hp = 9;
	}
}

bool Hero::GiveChance()
{
	char input = '\0';
	int random = 0;

	const int max_rand_limit = 1000;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < max_rand_limit; ++i)
	{
		random = (rand() % 2) + 1;
	}

	std::cout << "\n\tYou Lost All Your Energy     Final Chance\n\t     Head(1) or Tail(2)?";
	std::cin >> input;

	switch (random)
	{
		case 1 : 
		{
			if (input == '2')
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if (input == '1')
			{				
				return false;
			}
			break;
		}
	}

	std::cout << "\t    You Won the Life Gamble";
	_hp += 3;
	return true;
}

Hero::~Hero()
{
}
