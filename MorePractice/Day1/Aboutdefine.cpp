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
     * static const ����ֱ�������ڲ���ʼ��
     * no-const staticֻ�����ⲿ��ʼ��
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

const int C::NUM; /* ���� */
int main(int argc, char **argv)
{
    cout << p << endl; /* macro is global */
    C c;
    // cout << &c.NUM1 << endl; /* δ��������� ��Ҫ���� */
    cout << C::NUM1 << endl;

    int a = 5, b = 0;
    cout << MAX(++a, b) << endl;      /* a���ۼ����� */
    cout << MAX(++a, b + 10) << endl; /* a���ۼ�һ�� */
    a = 5, b = 0;
    cout << Max(++a, b) << endl;
    system("pause");
    return 0;
}