#pragma once


struct Node
{
	Node* next_node;
	void* data;
};

struct QeueList
{
	Node* first;
	Node* last;
	int node_count;
};

class LinkedQeue
{
	void (*_DataDeleteFunction)(void*);


public:

	QeueList* _listpt;

	LinkedQeue();

	void CreateQeueList(void p_DeleteDataPt(void*));
	Node* Deqeue();
	void Enqeue(Node* p_newnode);
	void DeleteList();
	Node* CreateNode(void* p_data);
	void DeleteNode(Node* &p_node_to_delete);
	void ShowQeueCount();
	~LinkedQeue();
};

