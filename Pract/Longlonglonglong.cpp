#include "pch.h"
#include "Longlonglonglong.h"
#include <iostream>

CLonglonglonglong::CLonglonglonglong() : input(" "), stackarr1{ 0 }, stackarr2{ 0 }, result{0}, arr1_length(0), arr2_length(0)
{

}

void CLonglonglonglong::Input_val()
{
	printf("How to use\ninput number to operate : n1(enter)\ninput operator : (+, -)\ninput number to operate : n2\n");
	std::cin >> input;
	ArrConverter(stackarr1, input, arr1_length);
	std::cin >> operator_input;
	std::cin >> input;
	ArrConverter(stackarr2, input, arr2_length);

	switch (operator_input)
	{
	case '+': ArrPlus();
		break;
	case '-': ArrMinus();
		break;
	default: std::cout << "\nwrong input\n";

	}
}


int CLonglonglonglong::Converter(char para)
{
	int temp = (int)para;
	for (int i = 0; i < 10; ++i)
	{
		if (temp == 48 + i)
		{
			temp = i;
		}
	}
	return temp;
}

void CLonglonglonglong::ArrConverter(int arr[10], char input[256], int& length)
{
	int temp[3] = {0};
	int tempcount = 0;
	int figure_amount_check = 0;

	for (int j = 0; j < 256; ++j)
	{
		if (input[j] != '\0')
		{
			++figure_amount_check;
		}
		else
		{
			break;
		}
	}
	length = figure_amount_check;
	int idx_limit_count = 0;
	if (figure_amount_check > 30)
	{
		figure_amount_check = 30;
		std::cout << "\ntoo many inputs. error occured. result would be wrong\n";
	}

	for (int i = figure_amount_check - 1; i >= 0; --i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (input[i] == (48 + j))
			{
				temp[tempcount] = Converter(input[i]);
				++tempcount;
				break;
			}

		}

		if (tempcount == 3)
		{
				arr[(9 - idx_limit_count)] = (temp[0]) + (temp[1] * 10) + (temp[2] * 100);
			++idx_limit_count;
			tempcount = 0;

		}
	}

	if (3 > tempcount && 0 < tempcount)
	{	
	int rest = figure_amount_check % 3;
	if (rest == 2)
	    arr[9 - idx_limit_count] = (temp[0]) + (temp[1]*10);
	else
		arr[9 - idx_limit_count] = (temp[0]);

	}

}

void CLonglonglonglong::ArrPlus()
{
		for(int i = 9; i >= 0; --i)
		{
			result[i] += (stackarr1[i] + stackarr2[i]);
			if ((result[i] / 1000) > 0)
			{
				if ((i - 1) < 0)
				{
					std::cout << "\nerror\n";
					break;
				}
				result[i - 1] += (result[i] / 1000);
				result[i] -= (result[i - 1] * 1000);

			}

		}	
}

void CLonglonglonglong::ArrMinus()
{
	int length = arr1_length >= arr2_length ? arr1_length : arr2_length;
	int idxcount = 0;
	int minuspoint = 0;

	if ((length % 3) == 0)
	{
		idxcount = (length / 3) - 1;
	}
	else
	{
		idxcount = length / 3;
	}

	if (arr1_length > arr2_length || stackarr1[9-idxcount] > stackarr2[9 - idxcount])
	{
		for (int i = 9; i >= 9 - idxcount; --i)
		{
			if (i == 9 - idxcount)
			{
				result[i] += stackarr1[i] - stackarr2[i];
			}
			else
			{

				if ((stackarr1[i] - stackarr2[i]) < 0 && stackarr1[i] > 0)
				{
					result[i] = stackarr2[i] - stackarr1[i];
					if (result[i] < 100 && result[i] > 10)
					{
						result[i] += 900;
					}
					else if (result[i] < 10)
					{
						result[i] += 990;
					}
					if ((i - 1) < 0)
					{
						std::cout << "\nerror\n";
						break;
					}
					stackarr2 [i - 1] += 1;
				}
				else if ((stackarr1[i] - stackarr2[i]) < 0 && stackarr1[i] == 0)
				{
					stackarr1[i] = 1000;
					result[i] = stackarr1[i] - stackarr2[i];
					if ((i - 1) < 0)
					{
						std::cout << "\nerror\n";
						break;
					}
					stackarr2[i - 1] += 1;
				}

				else
				{
					result[i] += stackarr1[i] - stackarr2[i];
				}
			}
		}
	}

	else
	{
		for (int i = 9; i >= 9 - idxcount; --i)
		{
			if (i == 9 - idxcount)
			{
				result[i] += stackarr2[i] - stackarr1[i];
				result[i] = result[i] * -1;
			}
			else
			{

				if ((stackarr2[i] - stackarr1[i]) < 0 && stackarr1[2] > 0)
				{
					result[i] = stackarr1[i] - stackarr2[i];
					if (result[i] < 100 && result[i] > 10)
					{
						result[i] += 900;
					}
					else if (result[i] < 10)
					{
						result[i] += 990;
					}
					if ((i - 1) < 0)
					{
						std::cout << "\nerror\n";
						break;
					}
					stackarr1[i - 1] += 1;
				}
				else if ((stackarr2[i] - stackarr1[i]) < 0 && stackarr2[i] == 0)
				{
					stackarr2[i] = 1000;
					result[i] = stackarr2[i] - stackarr1[i];
					if ((i - 1) < 0)
					{
						std::cout << "\nerror\n";
						break;
					}
					stackarr1[i - 1] += 1;
				}

				else
				{
					result[i] += stackarr2[i] - stackarr1[i];
				}
			}
		}
	}

}

void CLonglonglonglong::ShowResult()
{
	std::cout << "\nresult : ";
	char zero = '0';
	int count = 0;
	for (count = 0; count < 10; ++count)
	{
		if (result[count] == 0)
		{
			while (result[count] == 0)
			{
				++count;
				if (count == 9)
					break;
			}
		}
		std::cout << result[count];
		++count;
		break;
	}
	for ( ; count < 10; ++count)
	{
		if (result[count] == 0)
		{
			std::cout << zero << zero << zero;
		}
		else
		{
			if (result[count] < 100)
			{
				std::cout << zero << result[count];
			}
			else if(result[count] < 10)
			{
				std::cout << zero << zero << result[count];
			}
			else
			{	
		std::cout << result[count];
			}
		}
	}
	std::cout << "\n";
}

CLonglonglonglong::~CLonglonglonglong()
{
}
