#include "PaperKing.h"
#include <iostream>
#include <ctime>


PaperKing::PaperKing()
{
	SetName("Paper King");
	SetPercentage(25, 25, 50);
	_hp = 12;
}

void PaperKing::ShowNarrative()
{
	std::cout << '\n';
	std::cout << _name << "approached with Big Giant Hand\n";

}

PaperKing::~PaperKing()
{
}
