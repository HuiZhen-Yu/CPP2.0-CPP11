#include <cstring>
#include <iostream>

using namespace std;

template <typename T>
T compareMax(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}
/* ģ����ػ� */
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
    cout << "ģ�庯��" << endl;
}
/* ģ��ȫ�ػ� */
template <>
void mycout<int ,double>(int a,double b)
{
    cout<<"ģ��ȫ�ػ�"<<endl;
}
/* ����������ƫ�ػ� ��������Ĵ����Ǵ���� */
// template<typename T2>
// void mycout<int ,T2>(int a,T2 b)
// {
    
//     cout<<"ģ��ƫ�ػ�"<<endl;
// }

int main(int argc, char **argv)
{
    cout << compareMax(1, 2) << endl;
    cout << compareMax("asda", "qweq") << endl;
    system("pause");
    return 0;
}
