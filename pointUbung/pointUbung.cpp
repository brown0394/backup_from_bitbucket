#include <iostream>
#include "pch.h"

using namespace std;

#define INPUT_SIZE 10
void InputData(int* temp, int* even, int* odd, int* evenindex, int* oddindex);
void OutputData(int* even, int* odd, int* evenindex, int* oddindex);
void inint(int temp[10]);
void inininnt(int* temp);

int main()
{
	int temp[INPUT_SIZE] = { 0 };

	int even[INPUT_SIZE] = { 0 };
	int odd[INPUT_SIZE] = { 0 };
	
	int evenindex = 0;
	int oddindex = 0;

	InputData(temp, even, odd, &evenindex, &oddindex);
	OutputData(even, odd, &evenindex, &oddindex);


	inint(temp);
	for (int i = 0; i < INPUT_SIZE; ++i)
	{
	cout <<temp[i];
	}
}

void InputData(int* temp, int* even, int* odd, int* evenindex, int* oddindex)
{
	for (int i = 0; i < INPUT_SIZE; ++i)
	{
		cin >> *(temp + i);
		if (*(temp + i) % 2 == 0)
		{
			even[*evenindex] = *(temp + i);
			*evenindex += 1;
		}
		else if (*(temp + i) % 2 != 0)
		{
			odd[*oddindex] = *(temp + i);
			*oddindex += 1;
		}
	}
}

void OutputData(int* even, int* odd, int* evenindex, int* oddindex)
{
	cout << "\n짝수 : ";
	for (int i = 0; i < *evenindex; ++i)
	{
		cout << *(even + i) << ' ';
	}
	cout << "\n";
	cout << "\n홀수 : ";
	for (int i = 0; i < *oddindex; ++i)
	{
		cout << *(odd + i) << ' ';
	}
	cout << "\n";
}

void inint(int temp[10])
{
	for (int i = 0; i < INPUT_SIZE; ++i)
	{
		temp[i] = 10;
	}
}

void inininnt(int* temp)
{
	for (int i = 0; i < INPUT_SIZE; ++i)
	{
		temp[i] = 10;
	}
}