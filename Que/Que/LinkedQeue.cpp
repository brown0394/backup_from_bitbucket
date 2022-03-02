#include "LinkedQeue.h"
#include <iostream>


LinkedQeue::LinkedQeue() : _DataDeleteFunction(nullptr), _listpt(nullptr)
{
}

void LinkedQeue::CreateQeueList(void p_DeleteDataPt(void*))
{
	_listpt = new QeueList;
	_listpt->first = nullptr;
	_listpt->last = nullptr;
	_listpt->node_count = 0;

	_DataDeleteFunction = p_DeleteDataPt;
}

void LinkedQeue::Enqeue(Node* p_newnode)
{
	if (_listpt->first == nullptr)
	{
		_listpt->first = p_newnode;
		_listpt->last = p_newnode;
		_listpt->node_count += 1;
	}
	else
	{
		_listpt->last->next_node = p_newnode;
		_listpt->last = p_newnode;
		_listpt->node_count += 1;
	}
}

Node* LinkedQeue::Deqeue()
{
	if (_listpt->node_count == 0)
	{
		throw("Nothing Left in Qeue, Data Error");
	}

	Node* temp = _listpt->first;
	if (_listpt->first->next_node != nullptr)
	{
		_listpt->first = _listpt->first->next_node;
	}
	else
	{
		_listpt->first = nullptr;
	}

	_listpt->node_count -= 1;
	return temp;
}


void LinkedQeue::DeleteList()
{
	if (_listpt->first != nullptr)
	{
		Node* current = _listpt->first;
		Node* next = current->next_node;
		for (int i = 0; i < _listpt->node_count; ++i)
		{
			_DataDeleteFunction(current->data);
			delete current;
			current = next;

			if (current->next_node != nullptr)
			{
				next = current->next_node;
			}
	
		}
	}

	delete _listpt;
}

Node* LinkedQeue::CreateNode(void* p_data)
{
	Node* newnode = new Node;

	newnode->data = p_data;
	newnode->next_node = nullptr;

	return newnode;
}

void LinkedQeue::DeleteNode(Node* &p_node_to_delete)
{
	_DataDeleteFunction(p_node_to_delete->data);
	delete p_node_to_delete;
}

void LinkedQeue::ShowQeueCount()
{
	std::cout << _listpt->node_count;
}

LinkedQeue::~LinkedQeue()
{
	DeleteList();

}