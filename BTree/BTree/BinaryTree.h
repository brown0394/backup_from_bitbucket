#pragma once




struct BTNode
{
	BTNode* leftchild;
	BTNode* rightchild;

	void* data;
};


class BinaryTree
{
private:
	void (*DeleteFn)(void*);
	void (*PrintData)(void*);


public:
	BinaryTree(void(*p_Deleter)(void*), void(*p_Printer)(void*));
	BTNode* CreateNode(void* p_data);
	void DeleteNode(BTNode* p_node_delete);
	void PreorderPrint(BTNode* Node);
	void InorderPrint(BTNode* Node);
	void PostorderPrint(BTNode* Node);

	void DestroyTree(BTNode* p_root);
};

