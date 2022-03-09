#include <iostream>
#include <complex>
#include <vector>

using namespace std;

/* Rvalue references �����Ҫ�Ŀ��� ���������ֱ���һ����ֵ�����ֱ߶������͵���ֱ߶��󣬶�����Ҫ���·����ڴ� ǳcopy */

int foo() { return 5; }

class Foo
{
    Foo() = default;
    Foo(const Foo &foo) = default;
    Foo(Foo &&foo) noexcept {}
};

/* �жϵ�������һ������ */
void process(int &i)
{
    cout << "��ֵ����" << endl;
}
void process(int &&i)
{
    cout << "��ֵ����" << endl;
}
void UnPerfectForward(int &&i)
{
    cout << "forward(int&& i)" << endl;
    process(i);
}
// std::forward()ʵ�־�����������
void PerfectForward(int &&i)
{
    cout << "forward(int&& i)" << endl;
    process(static_cast<int &&>(i));
}

// Lvalue: ����
// Rvalue: ��ʱ������Ǹ���ֵ,��ֵ�����Է������
int main()
{
    int a = 9, b = 4;

    a = b;
    b = a;
    //    a+b=42;// error Rvalue

    string s1("hello");
    string s2("world");
    s1 + s2 = s2;    // ok
    string() = "ok"; // ok

    cout << "s2:" << s1 + s2 << endl;
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;

    complex<int> c1(3, 8), c2(1, 0);
    c1 + c2 = complex<int>(3, 4);        // ok
    complex<int>() = complex<int>(1, 2); // ok

    int x = foo();
    //    int *p=&foo(); //error!  Rvalue������ȡ��ַ
    //    foo()=7;  // error
    // Rvalue references
    //    vector<Foo> vec;
    //    vec.insert(vec.begin(), Foo());  // Rvalue references and Move Semantics
    //  ԭ�����������
    //  iterator insert(const_iterator __position, const value_type& __x);
    // �����������Move Semantics
    //  iterator insert(const_iterator __position, value_type&& __x)        // Ȼ��ת����Foo(Foo&& foo)
    //  { return emplace(__position, std::move(__x)); }
    // Foo()�����ʱ����Ϊ��ֵ����insert��move assignmentȻ���ٽ���Foo��move ctor���м��п��ܻᶪʧһЩ��Ϣ��

    int aa = 1;
    process(aa);       // L
    process(1);        // R
    process(move(aa)); // R

    UnPerfectForward(2);        // ϣ��ͨ��ת�����õ�����ֵ���뺯��,���ǵ��õ�����ֵ���� ����Ǹ�Unperfect Forwarding
    UnPerfectForward(move(aa)); // ͬ��
    // ��������Perfect Forwarding?
    // Ϊ���ݼ���static_cast<int &&>ǿת����ֱ��ʹ��std::forward()
    PerfectForward(2);
    PerfectForward(move(aa));

    system("pause");
    return 0;
}
