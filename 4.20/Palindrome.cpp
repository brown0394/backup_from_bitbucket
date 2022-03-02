#include "pch.h"
#include "Palindrome.h"
#include <iostream>


CPalindrome::CPalindrome() : mid(0)
{
}

bool CPalindrome::CheckString(char* para, int stringlength)
{
	mid = stringlength / 2;
	int check = 1;

	for (int i = 1; i <= mid; ++i)
	{
		if ((*(para + mid - i)) != (*(para + mid + i)))
		{
			check = 0;
			break;
		}

	}


	return check;
}

bool CPalindrome::PalindromeYN(bool para)
{
	if (para == true)
	{
		std::cout << "\n�ش� ������ ȸ���Դϴ�.\n";
	}
	else
	{
		std::cout << "\n�ش� ������ ȸ���� �ƴմϴ�.\n";
	}

	return para;
}

CPalindrome::~CPalindrome()
{
}
