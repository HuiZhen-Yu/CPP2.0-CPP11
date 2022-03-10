#include <cstring>
#include <iostream>

using namespace std;

template <typename T>
T compareMax(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}
/* 模板的特化 */
template <>
const char *compareMax<const char *>(const char *s1, const char *s2)
{
    cout << "[for debug]"
         << " call compareMax template" << endl;
    return strcmp(s1, s2) >= 0 ? s1 : s2;
}

template <typename T1, typename T2>
void mycout(T1 a, T2 b)
{
    cout << "模板函数" << endl;
}
/* 模板全特化 */
template <>
void mycout<int ,double>(int a,double b)
{
    cout<<"模板全特化"<<endl;
}
/* 函数不存在偏特化 所以下面的代码是错误的 */
// template<typename T2>
// void mycout<int ,T2>(int a,T2 b)
// {
    
//     cout<<"模板偏特化"<<endl;
// }

int main(int argc, char **argv)
{
    cout << compareMax(1, 2) << endl;
    cout << compareMax("asda", "qweq") << endl;
    system("pause");
    return 0;
}
