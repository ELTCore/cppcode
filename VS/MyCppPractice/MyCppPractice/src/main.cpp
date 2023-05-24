#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, char> test01;
	test01.emplace(3, 'a');
	test01.emplace(5, 'b');
	test01.emplace(1, 'c');

	map<char, int> test02;
	test02.emplace('c', 1);
	test02.emplace('b', 5);
	test02.emplace('a', 3);


	cout << "test01: " << endl;
	for (auto it : test01)
	{
		cout << it.first << " " << it.second << endl;
	}

	cout << "\ntest02: " << endl;
	for (auto it : test02)
	{
		cout << it.first << " " << it.second << endl;
	}


	return 0;
}