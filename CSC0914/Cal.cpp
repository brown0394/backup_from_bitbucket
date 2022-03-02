#include "pch.h"
#include <iostream>
#include "Calc.h"


int main()
{
	CCalc calcular;
	int endcount = 0;

	while (1)
	{
		endcount = calcular.Input();
		if (endcount == 78)
			break;
		calcular.Show();
	}


	
}
