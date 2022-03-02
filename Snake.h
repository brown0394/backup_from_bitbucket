#pragma once
#include "/Users/user/source/repos/csc0914/4.28/Coord.h"
#include "/Users/user/source/repos/csc0914/LinkedList.h"


struct SSnakeBodyCoord
{
	int x;
	int y;
};

class CSnake : public CCoord
{
	int _eatCount;
	int _fx;
	int _fy;
	int _foodsAte;
	CLinkedList Lists;
	CLinkedList* ListsPt;
	List* _listPt;

public:
	CSnake();
	void Start();
	void MapBuilder();
	void SnakeMove();
	bool WallOrNot(char  xOry, char minOrplus);
	void FoodLocate();
	bool FoodOrNot(char  xOry, char minOrplus);
	bool SnakeBodyOrNot(char  xOry, char minOrplus);
	void SnakeBodyCoordCreateList();
	void SnakeBodyDataSet(int x, int y, List*& list, CLinkedList* temp);
	int CurrentXyPos(int x, int y);
	SSnakeBodyCoord* GetData(void* data);
	void DeleteNodeData(void* &data_to_delete);
	void EatFood();

	~CSnake();
};

