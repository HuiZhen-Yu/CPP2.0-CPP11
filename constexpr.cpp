#include <iostream>
#include <array>
using namespace std;

// 对于修饰Object来说:
// const并未区分出编译期常量(比如数组的大小，在程序编译期间就需要确定)和运行期常量(在程序运行过程中不能被修改的常量)
// constexpr限定在了编译期常量
// constexpr作用：优化!效率!
// constexpr修饰的函数，返回值不一定是编译期常量。It is not a bug, it is a feature.
// const修饰的是类型，constexpr修饰的是用来算出值的那段代码。
/**
 * constexpr修饰的函数，简单的来说，如果其传入的参数可以在编译时期计算出来，那么这个函数就会产生编译时期的值。
 * 但是，传入的参数如果不能在编译时期计算出来，那么constexpr修饰的函数就和普通函数一样了。不
 * @param i
 * @return i + 10
 */
/* 具体有关编译器常量与运行期常量的内容可以参照：https://zhuanlan.zhihu.com/p/250238866 */
constexpr int foo(int i)
{
    return i + 10;
}

int main()
{
    int i = 10;
    /* OK */
    std::array<int, foo(2)> arr;

    /* Call is Ok */
    foo(i);
    /* error: the value of ‘i’ is not usable in a constant expression */
    // std::array<int, foo(i)> arr1;
    system("pause");
    return 0;
}