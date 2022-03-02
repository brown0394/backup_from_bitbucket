#pragma once
class CCalc
{

	int m_input1;
	int m_input2;
	char m_opinput;
	int m_count;
	int m_result;

public:
	CCalc();
	int Input();
	int Mul(int a, int b);
	int Div(int a, int b);
	int Plus(int a, int b);
	int Min(int a, int b);
	void GetCount();
	void Show();
	int End();
	~CCalc();
};

