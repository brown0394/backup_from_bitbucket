#include "pch.h"
#include <iostream>


using namespace std;


void SpaceEraser(char* space, char* maze)
{
	int count = 0;

	for (int i = 0; i < 200; ++i)
	{
		if (*(space + i) == ' ' || *(space+i) == '\0')
		{
			++i;
		}
			*(maze + count) = *(space + i);
			++count;
	}


}


int main()
{
	enum maze{empty = 0, wall, food};
	char maze[10][10] = { 0 };
	char temp[10][20] = {'\0'};


	for (int i = 0; i < 10; ++i)
	{
		cin.getline(temp[i], 20);

	}
	SpaceEraser(&temp[0][0], &maze[0][0]);


	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c ", maze[i][j]);
		}
		cout << "\n";
	}
	int x = 1;
	int y = 1;

	while (true)
	{
		if (maze[y][x] == '2')
		{
			break;
		}
		maze[y][x] = '9';
		if ('1' == maze[y + 1][x] && '1' == maze[y][x + 1])
		{
			break;
		}
		if (true && (maze[y][x+1] == '1'))
		{
			maze[y][x] = '9';
			--x;
			++y;
		}
		++x;

	}
	cout << "\n\n";
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c ", maze[i][j]);
		}
		cout << "\n";
	}
}