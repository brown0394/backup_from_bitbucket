#pragma once


struct Node
{
	Node* prev;
	Node* next;
	void* data;
	int idx;
};
struct List
{
	Node* head;
};

class CLinkedList
{
	int node_total;
public:




	void CreateList(List* & list);//head, list
	void Insert(Node* &node, void* data, List* list);
	Node* Last(List* list);
	void Delete(Node*& node, List* list);
	void DeleteList(List* &list);
	Node* Search(List* list, int para);
	int GetTotal();

	CLinkedList();
	~CLinkedList();
};

