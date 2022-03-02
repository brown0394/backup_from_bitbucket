#include <iostream>

#include "LCRSTree.h"



LCRSTree::LCRSTree(void(*p_DeleteFn)(void*), void (*p_ShowData)(void*))
{
	_DeleteFn = p_DeleteFn;
	_ShowData = p_ShowData;
}

void LCRSTree::DeleteTree(TNode* p_root)
{
	if (p_root->sibling != nullptr)
	{
		DeleteTree(p_root->sibling);
	}
		if (p_root->child != nullptr)
	{
		DeleteTree(p_root->child);
	}

		p_root->sibling = nullptr;
		p_root->child = nullptr;
		DeleteNode(p_root);
}

TNode* LCRSTree::CreateNode(void* p_data)
{
	TNode* newnode = new TNode;

	newnode->child = nullptr;
	newnode->sibling = nullptr;
	newnode->data = p_data;
	return newnode;
}

void LCRSTree::AddChild(TNode* p_parentnode, TNode* p_newnode) 
{
	if (p_parentnode->child == nullptr)
	{
		p_parentnode->child = p_newnode;
	}
	else
	{
		TNode* tempcurr = p_parentnode->child;
		if (tempcurr->sibling == nullptr)
		{
			tempcurr->sibling = p_newnode;
		}
		else
		{
			TNode* tempnext = tempcurr->sibling;
			while (tempnext != nullptr)
			{
				tempcurr = tempnext;
				tempnext = tempcurr->sibling;
			}
			tempcurr->sibling = p_newnode;
		}



	}
}

void LCRSTree::PrintTree(TNode* node, int depth)
{
	for (int i = 0; i < depth; ++i)
	{
		printf("  ");
	}
	_ShowData(node->data);

	if (node->child != nullptr)
	{
		PrintTree(node->child, depth + 1);
	}
	if (node->sibling != nullptr)
	{
		PrintTree(node->sibling, depth);
	}

}

void LCRSTree::DeleteNode(TNode* p_nodedelete)
{
	_DeleteFn(p_nodedelete->data);
	p_nodedelete->data = nullptr;
	delete p_nodedelete;
}

LCRSTree::~LCRSTree()
{


}

