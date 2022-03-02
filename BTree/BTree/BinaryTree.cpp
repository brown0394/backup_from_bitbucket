#include <iostream>


#include "BinaryTree.h"


BinaryTree::BinaryTree(void(*p_Deleter)(void*), void(*p_Printer)(void*))
{
	DeleteFn = p_Deleter;
	PrintData = p_Printer;
}






BTNode*  BinaryTree::CreateNode(void* p_data)
{
	BTNode* newnode = new BTNode;


	newnode->leftchild = nullptr;
	newnode->rightchild = nullptr;

	newnode->data = p_data;

	return newnode;
}


void BinaryTree::DeleteNode(BTNode* p_node_delete)
{
	DeleteFn(p_node_delete->data);

	delete p_node_delete;
	p_node_delete->leftchild = nullptr;
	p_node_delete->rightchild = nullptr;
}

void BinaryTree::PreorderPrint(BTNode* Node)
{
	if (Node == nullptr)
	{
		return;
	}
	printf(" ");
	PrintData(Node->data);

	PreorderPrint(Node->leftchild);
	PreorderPrint(Node->rightchild);
}

void BinaryTree::InorderPrint(BTNode* Node)
{
	if (Node == nullptr)
	{
		return;
	}
	


	InorderPrint(Node->leftchild);
	printf(" ");
	PrintData(Node->data);
	InorderPrint(Node->rightchild);
}

void BinaryTree::PostorderPrint(BTNode* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	PostorderPrint(Node->leftchild);
	PostorderPrint(Node->rightchild);

	printf(" ");
	PrintData(Node->data);
}

void BinaryTree::DestroyTree(BTNode* p_root)
{
	if (p_root == nullptr)
	{
		return;
	}

	DeleteNode(p_root->leftchild);
	DeleteNode(p_root->rightchild);
	DeleteNode(p_root);

}