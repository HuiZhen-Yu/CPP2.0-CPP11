#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
/**
 * [introducter](optional)mutable throwSpec->retType{}
 * mutable����[]�ܹ�����д��mutable throwSpec retType����ѡ��ģ�ֻҪ��һ�����ھ͵�д()
 * retType ��������
 * (�Ų���)
 * []������ı��� passed by value or referrence
 */

class UnNamedLocalFunction
{
private:
    int localVar;

public:
    UnNamedLocalFunction(int var) : localVar(var) {}
    bool operator()(int val)
    {
        return val == localVar;
    }
};

class Person
{
public:
    string firstname;
    string lastname;
};

class LambdaFunctor
{
public:
    LambdaFunctor(int a, int b)
        : m_a(a), m_b(b) {}
    bool operator()(int n) const
    {
        return m_a < n && n < m_b;
    }

private:
    int m_a;
    int m_b;
};

class X
{
private:
    int __x, __y;

public:
    X(int x, int y) : __x(x), __y(y) {}
    int operator()(int a) { return a; }
    int f()
    {
        /**
         *  ����lambda���ﾳ�ǳ�Ա���� X::f
         *  ����[=]��[&]����ʽ��lambda���ʽ����ֱ��ʹ��thisָ��
         */

        /* X::operator()(this->x+(*this).y) */
        return ([&]() -> int
                { return operator()(this->__x + __y); }());
    }
    int ff()
    {
        return [this]()
        { return this->__x; }();
    }
};

int main(int argc, char **argv)
{
    []
    {
        cout << "hello" << endl;
    }();

    auto I = []
    { cout << "hello" << endl; };
    I();
    int id = 0;
    /* ���ȿ���ǰ���id���û��mutable error��increment of read-only variable 'id' */
    auto f = [id]() mutable
    {
        cout << "id=" << id << endl;
        ++id;
    };

    id = 42;
    f();
    f();
    f();
    cout << id << endl;
    /**
     * ������lambda���൱��
     * class Funcitor{
     * private:
     *      int id;
     * public:
     *      void operator(){
     *          cout<<"id="<<id<<endl;
     *          ++id;
     *          }
     * };
     * Functor f;
     */

    int id1 = 0;
    // �Ӳ���mutableûӰ��,�Ҵ�����ֻҪ����id1���޸���,�ͻ�ʹ���޸ĺ��ֵ���в���
    auto f1 = [&id1]()
    {
        cout << "id1=" << id1 << endl;
        ++id1;
    };
    id1 = 42;
    f1(); // 42
    f1(); // 43
    f1(); // 44
    cout << id1 << endl;

    // �����뷵��
    int id2 = 0;
    auto f2 = [&id2](int &param)
    {
        cout << "id2=" << id2 << endl;
        ++id2;
        ++param;
        cout << "param=" << param << endl;
        static int x = 5;
        return id2;
    };
    int param = 1;
    f2(param);
    cout << "param=" << param << endl;

    // [=] =��ʾĬ����by value�����ⲿ���б���
    // [&] &��ʾĬ����by reference�����ⲿ���б���
    auto f3 = [&]()
    {
        cout << "id=" << id << endl;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f3();

    // һ���ִ�����, ���ഫֵ
    cout << "id=" << id << endl;
    auto f4 = [=, &id]() { // =�����Է���&id����
        cout << "id=" << id << endl;
        id++;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f4();

    // һ���ִ�ֵ,���ഫ����
    cout << "id=" << id << endl;
    auto f5 = [&, id]() { // &�����Է���id����
        cout << "id=" << id << endl;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f5();
    // this ָ��
    X x_(1, 2);
    cout << "x_.f()=" << x_.f() << endl;   // 1+2=3
    cout << "x_.ff()=" << x_.ff() << endl; // 1

    // ����lambda�����ȼ���������UnNamedLocalFunction
    int tobefound = 5;
    auto lambda1 = [tobefound](int val)
    {
        return val == tobefound;
    };
    bool b1 = lambda1(5);
    UnNamedLocalFunction lambda2(tobefound);
    bool b2 = lambda2(5);
    cout << b1 << " " << b2 << endl;

    auto ll1 = [](int x) -> int
    {
        return x + 10;
    };
    // lambda ��������
    function<int(int x)> ll = [](int x) -> float
    {
        return x + 10.1;
    };
    auto lz = [](int x) -> float
    {
        return x + 10.1;
    };
    cout << ll(1) << endl;
    cout << lz(1) << endl;

    // decltype+lambda
    // �ȴ�С
    function<bool(const Person &p1, const Person &p2)> cmp = [](const Person &p1, const Person &p2)
    {
        return p1.lastname < p2.lastname;
    };

    // ����lambda,��������ֻ��object,���������ܹ�д���������ͣ�����ʱ����Ҫ֪����������,Ҫ�����type,��Ҫ������decltype
    set<Person, decltype(cmp)> col(cmp);

    // Ҫ����lambda��������ͣ�����ʹ��template����auto�����Զ��Ƶ���
    // �����Ҫ֪�����ͣ�����ʹ��decltype�����磬��lambda������Ϊ�������������������������������߹�ϣ������
    // ������������������decltype�ĵ������÷��е���������������һ��lambda������cmp��ʾ�������Ƚ�Person����Ĵ�С�����뵽Set������ȥ��
    // �������ұߵ�set�����Ķ��壬���Ǵ���Ĳ�����cmp�����캯��������Ҫ����ģ���cmp���ͣ�Set�ڲ���Ҫ����cmp���ͣ���
    // ���Ա���ʹ��decltype���Ƶ������͡�
    // �����û�����캯������cmp�����õ���Ĭ�ϵĹ��캯����Ҳ����set() : t(Compare()), ����ᱨ��, ���ڲ����������!
    // ��ΪCompare()ָ���ǵ���Ĭ�ϵ�lambda���캯������lambda����û��Ĭ�Ϲ��캯���͸�ֵ������

    vector<int> vec{5, 28, 50, 83, 70, 590, 245, 59, 24};
    int x = 30, y = 100;
    // ���������Ǻ�ǿ��ģ���װ������������Զ����׼�����Ϊ������Ҫд������������Ҫд������class�����ǲ�����ģ������ǷǱ��صģ�
    // ������Ҳ�鷳����Ҫȥ������ʹ�ã��������������ϢҲ���Ѻã��������ǲ���inline�ģ�Ч�ʻ��һЩ���㷨Ч�ʻ�������Ҫ�ģ���
    //    vec.erase(remove_if(vec.begin(), vec.end(), LambdaFunctor(x, y)), vec.end());
    //    for(auto i:vec) cout<<i<<" ";
    //    cout<<endl;
    // ��lambda��������������������⣬�����Ч����������������ܺõ�˵����������⣬��lambdaҪ�����࣬����һ������ֱ�ۡ�
    vec.erase(remove_if(vec.begin(), vec.end(), [x, y](int n)
                        { return x < n && n < y; }),
              vec.end());
    for_each(vec.begin(), vec.end(), [](int i)
             { cout << i << " "; });
    cout << endl;

    system("pause");
    return 0;
}