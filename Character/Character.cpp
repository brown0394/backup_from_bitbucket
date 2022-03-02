#include "Character.h"
#include <iostream>


CCharacter::CCharacter() :_name{ "\0" }, _hp(100), _killed_enemies(0), _weapontype{ {"\0"}, {10} },
_level(1), _exp(0), _exp_to_levelup(50), _char_attack_point(10)
{
}

CCharacter::CCharacter(char charact_name[], char para[], int damge)
{
	strcpy_s(_weapontype.name, para);
	strcpy_s(_name, charact_name);
}

void CCharacter::Attack(CCharacter& target)
{
	std::cout << "\n" << _weapontype.name << "�� �̿��Ͽ� " << GetAttackPoint() << "�������� �־���\n";
	bool dead_or_not = false;
	dead_or_not = target.ReceiveDamage(GetAttackPoint());
	if (dead_or_not == true)
	{
		std::cout << "\n" << target._name << "�� óġ�ߴ�\n";
		Kill(target);	
	}
}

bool CCharacter::ReceiveDamage(int damage)
{
	if (_hp - damage < 0)
	{
		_hp = 0;
		return true;
	}
	else
	{
		_hp = _hp - damage;
		return false;
	}
}

void CCharacter::Kill(CCharacter& target)
{
	int temp = (3 * target._level) + (1 + (target._exp / 10));
	_killed_enemies++;
	_exp += temp;
	std::cout << "\n" << temp << "����ġ ȹ��\n";
}

int CCharacter::GetAttackPoint()
{
	return _char_attack_point + _weapontype.attackPoint;
}

void CCharacter::LevelCheck()
{
	if (_exp >= _exp_to_levelup)
	{
		_exp -= _exp_to_levelup;
		_exp_to_levelup *= 2;
		++_level;
		_char_attack_point += (_level + (1 * (_level / 2)));
		_hp += (_level * 2);
		std::cout << "\nLevel Up\n";
	}

}

CCharacter::~CCharacter()
{
}
