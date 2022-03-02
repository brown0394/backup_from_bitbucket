#include "pch.h"
#include <iostream>

class CCal 
{
	int count;
public:
	CCal();
	~CCal();
	void Mul(int a, int b);
	void GetCount();
};

CCal::CCal()
{
	count = 0;
}

void CCal::Mul(int a, int b)
{
	std::cout << "result : " << a * b << "\n";
	++count;
}


void CCal::GetCount()
{
	std::cout << "calculated " << count << " times\n";
}

CCal::~CCal()
{

}






int main()
{
	CCal calcular;

	int val1, val2;



	while (1)
	{
		std::cout << "Input two numbers to calculate : ";
		std::cin >> val1 >> val2;
		if (0 == val1 && 0 == val2)
		{
			calcular.GetCount();
			std::cout << "exit";
			return 0;
		}

		calcular.Mul(val1, val2);
	}



}
