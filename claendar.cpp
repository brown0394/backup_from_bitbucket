#include "pch.h"


int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	printf("년, 월, 일 순으로 입력 : ");
	cin >> year >> month >> day;


	printf("\n%04d. %02d. %02d\n", year, month, day);
}