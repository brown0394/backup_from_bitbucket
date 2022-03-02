#pragma once
class RockPaper
{
protected:
	char _name[100];
	int _hp;
	char _paper;
	char _rock;
	char _scissor;

public:
	RockPaper();
	bool Lose();
	virtual bool RockPaperFunc();
	void SetName(const char para[]);
	virtual void ShowHp();


	~RockPaper();
};

