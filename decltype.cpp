#include <iostream>
#include <map>
#include <set>

using namespace std;

/* 1��used to declare return types �������� */

/**
 * c++2.0֮ǰ�Ǳ��벻������
 * template <typename T1,typename T2>
 * decltype(x+y) add(T1 x,T2 y);
 */

/* �������಻������2.0֮������������������auto�ݶ������淵������Ϊdecltype(x+y) β�÷��������ͣ�Ҳ����lambda�������� */

template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y)
{
    return x + y;
}

class Person
{
public:
    string firstname;
    string lastname;
};

int main(int argc, char **argv)
{
    /* 1. used to declare return types */
    cout << add(1, 2) << endl;

    /* 2. ģ��Ԫ��̣�������һ��ģ�庯�������ȡ������value_type,����Ͳ���װ�ˣ�ֱ��д��main�������� ��ñ��ʽ��type���е���typeof() */
    map<string, float> coll;
    decltype(coll)::value_type m{"as", 1}; /* value_typeΪpair<string,int> m */
    cout << m.first << " " << m.second << endl;

    /* 3. use to pass the type of a lambda */
    auto cmp = [](const Person &p1, const Person &p2)
    {
        return p1.lastname < p2.lastname;
    };

    /**
     *  ����lambda����������ֻ��object�����������ܹ�д���������ͣ�����ʱ�����Ҫ֪�����ǵ����ͣ�Ҫ�����type����Ҫ������
     * decltype set<Person,decltype(cmp)> col(cmp);
     */

    system("pause");
    return 0;
}