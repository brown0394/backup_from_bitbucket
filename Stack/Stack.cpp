#include "Stack.h"



Stack::Stack(): FunctionDelete(nullptr)
{
}

void Stack::CreateList(StackList*& list, void FDelete(void*))
{
	FunctionDelete = FDelete;
	list = new StackList;
	list->first = nullptr;
	list->top = nullptr;
}


void Stack::Push(Node* newone, StackList* list)
{
	if (list->first == nullptr)
	{
		list->first = newone;
		list->top = newone;
	}
	else
	{
		list->top->next = newone;
		list->top = newone;
	}
}

Node* Stack::CreateNode(void* data_para)
{
	Node* new_node = new Node;
	new_node->next = nullptr;
	new_node->data = data_para;
	return new_node;
}

void Stack::DeleteNode(Node*& node)
{
	FunctionDelete(node->data);
	delete node;
}

Node* Stack::Pop(StackList* list)
{
	Node* node_pop = list->top;
	Node* new_top = list->first;
	if (list->top == list->first)
	{
		list->first = list->top = nullptr;
	}
	else
	{
		while (new_top->next != list->top)
		{
			new_top = new_top->next;
		}
	}
	list->top = new_top;
	list->top->next = nullptr;
		return node_pop;
}

void Stack::DeleteList(StackList*& list)
{
	Node* current = nullptr;
	Node* next = nullptr;

	if (list->first != nullptr)
	{
		Node* current = list->first;
		Node* next = current->next;

		while (current->next != nullptr)
		{
			FunctionDelete(current->data);
			delete current;
			current = next;
			next = current->next;
		}
	}




	delete list;
}

Stack::~Stack()
{
}
