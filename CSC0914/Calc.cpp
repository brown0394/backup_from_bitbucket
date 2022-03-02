#include "pch.h"
#include <iostream>
#include "Calc.h"


CCalc::CCalc() : m_count(0) , m_input1(0), m_input2(0), m_opinput(0)
{
}

int CCalc::Input()
{
	
	std::cout << "Input two numbers to Calculate : ";
	std::cin >> m_input1 >> m_opinput >> m_input2;
	if (0 == m_input1 && '0' == m_opinput && 0 == m_input2)
	{
		return End();
	}
	if(m_opinput == '*')
	{
	m_result = Mul(m_input1, m_input2);
	}
	else if (m_opinput == '/')
	{
		m_result = Div(m_input1, m_input2);
	}
	else if (m_opinput == '+')
	{
		m_result = Plus(m_input1, m_input2);
	}
	else
	{
		m_result = Min(m_input1, m_input2);
	}

	return NULL;
}

void CCalc::Show()
{
		std::cout << "result : " << m_result << "\n";
}

int CCalc::Mul(int a, int b)
{
	++m_count;
	return a * b;
}

int CCalc::Div(int a, int b)
{
	++m_count;
	return a / b;
}

int CCalc::Plus(int a, int b)
{
	++m_count;
	return a + b;
}

int CCalc::Min(int a, int b)
{
	++m_count;
	return a - b;
}

int CCalc::End()
{
	GetCount();
	std::cout << "exit" << "\n";
	return 78;
}

void CCalc::GetCount()
{
	std::cout << "calculated " << m_count << " times\n";
}


CCalc::~CCalc()
{
}
