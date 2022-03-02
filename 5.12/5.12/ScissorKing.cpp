#include "ScissorKing.h"
#include <iostream>
#include <ctime>



ScissorKing::ScissorKing()
{
	SetName("ScissorKing");
	SetPercentage(25, 50, 25);
	_hp = 12;
}

void ScissorKing::ShowNarrative()
{
	std::cout << '\n';
	std::cout << _name << "approached with Scary Scissor hand\n";

}

ScissorKing::~ScissorKing()
{
}