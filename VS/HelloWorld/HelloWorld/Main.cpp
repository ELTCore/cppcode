#include <iostream>
#include "Log.h"

static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

int main()
{
	const char* ptr = "hello";

	if (ptr)
		Log("Ptr is hello");
	else
		Log("Ptr is null!");

	//std::cout << Multiply(5, 8) << std::endl;
	std::cin.get();

	return 0;
}