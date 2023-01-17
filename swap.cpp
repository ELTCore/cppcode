#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    cout << "a = a ^ b = " << a << endl;
    b = a ^ b;
    cout << "b = a ^ b = " << b << endl;
    a = a ^ b;
    cout << "a = a ^ b = " << a << endl;
}

int main(int argc, char const *argv[])
{
    int a = 2;
    int b = 3;

    cout << "a = " << a << "\nb = " << b << endl;

    swap(a, b);

    system("pause");
    return 0;
}
