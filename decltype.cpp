#include <iostream>
#include <map>
#include <set>

using namespace std;

/* 1、used to declare return types 返回类型 */

/**
 * c++2.0之前是编译不出来的
 * template <typename T1,typename T2>
 * decltype(x+y) add(T1 x,T2 y);
 */

/* 编译器编不出来在2.0之后变成下面的这个，先用auto暂定，后面返回类型为decltype(x+y) 尾置返回类类型，也用在lambda函数里面 */

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

    /* 2. 模板元编程，例如在一个模板函数或类获取容器的value_type,这里就不封装了，直接写在main函数里面 获得表达式的type，有点像typeof() */
    map<string, float> coll;
    decltype(coll)::value_type m{"as", 1}; /* value_type为pair<string,int> m */
    cout << m.first << " " << m.second << endl;

    /* 3. use to pass the type of a lambda */
    auto cmp = [](const Person &p1, const Person &p2)
    {
        return p1.lastname < p2.lastname;
    };

    /**
     *  对于lambda，我们往往只有object，很少有人能够写出它的类型，而有时候就需要知道他们的类型，要获得期type，就要借助其
     * decltype set<Person,decltype(cmp)> col(cmp);
     */

    system("pause");
    return 0;
}