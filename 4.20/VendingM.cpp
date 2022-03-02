#include "pch.h"
#include "VendingM.h"
#include <iostream>


CVendingM::CVendingM() : _SgoodList{ {"�Ҷ��Ҷ�", 800, 2},{"���̴�", 500, 5}, {"õ�����", 400, 3}}
{

}

void CVendingM::InputCash(int para)
{
	_cash = para;
}

void CVendingM::ShowAvailList()
{
	std::cout << "\n�� ���� �ݾ� : " << _cash << "\n";

	if (_cash > 800)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("\n%s  %d��  ���� ���� : %d\n", _SgoodList[i]._Itemname, _SgoodList[i]._value, _SgoodList[i]._amount);
		}
	}
	else if (_cash > 500 && _cash < 800)
	{
		for (int i = 1; i < 3; ++i)
		{
			printf("\n%s  %d��  ���� ���� : %d\n", _SgoodList[i]._Itemname, _SgoodList[i]._value, _SgoodList[i]._amount);
		}
	}
	else if (_cash > 400 && _cash < 500)
	{
			printf("\n%s  %d��  ���� ���� : %d\n", _SgoodList[Cider]._Itemname, _SgoodList[Cider]._value, _SgoodList[Cider]._amount);
	}
	else if(_cash < 400)
	{
		printf("\n���� ������ ��ǰ�� �����ϴ�.\n");
	}

}

void CVendingM::Purchase(int input)
{
	switch (input)
	{
		case 1:
		{
			if (_SgoodList[Sottuck]._amount == 0)
			{
				std::cout << "\n�ش� ��ǰ�� ǰ���Դϴ�.\n";
			}
			_cash -= 800;
			_SgoodList[Sottuck]._amount -= 1;
			std::cout << "\n"<<_SgoodList[Sottuck]._Itemname << " ����\n";
			break;
		}
		case 2:
		{
			if (_SgoodList[Cider]._amount == 0)
			{
				std::cout << "\n�ش� ��ǰ�� ǰ���Դϴ�.\n";
			}
			_cash -= 500;
			_SgoodList[Cider]._amount -= 1;
			std::cout << "\n"<<_SgoodList[Cider]._Itemname << " ����\n";
			break;
		}
		case 3:
		{
			if (_SgoodList[Chunha]._amount == 0)
			{
				std::cout << "\n�ش� ��ǰ�� ǰ���Դϴ�.\n";
			}
			_cash -= 400;
			_SgoodList[Chunha]._amount -= 1;
			std::cout << "\n"<<_SgoodList[Chunha]._Itemname << " ����\n";
			break;
		}
		default:
		{
			std::cout << "\n�߸��� �Է�\n";
			break;
		}
	}

}

int CVendingM::ReturnChange()
{
	return _cash;
}





CVendingM::~CVendingM()
{
}
