#pragma once

struct TNode
{
	TNode* child;
	TNode* sibling;
	void* data;
};
struct TList
{
	TNode* root;
	int count;
};


class LCRSTree
{
	void (*_DeleteFn)(void*);
	void (*_ShowData)(void*);

public:
	LCRSTree(void(*p_DeleteFn)(void*), void (*p_ShowData)(void*));

	void DeleteTree(TNode* p_root);
	TNode* CreateNode(void* p_data);
	void AddChild(TNode* p_parentnode, TNode* p_newnode);
	void DeleteNode(TNode* p_nodedelete);
	void PrintTree(TNode* node, int depth);
	~LCRSTree();

};

