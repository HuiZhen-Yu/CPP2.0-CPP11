#include <iostream>
#include <list>

using namespace std;

/* template temptate ģ��ģ�庯�� */
template <typename T,
          template <typename U> class Container>
class XCLS
{
private:
    Container<T> c;
};

/* alias template ����ģ�� */
template <typename T>
using Lst = list<T>;

int main()
{
    XCLS<string, Lst> mylist2;
    system("pause");
    return 0;
}
