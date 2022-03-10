#include <iostream>

using namespace std;

struct A
{
#define p "Hello"
};

class C
{
public:
    /**
     * static const 可以直接在类内部初始化
     * no-const static只能在外部初始化
     */
    static const int NUM = 3;
    enum con
    {
        NUM1 = 3
    };
};

#define MAX(a, b) ((a) > (b) ? (a) : (b))

template <typename T>
inline int Max(const T &a, const T &b)
{
    return a > b ? a : b;
}

const int C::NUM; /* 定义 */
int main(int argc, char **argv)
{
    cout << p << endl; /* macro is global */
    C c;
    // cout << &c.NUM1 << endl; /* 未定义的引用 需要定义 */
    cout << C::NUM1 << endl;

    int a = 5, b = 0;
    cout << MAX(++a, b) << endl;      /* a被累加两次 */
    cout << MAX(++a, b + 10) << endl; /* a被累加一次 */
    a = 5, b = 0;
    cout << Max(++a, b) << endl;
    system("pause");
    return 0;
}