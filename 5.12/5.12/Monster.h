#pragma once
#include "RockPaper.h"
class Monster : public RockPaper 
{
protected:
	int _random_val;
	char _rcp;
	int _percent_scissor;
	int _percent_rock;
	int _percent_paper;
public:
	Monster();
	virtual  char MonRockPaperFunc();
	void SetPercentage(int r, int s, int p);
	void ShowHp();
	void Attack();
	virtual void ShowNarrative();

	~Monster();
};

