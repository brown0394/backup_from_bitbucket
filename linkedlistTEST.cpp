#include "pch.h"
#include "LinkedList.h"

struct SLine
{
	int x;
	int y;
};

void SLineList(List* &list, CLinkedList* temp)
{

	SLine* data = new SLine;
	cout << "input x, y : ";
	cin >> data->x >> data->y;
	Node* last = temp->Last(list);
	
	temp->Insert(last, data, list);
}

void GetAll(List* list, SLine* &line)
{
	Node* last = list->head->next;
	Node* next = last->next;
	cout << "\n";
	while (last != list->head)
	{
		line = (SLine*)last->data;
		printf("indexval : %d, x value : %d, y value : %d\n", last->idx, line->x, line->y);
		last = next;
		next = last->next;

	}


}

int main()
{
	SLine line;
	SLine* pointer = &line;
	CLinkedList lines;
	List* list = nullptr;
	lines.CreateList(list);
	int input = 0;

	
	while (1)
	{
		printf("1. Add line\n2. Show line\n3. Delete line\n4. Exit\ninput : ");
		cin >> input;

		switch (input)
		{
			case 1:
			{
				SLineList(list, &lines);
				break;
			}
			case 2:
			{
				printf("\n1. Show all\n2. Show a line\ninput : ");
				cin >> input;
				switch (input)
				{
					case 1:
					{
						GetAll(list, pointer);
						int total = lines.GetTotal();
						printf("total amount of nodes : %d\n", total);
						break;
					}
					case 2:
					{
						printf("\ninput index value of the line to see : ");
						cin >> input;
						Node* search = lines.Search(list, input);
						pointer = (SLine*)search->data;
						printf("indexval : %d, x value : %d, y value : %d\n", search->idx, pointer->x, pointer->y);
						break;
					}
				}
			 break;
			}
			case 3:
			{
				printf("\ninput index value of the line to delete : ");
				cin >> input;
				Node* search = lines.Search(list, input);
				lines.Delete(search, list);
				printf("\nDelete Complete\n");
				break;
			}
			case 4:
			{
				lines.DeleteList(list);
				printf("\nExit\n");
				return 0;
				break;
			}

			}
		}

	}



