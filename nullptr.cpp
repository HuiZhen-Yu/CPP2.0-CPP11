#include <iostream>
using namespace std;

void f(int i)
{
    cout << "void f(int i)" << i << endl;
}

void f(void *p)
{
    cout << "void f(void *p)" << p << endl;
}
int main()
{
    f(0);

    // #ifndef __cplusplus
    // #define NULL ((void *)0)
    // #else   /* C++ */
    // #define NULL 0

    //  c�����н�NULL����Ϊ��ָ�룬����c++��ֱ�Ӷ���Ϊ0��������ΪC++��ǿ���͵ģ�void *�ǲ�����ʽת��������ָ�����͵ġ�

    if (NULL == 0)
        cout << "NULL==0" << endl;
    //f(NULL); // ambiguous,��ΪNULL==0���Դ��ڶ����� ָ��Ҳ�����Ǹ�int�ĵ�ַ
    // c++11 ��ָ��nullptr
    f(nullptr); // typedef decltype(nullptr)	nullptr_t;
    // nullptr_tΪnullptr������
    nullptr_t nl; // ʹ��nullptr_t������κα���������nullptrһ������Ϊ
    f(nl);
    system("pause");
    return 0;
}