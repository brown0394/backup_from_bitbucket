#include "Snake.h"
#include<iostream>
#include<conio.h>

CSnake::CSnake():_eatCount(0), _fx(0), _fy(0), _listPt(nullptr), ListsPt(&Lists), _foodsAte(1)
{
}

void CSnake::MapBuilder()
{
	_xCoord = 0;
	_yCoord = 0;

	GoToXY(_xCoord, _yCoord);

	for (int i = _xCoord; i <= 25; ++i)
	{
		_xCoord = i;
		for (int j = _yCoord; j <= 13; ++j)
		{
			_yCoord = j;
			GoToXY(_xCoord, _yCoord);
		}
	}

	for (int i = _xCoord; i >= 0; --i)
	{
		_xCoord = i;
		for (int j = _yCoord; j >= 0; --j)
		{
			_yCoord = j;
			GoToXY(_xCoord, _yCoord);
		}
	}
}

void CSnake::Start()
{
	SnakeBodyCoordCreateList();
	MapBuilder();
	FoodLocate();
	_xCoord = 1;
	_yCoord = 1;
	GoToXY(_xCoord, _yCoord);
	SnakeMove();

}

void CSnake::SnakeMove()
{
	char q = '0';
	GoToXY(_xCoord, _yCoord);
	SnakeBodyDataSet(_xCoord, _yCoord, _listPt, ListsPt);
	while (q != 'q')
	{
		//std::cin >> _input;
		_input = _getch();
		switch (_input)
		{
		case 'w':
		{

			if (WallOrNot('y', '-') == false || SnakeBodyOrNot('y', '-') == false)
			{
				q = 'q';
				break;
			}
			else
			{
				if (false == FoodOrNot('y', '-'))
				{
					EatFood();
				}
				else
				{
					GoToTrace(GetData(_listPt->head->next->data)->x, GetData(_listPt->head->next->data)->y);
				}
					_yCoord -= 1;
					SnakeBodyDataSet(_xCoord, _yCoord, _listPt, ListsPt);
					GoToXY(_xCoord, _yCoord);
					break;
			}
		}
		case's':
		{
			if (WallOrNot('y', '+') == false || SnakeBodyOrNot('y', '+') == false)
			{
				q = 'q';
				break;
			}
			else
			{
				if (false == FoodOrNot( 'y', '+'))
				{
					EatFood();
				}
				else
				{
					GoToTrace(GetData(_listPt->head->next->data)->x, GetData(_listPt->head->next->data)->y);
				}
					_yCoord += 1;
					SnakeBodyDataSet(_xCoord, _yCoord, _listPt, ListsPt);
					GoToXY(_xCoord, _yCoord);
					break;
			}
		}
		case'a':
		{
			if (WallOrNot( 'x', '-') == false || SnakeBodyOrNot('x', '-') == false)
			{
				q = 'q';
				break;
			}
			else
			{
				if (false == FoodOrNot( 'x', '-'))
				{
					EatFood();
				}
				else
				{
					GoToTrace(GetData(_listPt->head->next->data)->x, GetData(_listPt->head->next->data)->y);
				}
					_xCoord -= 1;
					SnakeBodyDataSet(_xCoord, _yCoord, _listPt, ListsPt);
					GoToXY(_xCoord, _yCoord);
					break;
			}
		}
		case'd':
		{
			if (WallOrNot( 'x', '+') == false)
			{
				q = 'q';
				break;
			}
			else
			{
				if (false == FoodOrNot( 'x', '+') || SnakeBodyOrNot('x', '+') == false)
				{
					EatFood();
				}
				else
				{
					GoToTrace(GetData(_listPt->head->next->data)->x, GetData(_listPt->head->next->data)->y);
				}
					_xCoord += 1;
					SnakeBodyDataSet(_xCoord, _yCoord, _listPt, ListsPt);
					GoToXY(_xCoord, _yCoord);
					break;
			}
		}
		case'q':
			q = _input;
			break;
		}
		Node* search = Lists.Search(_listPt, 1);
		DeleteNodeData(search->data);
		Lists.Delete(search, _listPt);
	}
}

bool CSnake::WallOrNot(char  xOry, char minOrplus)
{
	if (xOry == 'x')
	{
		if (minOrplus == '+')
		{
				for (int j = 0; j < 13; ++j)
				{
					if (CurrentXyPos(_xCoord, _yCoord) + 100 == 0 + j || CurrentXyPos(_xCoord, _yCoord) + 100 == 2500 + j)
					{
						return false;
					}
				}
		}
		if (minOrplus == '-')
		{
				for (int j = 0; j < 13; ++j)
				{
					if (CurrentXyPos(_xCoord, _yCoord) - 100 == 0 + j || CurrentXyPos(_xCoord, _yCoord) - 100 == 2500 +j)
					{
						return false;
					}
				}
		}		
	}
	else if (xOry == 'y')
	{
		if (minOrplus == '+')
		{
			int i = 0;
			while (i < 2600)
			{
				if (CurrentXyPos(_xCoord, _yCoord) + 1 == 0 + i || CurrentXyPos(_xCoord, _yCoord) + 1 == 13 + i)
				{
					return false;
				}
				i += 100;
			}
		}
		if (minOrplus == '-')
		{
			int i = 0;
			while (i < 2600)
			{
				if (CurrentXyPos(_xCoord, _yCoord) - 1 == 0 + i || CurrentXyPos(_xCoord, _yCoord) - 1 ==13 + i)
				{
					return false;
				}
				i += 100;
			}
		}
	}

	return true;
}

int CSnake::CurrentXyPos(int x, int y)
{
	int curr = 0;
	curr = (x * 100) + (y);
	return curr;
}

void CSnake::FoodLocate()
{
	Node* search = nullptr;
	void* data = nullptr;
	SSnakeBodyCoord* data_pt = nullptr;
	if (_fx + 12 >= 25)
	{
		_fx = (_fx + 12) - 25;
	}
	else
	{
		_fx += 12;
	}
	if (_fy + 6 >= 13)
	{
		_fy = (_fy + 6) - 13;
	}
	else
	{
		_fy += 6;
	}

	for (int i = 0; i < Lists.GetTotal(); ++i)
	{
		search = Lists.Search(_listPt, i + 1);
		data = search->data;
		data_pt = (SSnakeBodyCoord*)data;
		if (data_pt->x == _fx && data_pt->y == _fy)
		{
			if (_fx + 1 >= 25)
			{
				--_fx;
			}
			else if (_fx - 1 == 0)
			{
				++_fx;
			}
		}
	}
	GoToXY(_fx, _fy);

}

bool CSnake::FoodOrNot(char  xOry, char minOrplus)
{
	if (xOry == 'x')
	{
		if (minOrplus == '+')
		{
			if (CurrentXyPos(_xCoord + 1, _yCoord) == CurrentXyPos(_fx, _fy))
			{
				return false;
			}
		}
		if (minOrplus == '-')
		{
			if (CurrentXyPos(_xCoord - 1, _yCoord) == CurrentXyPos(_fx, _fy))
			{
				return false;
			}
		}
	}
	else if (xOry == 'y')
	{
		if (minOrplus == '+')
		{
			if (CurrentXyPos(_xCoord, _yCoord + 1) == CurrentXyPos(_fx, _fy))
			{
				return false;
			}
		}
		if (minOrplus == '-')
		{
			if (CurrentXyPos(_xCoord, _yCoord - 1) == CurrentXyPos(_fx, _fy))
			{
				return false;
			}
		}
	}
	return true;
}

bool CSnake::SnakeBodyOrNot(char  xOry, char minOrplus)
{
	Node* search = nullptr;
	void* data = nullptr;
	SSnakeBodyCoord* data_pt = nullptr;
	for (int i = 0; i < Lists.GetTotal(); ++i)
	{
		search = Lists.Search(_listPt, i + 1);
		data = search->data;
		data_pt = (SSnakeBodyCoord*)data;
		if (xOry == 'x')
		{
			if (minOrplus == '+')
			{
				if (CurrentXyPos(_xCoord + 1, _yCoord) == CurrentXyPos(data_pt->x, data_pt->y))
				{
					return false;
				}
			}
			if (minOrplus == '-')
			{
				if (CurrentXyPos(_xCoord - 1, _yCoord) == CurrentXyPos(data_pt->x, data_pt->y))
				{
					return false;
				}
			}
		}
		else if (xOry == 'y')
		{
			if (minOrplus == '+')
			{
				if (CurrentXyPos(_xCoord, _yCoord + 1) == CurrentXyPos(data_pt->x, data_pt->y))
				{
					return false;
				}
			}
			if (minOrplus == '-')
			{
				if (CurrentXyPos(_xCoord, _yCoord - 1) == CurrentXyPos(data_pt->x, data_pt->y))
				{
					return false;
				}
			}
		}
	}

	return true;
}

void CSnake::SnakeBodyCoordCreateList()
{
	Lists.CreateList(_listPt);
}


void CSnake::SnakeBodyDataSet(int x, int y, List*& list, CLinkedList* temp)
{
	SSnakeBodyCoord* data = new SSnakeBodyCoord;
	data->x = x;
	data->y = y;
	Node* last = temp->Last(list);

	temp->Insert(last, data, list);

}

SSnakeBodyCoord* CSnake::GetData(void* data)
{
	SSnakeBodyCoord* newdata = (SSnakeBodyCoord*)data;
	return newdata;
}

void CSnake::DeleteNodeData(void* &data_to_delete)
{
	delete (SSnakeBodyCoord*)data_to_delete;
}

void CSnake::EatFood()
{
	SSnakeBodyCoord* newCord = new SSnakeBodyCoord;
	void* dataPt = _listPt->head->next->data;
	SSnakeBodyCoord* pt = (SSnakeBodyCoord*)dataPt;

	newCord->x = pt->x;
	newCord->y = pt->y;
	Lists.Insert(_listPt->head, newCord, _listPt);
	GoToXY(GetData(_listPt->head->next->data)->x, GetData(_listPt->head->next->data)->y);

	FoodLocate();
	++_eatCount;
}

CSnake::~CSnake()
{
	Lists.DeleteList(_listPt);
}
