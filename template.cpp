#include <iostream>
#include <list>

using namespace std;

/* template temptate 模板模板函数 */
template <typename T,
          template <typename U> class Container>
class XCLS
{
private:
    Container<T> c;
};

/* alias template 别名模板 */
template <typename T>
using Lst = list<T>;

int main()
{
    XCLS<string, Lst> mylist2;
    system("pause");
    return 0;
}
