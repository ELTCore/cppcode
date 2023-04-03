#include <iostream>

class Entity
{
public:
	float X, Y;

	Entity() = delete;

	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	~Entity()
	{
		std::cout << "awsl" << std::endl;
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};


int main()
{
	//error
	//Entity e;

	Entity e(5.0f,10.0f);
	e.Print();

	std::cin.get();

	return 0;
}