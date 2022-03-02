#include "pch.h"

struct coord
{
	int x;
	int y;
};

int main()
{
	const int white = 0;
	const int black = 1;	
	int table[19][19] = { 0 };

	for (int i = 0; i < 19; ++i)
	{

		for (int j = 0; j < 19; ++j)
		{
			table[i][j] = white;
		}
	}
	for (int i = 0; i < 19; ++i)
	{

		for (int j = 0; j < 19; ++j)
		{
			printf("%d ", table[i][j]);
		}
		cout << "\n";
	}

	int offval = 0;
	int num_count = 0;
	printf("���� �ٲٱ⸦ ������ Ƚ���� �Է��Ͻÿ� : ");
	cin >> num_count;
	coord* point = new coord[num_count];
	while (1)
	{
		if (offval == num_count)
		{
			break;
		}
		printf("���� �ٲٱ⸦ ������ ���ο� �� ���ο��� �Է��Ͻÿ� : ");
		cin >> point[offval].x >> point[offval].y;

	
		for (int i = 0; i < 19; ++i)
		{
			table[i][point[offval].x-1] = black;
			for (int j = 0; j < 19; ++j)
			{
				table[point[offval].y-1][j] = black;
			}
		}
		++offval;
	}

	for (int i = 0; i < 19; ++i)
	{

		for (int j = 0; j < 19; ++j)
		{
			printf("%d ", table[i][j]);
		}
		cout << "\n";
	}

	delete [] point;
	point = nullptr;
}