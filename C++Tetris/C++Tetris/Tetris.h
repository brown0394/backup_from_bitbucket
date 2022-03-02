#pragma once

#define STAGEMAXHEIGHT 22
#define STAGEMAXWIDTH 12
#define BLOCKHEIGHT 4
#define BLOCKWIDTH 4
#define BLOCKROTTYPE 4
#define BLOCKTYPEAMOUNT 4

enum BlockType
{
	None = 0,
	Block,
	SideWall,
	FlatWall
};

struct S_BlockData
{
	int BlockElementData[BLOCKHEIGHT][BLOCKWIDTH] = { 0 };
};

struct S_BlockTypes
{
	S_BlockData blockdata[BLOCKROTTYPE] = {0};

};

class Tetris
{
	S_BlockTypes m_blocktypes[BLOCKTYPEAMOUNT];

	int m_next_tick;
	int m_delaytick;
	int m_block_pos_y;
	int m_block_pos_x;
	int m_stagearr[STAGEMAXHEIGHT][STAGEMAXWIDTH];

	int m_blockbreakcount;

	int m_currentBlockType;
	int m_rottype;
public:



	Tetris();

	void GotoXy(int x, int y);



	void StageInit();
	void DrawStage();
	void DrawBlock();
	void Draw();

	void CreateRandomBlock();
	int GetBlcokRot(int x, int y);
	void BlockInitialize();
	void SetBlockStart();

	bool IsSideCollision();
	bool IsDownCollision();
	bool IsRotatable();

	
	void StageMoveDown(int p_y);
	void CopyBlockData();
	void CheckBlockLine();
	bool IsStageFull();


	void GameUpdate();
	int GameLogic();

	void InputUpdate();
	void Game();
};

