#include <iostream>

#include "..\CppEnum\global.h"

class Printable
{
public:
	virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}

	std::string GetName() override
	{
		return m_Name;
	}

	std::string GetClassName() override
	{
		return m_Name;
	}


	//std::string GetClassName() {
	//	return;
	//}
};

void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	Player* p = new Player("cherno");

	std::cout << g_variable << std::endl;

	Print(e);
	Print(p);

	std::cin.get();

	return 0;
}