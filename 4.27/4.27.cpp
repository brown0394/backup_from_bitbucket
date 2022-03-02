/*

#include "pch.h"
#include <iostream>

int main()
{

	int result = 0;
	int input = 0;
	std::cin >> input;

	FILE* filePt;
	errno_t err;
	err = fopen_s(&filePt, "tesxt.txt", "wt");
	if (filePt == NULL)
	{
		return -1;
	}
	else 
	{
		fprintf(filePt, "---- %d * n ----\n", input);

		for (int i = 2; i < 10; ++i)
		{
			result = input * i;
			fprintf(filePt, "%d * %d = %d\n", input, i, result);
		}

	
	}


	fclose(filePt);
	filePt = nullptr;
}
*/