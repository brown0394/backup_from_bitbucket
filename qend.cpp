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
	printf("���ڸ� (%dȸ) �Է��Ͻÿ� : ", (7 - idxcount));
	cin >> Carr[idxcount];
	++idxcount;
	}

	idxcount = 0;
		while (1)
		{
			if (idxcount == 7)
			{
				printf("\nq�� ���ԵǾ� ���� �ʽ��ϴ�.\n");
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