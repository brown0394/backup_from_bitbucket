#pragma once
class COddEeven
{
	int _odd[10];
	int _even[10];
	int _oddcount;
	int _evencount;

public:
	COddEeven();
	void CheckEvenOdd(int arr[10]);
	void ShowAll();
	~COddEeven();
};

