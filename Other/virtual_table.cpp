#include <iostream>

class Base
{
public:
    virtual void f() { std::cout << "Base::f()" << std::endl; }
    virtual void g() { std::cout << "Base::g()" << std::endl; }
    virtual void h() { std::cout << "Base::h()" << std::endl; }
};

class Derived : public Base
{
public:
    virtual void x() { std::cout << "Derived::x()" << std::endl; }
    virtual void f() { std::cout << "Derived::f()" << std::endl; }
};

int main()
{
    Derived d;
    Base *b = &d;

    // 获取虚函数表指针
    int *vtable = *reinterpret_cast<int **>(&d);

    // 调用 Derived::x()
    reinterpret_cast<void (*)()>(vtable[0])();

    // 调用 Derived::f()
    reinterpret_cast<void (*)()>(vtable[1])();

    // 调用 Base::h()
    reinterpret_cast<void (*)()>(vtable[2])();

    system("pause");

    return 0;
}