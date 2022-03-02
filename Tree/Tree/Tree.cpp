#include <iostream>
#include "LCRSTree.h"



void DeleteData(void* _pdata);
void ShowData(void* p_data);
void* DataConvert(char para);

int main()
{
	LCRSTree Tree(DeleteData, ShowData);

	TNode* root = Tree.CreateNode(DataConvert('a'));

	TNode* one = Tree.CreateNode(DataConvert('b'));
	TNode* two = Tree.CreateNode(DataConvert('c'));
	TNode* three = Tree.CreateNode(DataConvert('d'));
	TNode* four = Tree.CreateNode(DataConvert('e'));
	TNode* five = Tree.CreateNode(DataConvert('f'));
	TNode* six = Tree.CreateNode(DataConvert('g'));
	TNode* seven = Tree.CreateNode(DataConvert('h'));
	TNode* eight = Tree.CreateNode(DataConvert('i'));

	Tree.AddChild(root, one);
	Tree.AddChild(root, two);
	Tree.AddChild(one, three);
	Tree.AddChild(one, four);
	Tree.AddChild(two, five);
	Tree.AddChild(two, six);
	Tree.AddChild(three, seven);
	Tree.AddChild(six, eight);

	Tree.PrintTree(root, 0);


	Tree.DeleteTree(root);
}




void DeleteData(void* _pdata)
{
	delete (char*)_pdata;
}

void ShowData(void* p_data)
{
	char* temp = (char*)p_data;
	printf("%c\n", *temp);
}

void* DataConvert(char para)
{
	char* data = new char;
	*data = para;
	void* temp = data;
	return temp;
}