#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    int j(); /* 0 */
    int *p;
    int *q(); /* nullptr */

    /* error: narrowing conversion  */
    // int x1{0.5};

    /* 编译器调用initializer_list私有构造之前，编译器准备好array(array头)与len，传递给该构造，并没有内含这个array */
    /* 指针指向array，copy只是浅copy，如今所有容器都接受任意数量的值 insert() max() min() */

    cout << max({1, 2, 3}) << endl;
    system("pause");
    return 0;
}