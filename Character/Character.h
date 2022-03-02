#pragma once

struct Weapon
{
	char name[100];
	int attackPoint;
};

class CCharacter
{
	char _name[100];
	int _hp;
	int _killed_enemies;
	int _level;
	long _exp;
	int _char_attack_point;
	long _exp_to_levelup;
	Weapon _weapontype;

public:
	CCharacter();
	CCharacter(char charact_name[], char para[], int damge);
	void Attack( CCharacter &target);
	bool ReceiveDamage(int damage);
	void Kill(CCharacter& target);
	int GetAttackPoint();
	void LevelCheck();
	~CCharacter();
};

