#pragma once
#include "RockPaper.h"
class Hero : public RockPaper
{
public:
	Hero();
	char RockPaperFunc(char input, char opponentinpt);
	bool GiveChance();
	void RetoreEnergy();
	~Hero();
};

