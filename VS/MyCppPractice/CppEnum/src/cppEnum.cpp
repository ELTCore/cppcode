#include <iostream>

enum Example
{
	A = 0, B, C
};


int main()
{

	// 1 2 3
	std::cout << "A = " << A
		<< "\nB = " << B
		<< "\nC = " << C
		<< std::endl;

	std::cin.get();

	return 0;
}