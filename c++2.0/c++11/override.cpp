//
// Created by light on 19-11-3.
//

#include <iostream>

using namespace std;

/*
    描述: override保留字表示当前函数重写了基类的虚函数。
    目的:
        1.在函数比较多的情况下可以提示读者某个函数重写了基类虚函数（表示这个虚函数是从基类继承，不是派生类自己定义的）
        2.强制编译器检查某个函数是否重写基类虚函数，如果没有则报错。
    用法:在类的成员函数参数列表后面添加该关键字既可。
*/

class Base
{
public:
    Base(){}
    // 表示新定义了一个虚函数，名称是func
    virtual void func() {}
};
class Derivered:public Base
{
    virtual void func(int) override {}  //编译报错: error: ‘virtual void Derivered::func(int)’ marked ‘override’, but does not override
};

int main()
{
    return 0;
}