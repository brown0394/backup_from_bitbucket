#include "pch.h"
#include <iostream>
#include "OddEeven.h"
#include "Palindrome.h"
#include "VendingM.h"

int main()
{
	/*
	int arr[10] = { 0 };
	for (int i = 0; i < 10; ++i)
	{
		std::cin >> arr[i];
	}


	COddEeven Coddeven;
	Coddeven.CheckEvenOdd(arr);
	Coddeven.ShowAll();
	*/

	/*
	CPalindrome Cpcheck;
	char string[100] = { 0 };
	bool isPalindromeCheck = 0;


	while (isPalindromeCheck != true)
	{
	std::cin >> string;
	isPalindromeCheck = Cpcheck.PalindromeYN(Cpcheck.CheckString(string, strlen(string)));
	}

	*/


	/*
	CVendingM Machine;
	bool offswitch = 1;
	int input = 0;
	std::cout << "\nPlease input cash\n";
	std::cin >> input;
	Machine.InputCash(input);

	while (offswitch)
	{
		Machine.ShowAvailList();

		std::cout << "\n\n1. 구매\n2. 잔돈반환  ";
		std::cin >> input;

		switch (input)
		{
			case 1:
			{
				std::cout << "\n1. 소떡소떡\n2. 사이다\n3. 천하장사 ";
				std::cin >> input;
				Machine.Purchase(input);
				break;
			}
			case 2:
			{
				input = Machine.ReturnChange();
				std::cout << "\n반환된 잔돈 : " << input << "\n";
				offswitch = false;
			}
		}
	}
	*/

}
