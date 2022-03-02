#include <iostream>

#include "BinaryTree.h"

void DeleteData(void* p_data);
void PrintData(void* p_data);
void* DataConvert(char para);


int main()
{
	BinaryTree BTree(DeleteData, PrintData);

	BTNode* root = BTree.CreateNode(DataConvert('A'));

	BTNode* B = BTree.CreateNode(DataConvert('B'));
	BTNode* C = BTree.CreateNode(DataConvert('C'));
	BTNode* D = BTree.CreateNode(DataConvert('D'));
	BTNode* E = BTree.CreateNode(DataConvert('E'));
	BTNode* F = BTree.CreateNode(DataConvert('F'));
	BTNode* G = BTree.CreateNode(DataConvert('G'));

	root->leftchild = B;
	root->rightchild = C;
	B->leftchild = D;
	B->rightchild = E;
	C->leftchild = F;
	C->rightchild = G;

	BTree.PreorderPrint(root);
	printf("\n");
	BTree.InorderPrint(root);
	printf("\n");
	BTree.PostorderPrint(root);

}

void DeleteData(void* p_data)
{
	delete (char*)p_data;
}


void PrintData(void* p_data)
{
	char* print = (char*)p_data;

	printf("%c", *print);
}

void* DataConvert(char para)
{
	char* newdata = new char;
	*newdata = para;

	void* pt = newdata;
	return pt;
}