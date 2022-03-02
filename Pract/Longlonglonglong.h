#pragma once
class CLonglonglonglong
{
	char input[256];
	int stackarr1[10];
	int stackarr2[10];
	int result[10];
	int arr1_length;
	int arr2_length;
	char operator_input;
public:
	CLonglonglonglong();
	int Converter(char para);
	void Input_val();
	void ArrConverter(int arr[10], char input[256], int& length);
	void ArrPlus();
	void ArrMinus();
	void ShowResult();
	~CLonglonglonglong();
};

