#include "pch.h"


int main()
{
	int idxcount = 0;
	char Sarr[20] = { 0 };
	cin >> Sarr;



	while (1)
	{
		if (20 == idxcount)
		{
			return 0;
		}
		if (Sarr[idxcount] == '\0')
		{
			return 0;
		}

		printf(" '%c' \n", Sarr[idxcount]);
		++idxcount;
	}
}