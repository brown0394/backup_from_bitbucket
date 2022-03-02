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
		std::cout << "\n해당 구문은 회문입니다.\n";
	}
	else
	{
		std::cout << "\n해당 구문은 회문이 아닙니다.\n";
	}

	return para;
}

CPalindrome::~CPalindrome()
{
}
