#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;

// iterator stl_iterator.h�����Դ�� ʹ��auto
template <typename _Iterator>
#if __cplusplus < 201103L
inline typename reverse_iterator<_Iterator>::difference_type
operator-(const reverse_iterator<_Iterator> &__x,
          const reverse_iterator<_Iterator> &__y)
#else

inline auto
operator-(const reverse_iterator<_Iterator> &__x,
          const reverse_iterator<_Iterator> &__y)
    -> decltype(__x.base - __y.base())

#endif
{
    return __y.base() - __x.base();
}

int main(int argc, char **argv)
{
    /* �������߱�ʵ���Ƶ� */
    auto i = 42;
    /* lambda �������� auto�ܹ��Զ��Ƶ�ʵ�� */
    auto ll1 = [](int x) -> int
    {
        return x + 10;
    };

    /* lambda �������� */
    function<int(int x)> ll = [](int x) -> int
    {
        return x + 10;
    };

    cout << ll(10) << endl;
    list<int> l{1, 2, 3};
    list<int>::iterator iterator;
    iterator = find(l.begin(), l.end(), 10);

    auto ite = find(l.begin(), l.end(), 11); // auto �ؼ���

    vector<int> vec;
    /* =====================range-based for statement========================= */
    for (auto elem : vec)
        cout << elem << endl;

    cout << endl;

    /* pass by reference */
    for (auto &elem : vec)
        cout << elem << endl;
    for (auto _pos = l.begin(), _end = l.end(); _pos != _end; ++_pos)
        cout << *_pos << " ";
    cout << endl;

    for (auto &elem : vec) // pass by reference
        elem *= 3;

    for (auto _pos = l.begin(), _end = l.end(); _pos != _end; ++_pos)
    {
        auto &elem = *_pos;
        elem *= 3;
    }

    cout << endl;

    vector<string> vs = {"hello", "world"};

/*  
    ����explicit�Ͳ���ת�� error
    for (const C &elem:vs) {
        
        }
    auto ���������ʹ���ɶ��ԡ����ܵò�����Ԥ������͡����decltype�����벻���Ľ��
    auto���ܵò�����Ԥ������ͣ���vector<bool>[]�ķ������͡�
 */
    vector<bool> v(true);
    auto var = v.at(0);
    cout << typeid(var).name() << endl;
    system("pause");
    return 0;
}