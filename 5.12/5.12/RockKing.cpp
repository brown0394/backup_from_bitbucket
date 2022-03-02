#include "RockKing.h"
#include <iostream>
#include <ctime>



RockKing::RockKing()
{
	SetName("Rock King");
	SetPercentage(50, 25, 25);
	_hp = 12;
}


void RockKing::ShowNarrative()
{
	std::cout << '\n';
	std::cout << _name << "approached with Heavy Rock on his hand\n";

}

RockKing::~RockKing()
{
}
