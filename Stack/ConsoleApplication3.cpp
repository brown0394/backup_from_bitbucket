#include <iostream>
#include "Stack.h"

void* DynamicData(int para);
void DeleteIntData(void* data);
void ShowData(void* data);
int main()
{
	Stack stack;
	StackList* stacklist;
	Node* popped_node = nullptr;
	int val = 0;
	int* val_pt = &val;

	stack.CreateList(stacklist, DeleteIntData);
	stack.Push(stack.CreateNode(DynamicData(12)), stacklist);
	stack.Push(stack.CreateNode(DynamicData(22)), stacklist);
	popped_node = stack.Pop(stacklist);
	ShowData(popped_node->data);
	stack.DeleteNode(popped_node);
	popped_node = stack.Pop(stacklist);
	ShowData(popped_node->data);
	stack.DeleteNode(popped_node);

	stack.DeleteList(stacklist);
}

void* DynamicData(int para)
{
	int* data = new int;
	*data = para;
	return (void*)data;
}
void DeleteIntData(void* data)
{
	delete (int*)data;
}
void ShowData(void* data)
{
	int* data_to_show = (int*)data;
	std::cout << *data_to_show << '\n';
}