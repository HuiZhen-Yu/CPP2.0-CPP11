#include <iostream>
#include <complex>

using namespace std;

class Zoo
{
public:
    Zoo(int a, int b) : a(a), b(b)
    {
        cout << "with param ctor \n";
    }
    Zoo() = default;
    Zoo(const Zoo &) = delete;  /* copy ctor */
    Zoo(const Zoo &&) = delete; /* move ctor */

    Zoo &operator=(const Zoo &) = default; /* copy assignment */
    /* ���׳��쳣���ƶ����캯�����ƶ���ֵ�����������Ϊnoexcept */
    Zoo &operator=(const Zoo &&) = delete; /* move assignment */


    /* һ�㺯������ʹ��=default ����=delete */
    // һ�㺯������ʹ��=default��=delete?
    //    void fun1()= default; // error: ��void Zoo::fun1()�� cannot be defaulted
    void fun1() = delete; // compile ok
    // ������������ʹ��=default��=delete?
    //    ~Zoo()= delete;   // ok,�������ʹ��Zoo object����
    ~Zoo() = default;

    // �����ó�=delete����ʹ�����κκ�������,��=default������ʹ������ͨ������
    // ���������뵽=0,=0ֻ������virtual funciton��

private:
    int a;
    int b;
};

class Empty
{
};

// �ȼ���  ������������Ĭ�ϰ汾��������public��inline
class Empty1
{
public:
    Empty1() {}

    Empty1(const Empty1 &rhs) {}
    ~Empty1() {}
};

// no-copy
// copy ctor��copy assignment��delete��
struct NoCopy
{
    NoCopy() = default;
    NoCopy(const NoCopy &) = delete;
    NoCopy &operator=(const NoCopy &) = delete;
    ~NoCopy() = default;
};

// no-dtor
struct NoDtor
{
    NoDtor() = default;
    ~NoDtor() = delete;
};
// ��no-copy�ĸĽ� ��copy ctor��copy assignment �ŵ�private ,���ǿ��Զ�member��friend����
// boost::noncopyable ���õ���PrivateCopy
class PrivateCopy
{
private:
    PrivateCopy(const PrivateCopy &){}

    PrivateCopy &operator=(const PrivateCopy &){ return *this;}

public:
    PrivateCopy() = default;

    ~PrivateCopy(){}
};

// �̳��˵Ķ�ӵ��PrivateCopy����
class Foo : public PrivateCopy
{
};

int main()
{
    Zoo z;
    Zoo z1(1, 2);
    //    Zoo z2=z;   // error copy ctor delete
    z = z1;
    complex<int> a; // �ڲ�����ָ��Ŀ��Բ���д big three û������ ��copy ctor��copy assignmetn ����ʹ��=default,û���Լ�д
    string s;       // �ڲ���ָ�����big five

    //    NoDtor n;  //error no-dtor ���ܹ��Զ�delete
    //    NoDtor *p=new NoDtor;   // ok
    //    delete p;   // error no-dtor ���ܹ�delete
    Foo foo;
    Foo foo1;
    //    foo = foo1;   // �̳��˵Ķ�ӵ��PrivateCopy����
    system("pause");
    return 0;
}
