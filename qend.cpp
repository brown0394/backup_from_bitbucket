#include "pch.h"

int main()
{
	int idxcount = 0;
	char Carr[7] = {0};

	while(1)
	{
		if (idxcount == 7)
		{
			break;
		}
	printf("문자를 (%d회) 입력하시오 : ", (7 - idxcount));
	cin >> Carr[idxcount];
	++idxcount;
	}

	idxcount = 0;
		while (1)
		{
			if (idxcount == 7)
			{
				printf("\nq가 포함되어 있지 않습니다.\n");
				return 0;
			}
			printf("%c ", Carr[idxcount]);
			if ('q' == Carr[idxcount])
			{
				return 0;
			}
			++idxcount;
		}
}