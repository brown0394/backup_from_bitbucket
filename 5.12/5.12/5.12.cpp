#include <iostream>

#include "Hero.h"
#include "Monster.h"'
#include "PaperKing.h"
#include "RockKing.h"
#include "ScissorKing.h"

int main()
{
	Hero Me;
	RockKing RKing;
	ScissorKing SKing;
	PaperKing PKing;
	Monster monster;
	Monster* monster_pt = &monster;
	short int monster_count = 1;

	char input = '\0';
	std::cout << "\n1. Scissor    2. Rock     3. Paper     q. Quit     ";
	bool winorlose = true;
	monster_pt->ShowNarrative();

	while (input != 'q')
	{

		monster_pt->ShowHp();
		Me.ShowHp();

		std::cin >> input;

		switch (input)
		{
		case '1': input = 'c'; break;
		case '2': input = 'r'; break;
		case '3': input = 'p'; break;
		case 'q': std::cout << "Exit\n"; return 0; break;
		}

		input = Me.RockPaperFunc(input, monster_pt->MonRockPaperFunc());
		monster_pt->Attack();

		if (input == 'w')
		{
			std::cout << "Win";
			winorlose = monster_pt->Lose();

			if (winorlose == false)
			{
				std::cout << "\nVictory";
				Me.RetoreEnergy();
				switch (monster_count)
				{
				case 1: monster_pt = &SKing; break;
				case 2: monster_pt = &RKing; break;
				case 3: monster_pt = &PKing; break;
				case 4: input = 'q'; break;
				}
				++monster_count;
			}
		}
		else if (input == 'd')
		{
			std::cout << "Draw";
		}
		else if(input == 'l')
		{
			std::cout << "Lose";
			winorlose = Me.Lose();
			if (winorlose == false)
			{
				if (Me.GiveChance() == false)
				{
					std::cout << "\n\t        You Lost Your Chance\nGame Over";
					break;
				}
			}
		}

	}
}
