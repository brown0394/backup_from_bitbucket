#include <iostream>
#include <ctime>




template <typename T>
T Add(T a, T b)
{
	return a + b;

}


void Swap(void* a, void* b, int sizeof_para)
{

	if (sizeof_para != 0)
	{
		void* temp = malloc(sizeof_para);
		memcpy(temp, a, sizeof_para);
		memcpy(a, b, sizeof_para);
		memcpy(b, temp, sizeof_para);
		free(temp);
	}
	else { std::cout << "변수 사이즈 값이 0 이하 입니다."; }


}

void Random()
{
	int random = 0;
	const int max_rand_limit = 1000;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < max_rand_limit; ++i)
	{
		random = (rand() % 100) + 1;
	}

	if (random <= 50)
	{
		std::cout << "앞   " << random << std::endl;
	}
	else if (random > 50 && random <= 100)
	{
		std::cout << "뒤   " << random << std::endl;
	}
}

void Random2()
{
	int random = 0;
	const int max_rand_limit = 1000;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < max_rand_limit; ++i)
	{
		random = (rand() % 2) + 1;
	}

	if (random == 1)
	{
		std::cout << "앞    " << random << std::endl;
	}
	else if (random == 2)
	{
		std::cout << "뒤     " << random << std::endl;
	}
}

class XY
{
private:
	int _x;
	int _y;

public:
	XY(): _x(0), _y(0)
	{
	
	}
	XY(int para1, int para2)
	{
		this->_x = para1;
		this->_y = para2;
	}
	XY(const XY &para)
	{
		this->_x = para._x;
		this->_y = para._y;
	}
	XY operator+(const XY& para)
	{
		this->_x += para._x;
		this->_y += para._y;
		return XY(this->_x, this->_y);
	}
	XY operator++()
	{
		this->_x = this->_x + 1;
		this->_y = this->_y + 1;
		return XY(this->_x, this->_y);
	}
	XY operator++(int) // 후위
	{
		this->_x = this->_x + 1;
		this->_y = this->_y + 1;
		return XY(this->_x, this->_y);
	}
	XY operator+=(const XY& para)
	{
		this->_x += para._x;
		this->_y += para._y;
		return XY(this->_x, this->_y);
	
	}



	void ShowXY()
	{
		std::cout << this->_x << ' ' << this->_y << " \n";
	}

	friend void FriendXY(XY &para);//f

};

void FriendXY(XY &para)//f
{
	para._x += 15;
}

int main()
{
	int a = 10;
	int b = 12;

	float a1 = 1.2f;
	float a2 = 2.2f;


	a = Add(a, b);
	a1 = Add(a1, a2);

	std::cout << a << ' ' << a1 << std::endl;


	Swap(&a, &b, sizeof(a));

	Swap(&a1, &a2, sizeof(a1));

	std::cout << a << ' ' << b << std::endl;
	std::cout << a1 << ' ' << a2 << std::endl;



	char string1[20] = { "첫 번째 문장    " };
	char string2[20] = { "두 번째 문장    " };

	std::cout << string1 << ' ' << string2 << std::endl;

	Swap(string1, string2, sizeof(string1));
	std::cout << string1 << ' ' << string2 << std::endl;


	int arr1[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int arr2[10] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

	Swap(arr1, arr2, sizeof(int)*10);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << arr1[i] << ' ';
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << arr2[i] << ' ';
	}
	std::cout << std::endl;

	XY xy1;
	XY xy2(12, 23);

	xy1.ShowXY();
	xy2.ShowXY();

	XY xy3(xy2);
	xy3.ShowXY();

	++xy1;
	xy1.ShowXY();

	xy1 = xy2 + xy3;
	xy1.ShowXY();

	xy1 += xy2;
	xy1.ShowXY();

	xy1 = Add(xy1, xy2);
	xy1.ShowXY();

	Swap(&xy1, &xy2, sizeof(xy1));
	xy1.ShowXY();

	FriendXY(xy1);
	xy1.ShowXY();

	char input = '\0';

	while (input != 'q')
	{
		std::cin >> input;
		Random();
		Random2();
	}
}