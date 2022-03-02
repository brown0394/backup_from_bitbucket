#pragma once
#include "Stack.h"

class StackCalculator
{
	char* _string_pt;
	char _numbers[10];
	int _intnumbers[10];
	char _operators[10];
	int _oper_indxcount;
	Stack Stack;
	StackList* List;


	void StringConvert(int length);
	void Calculate(char operand);
	int DataConvertInt();
	void* DynamicData(int para);

public:
	StackCalculator();
	StackCalculator(void Func(void* data));
	void StringInput(const char* string, int stringLength);
	void ShowResult();

	~StackCalculator();
};
