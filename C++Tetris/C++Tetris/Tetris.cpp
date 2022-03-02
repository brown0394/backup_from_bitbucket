#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#include "Tetris.h"




Tetris::Tetris() : m_stagearr{ 0 }, m_block_pos_x(1), m_block_pos_y(1), m_next_tick(0), m_delaytick(1000), m_rottype(0), m_blocktypes{ 0 },
m_currentBlockType(0), m_blockbreakcount(0)
{
	m_delaytick = 500;
	m_next_tick = GetTickCount64() + m_delaytick;

	StageInit();
	BlockInitialize();
	SetBlockStart();
	CreateRandomBlock();
	
}

void Tetris::BlockInitialize()
{
	for (int i = 0; i < BLOCKWIDTH; ++i)
	{
		m_blocktypes[0].blockdata[0].BlockElementData[1][i] = 1;
		m_blocktypes[0].blockdata[1].BlockElementData[i][1] = 1;
		m_blocktypes[0].blockdata[2].BlockElementData[1][i] = 1;
		m_blocktypes[0].blockdata[3].BlockElementData[i][1] = 1;
	}
	for (int i = 0; i < BLOCKWIDTH; ++i)
	{
		m_blocktypes[1].blockdata[i].BlockElementData[0][1] = 1;
		m_blocktypes[1].blockdata[i].BlockElementData[0][2] = 1;
		m_blocktypes[1].blockdata[i].BlockElementData[1][1] = 1;
		m_blocktypes[1].blockdata[i].BlockElementData[1][2] = 1;
	}
	for (int i = 0; i < 2; ++i)
	{
		int a = i * 2;
		int b = (i * 2) + 1;


		m_blocktypes[2].blockdata[a].BlockElementData[0][1] = 1;
		m_blocktypes[2].blockdata[a].BlockElementData[1][1] = 1;
		m_blocktypes[2].blockdata[a].BlockElementData[1][2] = 1;
		m_blocktypes[2].blockdata[a].BlockElementData[2][2] = 1;

		m_blocktypes[2].blockdata[b].BlockElementData[0][1] = 1;
		m_blocktypes[2].blockdata[b].BlockElementData[0][2] = 1;
		m_blocktypes[2].blockdata[b].BlockElementData[1][0] = 1;
		m_blocktypes[2].blockdata[b].BlockElementData[1][1] = 1;

	}

		m_blocktypes[3].blockdata[0].BlockElementData[0][1] = 1;
		m_blocktypes[3].blockdata[0].BlockElementData[1][0] = 1;
		m_blocktypes[3].blockdata[0].BlockElementData[1][1] = 1;
		m_blocktypes[3].blockdata[0].BlockElementData[1][2] = 1;

		m_blocktypes[3].blockdata[1].BlockElementData[0][1] = 1;
		m_blocktypes[3].blockdata[1].BlockElementData[1][1] = 1;
		m_blocktypes[3].blockdata[1].BlockElementData[1][2] = 1;
		m_blocktypes[3].blockdata[1].BlockElementData[2][1] = 1;

		m_blocktypes[3].blockdata[2].BlockElementData[1][0] = 1;
		m_blocktypes[3].blockdata[2].BlockElementData[1][1] = 1;
		m_blocktypes[3].blockdata[2].BlockElementData[1][2] = 1;
		m_blocktypes[3].blockdata[2].BlockElementData[2][1] = 1;

		m_blocktypes[3].blockdata[3].BlockElementData[1][0] = 1;
		m_blocktypes[3].blockdata[3].BlockElementData[0][1] = 1;
		m_blocktypes[3].blockdata[3].BlockElementData[1][1] = 1;
		m_blocktypes[3].blockdata[3].BlockElementData[2][1] = 1;

}

void Tetris::GotoXy(int x, int y)
{
	COORD position = { x, y };
	//	SetCursorPos(x, y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Tetris::StageInit()
{
	for (int y = 0; y < STAGEMAXHEIGHT; ++y)
	{
		for (int x = 1; x < STAGEMAXWIDTH - 1; ++x)
		{
			m_stagearr[0][x] = 3;
			m_stagearr[STAGEMAXHEIGHT - 1][x] = 3;

			m_stagearr[y][0] = 2;
			m_stagearr[y][STAGEMAXWIDTH -1] = 2;
		}

	}
}

void Tetris::DrawStage()
{
	for (int y = 0; y < STAGEMAXHEIGHT; ++y)
	{
		for (int x = 0; x < STAGEMAXWIDTH; ++x)
		{
			if (m_stagearr[y][x] == static_cast<int>(None))
			{
				GotoXy(x * 2, y);
				printf("в╞");
			}
			else if (m_stagearr[y][x] == static_cast<int>(Block))
			{
				GotoXy(x * 2, y);
				printf("бс");

			}
			else if (m_stagearr[y][x] == static_cast<int>(SideWall) )
			{
				GotoXy(x * 2, y);
				printf("|");

			}
			else if (m_stagearr[y][x] == static_cast<int>(FlatWall))
			{
				GotoXy(x * 2, y);
				printf("-");

			}
		}


	}
}


void Tetris::DrawBlock()
{
	for (int y = 0; y < BLOCKHEIGHT; ++y)
	{
		for (int x = 0; x < BLOCKWIDTH; ++x)
		{

			if (1 == GetBlcokRot(x, y))
			{
				GotoXy((x + m_block_pos_x) * 2, y + m_block_pos_y);
				printf("бс");

			}		
		}

	}
}


void Tetris::Draw()
{
	DrawStage();
	DrawBlock();
}

int Tetris ::GetBlcokRot(int x, int y)
{
	return m_blocktypes[m_currentBlockType].blockdata[m_rottype].BlockElementData[y][x];
}

void Tetris::SetBlockStart()
{
	m_block_pos_y = 1;
	m_block_pos_x = (STAGEMAXWIDTH * 0.5) - 2;
}

void Tetris::CreateRandomBlock()
{
	srand(static_cast<unsigned int>(time(NULL)));

	m_currentBlockType = rand() % BLOCKTYPEAMOUNT;

}


void Tetris::CopyBlockData()
{

	for (int y = 0; y < BLOCKHEIGHT; ++y)
	{
		for (int x = 0; x < BLOCKWIDTH; ++x)
		{
			if (1 == GetBlcokRot(x, y) )
			{
				m_stagearr[y + m_block_pos_y][x + m_block_pos_x] = static_cast<int>(Block);
			}
		}
	}

}





void Tetris::GameUpdate()
{
	int currenttick = GetTickCount64();
	bool isflag = false;

	if (m_next_tick <= currenttick)
	{
		m_next_tick = currenttick + m_delaytick;
		isflag = true;
	}
	if (isflag == true)
	{
		++m_block_pos_y;
		if (true == IsDownCollision())
		{
			--m_block_pos_y;
			CopyBlockData();
			CheckBlockLine();
			SetBlockStart();
			CreateRandomBlock();
		}
	}
	InputUpdate();
}

void Tetris::InputUpdate()
{
	if (_kbhit())
	{
		char input = '\0';
		//scanf_s("c", &input, sizeof(char));
		input = _getch();

		if (input == 'd' || input == 77)
		{
			++m_block_pos_x;
			if (true == IsSideCollision())
			{
				--m_block_pos_x;
			}
		}
		else if (input == 'a' || input == 75)
		{
			--m_block_pos_x;
			if (true == IsSideCollision())
			{
				++m_block_pos_x;
			}
		}
		else if (input == 's' || input == 80)
		{
			++m_block_pos_y;
			if (true == IsDownCollision())
			{
				--m_block_pos_y;
			}
		}
		else if (input == 'w' || input == 72)
		{
			IsRotatable();
		}
	}

	


}

bool Tetris::IsSideCollision()
{
	for (int y = 0; y < BLOCKHEIGHT; ++y)
	{
		for (int x = 0; x < BLOCKWIDTH; ++x)
		{
			if (1 == GetBlcokRot(x, y) &&
				(m_stagearr[y + m_block_pos_y][x + m_block_pos_x] == static_cast<int>(Block) ||
					m_stagearr[y + m_block_pos_y][x + m_block_pos_x] == static_cast<int>(SideWall)))
			{
				return true;
			}
		}
	}

	return false;
}

bool Tetris::IsDownCollision()//(int p_blockwidth, int p_blockheight)
{
	for (int y = 0; y < BLOCKHEIGHT; ++y)
	{
		for (int x = 0; x < BLOCKWIDTH; ++x)
		{
			if (1 == GetBlcokRot(x, y) &&
				(m_stagearr[y + m_block_pos_y][x + m_block_pos_x] == static_cast<int>(Block) ||
				m_stagearr[y + m_block_pos_y][x + m_block_pos_x] == static_cast<int>(FlatWall)))
			{
				return true;			
			}
		}	
	}

	return false;
}


bool Tetris::IsRotatable()
{
	int temp = m_rottype;

	m_rottype = (m_rottype + 1) % BLOCKROTTYPE;
	if (true == IsSideCollision())
	{
		int tempx = m_block_pos_x;

		for (int i = 1; i < 3; ++i)
		{
			m_block_pos_x += i;
			if (false == IsSideCollision())
			{
				return true;
			}

			m_block_pos_x -= (i * 2);
			if (false == IsSideCollision())
			{
				return true;
			}
		}
		m_block_pos_x = tempx;
		m_rottype = temp;
		return false;
	}
	if (true == IsDownCollision())
	{
		m_rottype = temp;
		return false;
	}
	return true;
}

bool Tetris::IsStageFull()
{
	for (int i = 1; i < STAGEMAXWIDTH; ++i)
	{
		if (m_stagearr[1][i] == 1)
		{
			return true;

		}
	}

	return false;
}

void Tetris::CheckBlockLine()
{
	bool isBlock = false;
	for (int y = STAGEMAXHEIGHT - 2; y > 0; --y)
	{
		for (int x = STAGEMAXWIDTH - 2; x > 0; --x)
		{
			if (m_stagearr[y][x] != static_cast<int>(Block))
			{
				isBlock = false;
				break;
			}
			else
			{
				isBlock = true;
			}
		}
		if (true == isBlock)
		{
			StageMoveDown(y);
			++y;
			m_blockbreakcount++;
			if (2 == m_blockbreakcount)
			{
				m_delaytick -= 50;
				m_blockbreakcount = 0;
			}
		}
	}
}

void Tetris::StageMoveDown(int p_y)
{
	for (int y = p_y; y > 1; --y)
	{
		for (int x = STAGEMAXWIDTH - 2; x > 0; --x)
		{
			m_stagearr[y][x] = m_stagearr[y - 1][x];
		}
	}

}


int Tetris::GameLogic()
{
	GameUpdate();
	Draw();
	if (true == IsStageFull())
	{
		return -1;
	}
	return 0;
}

void Tetris::Game()
{
	int result = 0;
	while (true)
	{
		result = GameLogic();

		if (result < 0)
		{
			printf("GAMEOVER");
			break;
		}

	}

}