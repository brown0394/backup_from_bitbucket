#pragma once
class CCoord
{
protected:
	int _xCoord;
	int _yCoord;
	char _input;

public:
	CCoord();
	void SetPosition(int x, int y);
	void Move(int x, int y);
	void GoToXY(int x, int y);
	void GoToTrace(int x, int y);
	void Show();
	void Update(int thick);

	void KeyboardInput();


	~CCoord();
};

