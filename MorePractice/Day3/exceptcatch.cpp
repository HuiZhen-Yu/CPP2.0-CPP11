#include <iostream>
using namespace std;

/* 函数异常可以跑出去自主函数来处理 */
void fun(int x)
{
    try
    {
        if (x > 0)
        {
            throw "异常";
        }
    }
    catch (int a)
    {
        cout << "in fun" << endl;
        if (a == 1)
            throw 1;
        else if (a == 2)
            throw 2.34;
        else if (a == 3)
            throw "haha";
        else
            throw 23;
    }
}

int main(int argc, char const *argv[])
{

    try
    {
        fun(0);
    }
    catch (...)
    {
        cout << "in main" << endl;
    }

    system("pause");
    return 0;
}