#include <iostream>

#include "LinkedQeue.h"

void DataDelete(void* p_data);
void* DataConvert(int para);
void ShowData(void* p_data);

int main()
{
	LinkedQeue LQ;
	LQ.CreateQeueList(DataDelete);
	LQ.Enqeue(LQ.CreateNode(DataConvert(35)));
	LQ.Enqeue(LQ.CreateNode(DataConvert(20)));
	LQ.Enqeue(LQ.CreateNode(DataConvert(15)));

	Node* temp = LQ.Deqeue();
	try
	{
		ShowData(temp->data);
		LQ.DeleteNode(temp);
		temp = LQ.Deqeue();
		ShowData(temp->data);
		LQ.DeleteNode(temp);
		temp = LQ.Deqeue();
		ShowData(temp->data);
		LQ.DeleteNode(temp);
		temp = LQ.Deqeue();
		ShowData(temp->data);
		LQ.DeleteNode(temp);

	}

	catch (const char* ex)
	{
		std::cout << "\nerror occured : " << ex << "\n";

	}

}


void DataDelete(void* p_data)
{
	delete (int*)p_data;
}

void* DataConvert(int para)
{
	int* data = new int;
	*data = para;
	void* ndata = data;
	return ndata;
}

void ShowData(void* p_data)
{
		int* data_to_show = (int*)p_data;
		std::cout << '\n' <<  *data_to_show;
}