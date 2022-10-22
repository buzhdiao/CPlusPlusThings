//
// Created by light on 19-11-3.
//

#include <iostream>

using namespace std;

// final关键字用于两个地方
// 第一个用在类，用于说明该类是继承体系下最后的一个类，不要其他类继承，当继承时就会报错。
class Base final {
public:
    Base() {}

    virtual void func() {}
};

class Derivered : public Base {     // error: cannot derive from ‘final’ base ‘Base’ in derived type ‘Derivered’
};
// 第二个用在虚函数，表示这个虚函数不能再被override了，再override就会报错。
class Base1 {
public:
    Base1() {}

    virtual void func() final {}
};

class Derivered1 : public Base1 {
    virtual void func() {}      // error: overriding final function ‘virtual void Base1::func()’
};
int main() {

}

/* 
编译运行结果如下
E:\repo\CPlusPlusThings\c++2.0\c++11\final.cpp:18:7: error: cannot derive from 'final' base 'Base' in derived type 'Derivered'
   18 | class Derivered : public Base {     // error: cannot derive from ‘final’ base ‘Base’ in derived type ‘Derivered’
      |       ^~~~~~~~~
E:\repo\CPlusPlusThings\c++2.0\c++11\final.cpp:29:18: error: virtual function 'virtual void Derivered1::func()' overriding final function
   29 |     virtual void func() {}      // error: overriding final function ‘virtual void Base1::func()’
      |                  ^~~~
E:\repo\CPlusPlusThings\c++2.0\c++11\final.cpp:25:18: note: overridden function is 'virtual void Base1::func()'
   25 |     virtual void func() final {}
*/