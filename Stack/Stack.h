#pragma once

struct Node
{
	void* data;
	Node* next;
};

struct StackList
{
	Node* first;
	Node* top;
};

class Stack
{
	void (*FunctionDelete)(void* );

public:
	Stack();
	void CreateList(StackList*& list, void FDelete(void*));
	void Push(Node* newone, StackList* list);
	Node* Pop(StackList* list);
	Node* CreateNode(void* data_para);
	void DeleteNode(Node*& node);
	void DeleteList(StackList*& list);

	~Stack();
};

