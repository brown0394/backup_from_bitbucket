#include "/Users/user/source/repos/csc0914/4.27/pch.h"
#include "LinkedList.h"


CLinkedList::CLinkedList() : node_total(0)
{
}

void CLinkedList::CreateList(List* &list)
{
	Node* head = new Node;
	head->next = head;
	head->prev = head;
	head->data = nullptr;
	head->idx = 0;

	list = new List;
	list->head = head;
}

void CLinkedList::Insert(Node* &node, void* data, List* list)
{
	Node* newnode = new Node;

	newnode->data = data;
	newnode->next = node->next;
	newnode->prev = node;

	node->next->prev = newnode;
	node->next = newnode;
	
	if (newnode->prev == list->head)
	{
		newnode->idx = 1;
	}
	else
	{
		newnode->idx = (newnode->prev->idx) + 1;
	}
	Node* curr = newnode->next;
	Node* next = curr->next;
	while (curr != list->head)
	{
		curr->idx = (curr->prev->idx) + 1;
		curr = next;
		next = curr->next;
	}

	++node_total;
}

Node* CLinkedList::Last(List* list) // 순서상 마지막에 해당하는 노드를 불러온다.
{
	Node* last = list->head->prev;
	return last;
}

Node* CLinkedList::Search(List* list, int para) //검색할 idx값
{
	Node* search = list->head->next;
	while (search->idx != para)
	{
		search = search->next;
	}
	return search;
}

int CLinkedList::GetTotal()
{
	return node_total;
}

void CLinkedList::Delete(Node* &node, List* list)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;


	Node* curr = node->next;
	Node* next = curr->next;
	while (curr != list->head)
	{
		curr->idx = (curr->idx) - 1;
		curr = next;
		next = curr->next;
	}

	--node_total;

	delete node;
}

void CLinkedList::DeleteList(List* &list)
{
	Node* current = list->head;
	Node* next = nullptr;
	while (next != list->head)
	{
		next = current->next;
		delete current;
		current = next;
	}
}

CLinkedList::~CLinkedList()
{
}
