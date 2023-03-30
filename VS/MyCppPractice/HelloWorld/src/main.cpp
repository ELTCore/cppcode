#include <iostream>
#include "Log.h"

class Singleton
{
public:
	static Singleton& Get() {
		static Singleton instance;
		return instance;
	}

	void Hello() {}
};


void Function()
{
	static int i = 0;
	++i;
	std::cout << i << std::endl;
}

int main()
{
	Log("hello world");

	Singleton::Get().Hello();

	std::cin.get();

	return 0;
}