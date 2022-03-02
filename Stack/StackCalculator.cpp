#include <iostream>

#include "StackCalculator.h"



StackCalculator::StackCalculator() :  _numbers{ '\0' }, _operators{'\0'}, _oper_indxcount(0)
{
	
}
StackCalculator::StackCalculator(void Func(void* data))
{
	Stack.CreateList(List, Func);
}


void StackCalculator::StringInput(const char* string, int stringLength)
{
	int count = 0;
	int idxcount = 0;

	--stringLength;
	for (; 0 <= stringLength; --stringLength)
	{


		if (*(string + stringLength + 1) == ')' && *(string + stringLength) != ' ')//(*(string + count - 1) == '(' && *(string + count) != ' ')
		{
			StringConvert(idxcount);
			idxcount = 0;
			_numbers[idxcount] = *(string + stringLength);
			++idxcount;
			--stringLength;


			if (*(string + stringLength) == ' ')
			{
				StringConvert(idxcount);
				idxcount = 0;
				--stringLength;
			}
		}
		else if (*(string + stringLength) == '(' && *(string + stringLength + 1) != ' ' )//(*(string + count) == ')' && *(string + count - 1) != ' ')
		{
			StringConvert(idxcount);
			idxcount = 0;
			_numbers[idxcount] = *(string + stringLength);
			++idxcount;
			--stringLength;
			if (stringLength >= 0)
			{
				StringConvert(idxcount);
				idxcount = 0;
				--stringLength;
			}
		}
		else if (*(string + stringLength) == ' ')
		{
			StringConvert(idxcount);
			idxcount = 0;
			--stringLength;
		}

		if (stringLength >= 0)
		{
			_numbers[idxcount] = *(string + stringLength);
			++idxcount;
		}

	}

	StringConvert(idxcount);
	/*
	while (*(string + count) != '\0')
	{
		if (*(string + count - 1) == '(' && *(string + count ) != ' ')
		{
			StringConvert(idxcount);
			idxcount = 0;
			_numbers[idxcount] = *(string + count);
			++idxcount;
			++count;


			if (*(string + count ) == ' ')
			{
				StringConvert(idxcount);
				idxcount = 0;
				++count;
			}
		}
		else if (*(string + count) == ')' && *(string + count - 1) != ' ')
		{
			StringConvert(idxcount);
			idxcount = 0;
			_numbers[idxcount] = *(string + count);
			++idxcount;
			++count;
			if (*(string + count) != '\0')
			{
				StringConvert(idxcount);
				idxcount = 0;
				++count;
			}
		}
		else if (*(string + count) == ' ')
		{
			StringConvert(idxcount);
			idxcount = 0;
			++count;
		}

		if (*(string + count) != '\0')
		{
			_numbers[idxcount] = *(string + count);
			++idxcount;
			++count;
		}

	}

	StringConvert(idxcount);*/
}

void StackCalculator::StringConvert(int length)
{
	if (_numbers[0] == '(')
	{
		--_oper_indxcount;
			while (_operators[_oper_indxcount] != ')')
			{
				Calculate(_operators[_oper_indxcount]);
				_operators[_oper_indxcount ] = '\0';
				--_oper_indxcount;

			}
			_operators[_oper_indxcount] = '\0';
			if (_oper_indxcount > 0 && (_operators[_oper_indxcount - 1] == '*' || _operators[_oper_indxcount - 1] == '/'))
			{
				--_oper_indxcount;
				Calculate(_operators[_oper_indxcount]);
				_operators[_oper_indxcount] = '\0';
			}


	}
	else if (_numbers[0] == '+' || _numbers[0] == '-' || _numbers[0] == '*' || _numbers[0] == '/' || _numbers[0] == ')')
	{
		_operators[_oper_indxcount] = _numbers[0];
		++_oper_indxcount;
	}
	else
	{
		for (int i = 0; i < length; ++i)
		{
			switch (_numbers[i])
			{
				case '1': _intnumbers[i] = 1; break;
				case '2': _intnumbers[i] = 2; break;
				case '3': _intnumbers[i] = 3; break;
				case '4': _intnumbers[i] = 4; break;
				case '5': _intnumbers[i] = 5; break;
				case '6': _intnumbers[i] = 6; break;
				case '7': _intnumbers[i] = 7; break;
				case '8': _intnumbers[i] = 8; break;
				case '9': _intnumbers[i] = 9; break;
				case '0': _intnumbers[i] = 0; break;
			}
		}
		switch (length)
		{
			case 1: _intnumbers[0] *= 1; break;
			case 2: {_intnumbers[1] *= 10; _intnumbers[0] += _intnumbers[1]; break; }
			case 3: {_intnumbers[2] *= 100;  _intnumbers[1] *= 10; _intnumbers[0] += _intnumbers[1] + _intnumbers[2]; break; }
			case 4: {_intnumbers[3] *= 1000;  _intnumbers[2] *= 100; _intnumbers[1] *= 10; _intnumbers[0] += _intnumbers[1] + _intnumbers[2] + _intnumbers[3]; break; }
		}
		Stack.Push(Stack.CreateNode(DynamicData(_intnumbers[0])), List);
		if ((_operators[_oper_indxcount - 1] == '*' || _operators[_oper_indxcount - 1] == '/') && _operators[_oper_indxcount ] != '(')
		{
			--_oper_indxcount;
			Calculate(_operators[_oper_indxcount]);
			_operators[_oper_indxcount] = '\0';
		}
	}



}


void StackCalculator::Calculate(char operand)
{
	int val1 = 0;
	int val2 = 0;


	val1 = DataConvertInt();
	val2 = DataConvertInt();
	switch (operand)
	{
	case '*':
	{
		val2 *= val1;
		Stack.Push(Stack.CreateNode(DynamicData(val2)), List);
		break;
	}
	case '/':
	{
		val1 /= val2;
		Stack.Push(Stack.CreateNode(DynamicData(val1)), List);
		break;
	}
	case '+':
	{
		val2 += val1;
		Stack.Push(Stack.CreateNode(DynamicData(val2)), List);
		break;
	}
	case '-':
	{
		val1 -= val2;
		Stack.Push(Stack.CreateNode(DynamicData(val1)), List);
		break;
	}
	}

}

void StackCalculator::ShowResult()
{
	while (_operators[_oper_indxcount] != '\0')
	{
		++_oper_indxcount;
	}
	--_oper_indxcount;

	while (_oper_indxcount > -1)
	{
		Calculate(_operators[_oper_indxcount]);
		--_oper_indxcount;
	}

	int val1 = DataConvertInt();
	std::cout << "°á°ú °ª : " <<val1 << std::endl;
}

int StackCalculator::DataConvertInt()
{
	Node* popped_node = nullptr;
	int val1 = 0;
	int* dat = nullptr;

	popped_node = Stack.Pop(List);
	dat = (int*)popped_node->data;
	val1 = *dat;
	Stack.DeleteNode(popped_node);

	return val1;
}

void* StackCalculator::DynamicData(int para)
{
	int* data = new int;
	*data = para;
	return (void*)data;
}



StackCalculator::~StackCalculator()
{
	Stack.DeleteList(List);
}
