/* Created by light on 19-11-2. */

// variadic template(c++11) 数量不定的模板参数
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
// 参数个数  参数个数逐一递减
// 参数类型  参数类型也逐一递减

// (3)
// 需要重载一个终止函数
template<typename T>
void _hash(size_t &seed, const T &val)
{
    cout << "hash over " << val << endl;
    cout << "seed " << seed << endl;
}

// (2)
// 展开函数, 把参数分为一个普通参数和一个参数包，调用一次，参数包大小就减一
template<typename T, typename ...Args>
void _hash(size_t &seed, const T& val, const Args &... args)
{
    cout << "parameter " << val << endl;
    cout << "seed = " << seed++ << endl;
    // 递归调动自己, 如果上面不给T参数，就会自己调用自己，形成死循环
    _hash(seed, args...);
}

// 泛化版 (1)
// 使用 Args ... args 来指出 args 是一个函数参数包
template<typename ...Args>
size_t _hash(const Args &... args) {
    cout << "hash start " << endl;
    size_t seed = 10;
    // 递归调用自己
    // 将一个包分解为构成的元素，并对每个元素应用模式，获得扩展后的列表。
    // C++ 通过在模式的右边加上一个省略号来触发包扩展
    _hash(seed, args...);
    return seed;
}

template<typename ...Args>
class A {
private:
    int size = 0;
public:
    A() {
        // 通过 sizeof... 运算符获取参数包中的参数个数
        size = sizeof...(Args);
        cout << "size = " << size << endl;
    }
};

int main(void) {
    _hash("asdas", 2, 3, 4);
    /* 打印结果如下所示：
        hash start 
        parameter asdas
        seed = 10
        parameter 2
        seed = 11
        parameter 3
        seed = 12
        hash over 4
        seed 13
    */
    cout << "==========" << endl;
    A<int, string, vector<int>> a;    // 类型任意
    /*
        打印结果如下所示：
        size = 3
    */
    cout << "==========" << endl;

    // Tuple就是利用这个特性(变长参数模板)
    tuple<int, string> t = make_tuple(1, "hha");
    int firstArg = get<0>(t);
    string secondArg = get<1>(t);
    cout << firstArg << " " << secondArg << endl;
    /*
        打印结果如下所示：
        1 hha
    */
    return 0;
}