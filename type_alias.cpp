#include <iostream>
#include <vector>

using namespace std;

// ��һ��ʹ��
// type alias
// �ȼ���typedef void(*func)(int, int);
using fun = void (*)(int, int);

void example(int, int) {}

// �ڶ���ʹ��
template <typename T>
struct Container
{
    using value_type = T; // �ȼ���typedef T value_type;
};

template <typename Cn>
void func2(const Cn &cn)
{
    typename Cn::value_type n;
}

// ������ʹ��
// alias template
template <typename CharT>
using string = basic_string<CharT, char_traits<CharT>>;
// �ȼ��� typedef basic_string<char>    string;

// ����:type alias�ȼ���typedef,û��ʲô��ͬ
// using �������÷���չ����:
// 1.using-directives
// using namespace std; or using std::cout;
// 2. using-declaration
// protected:
//    using _Base::_M_alloc;
// 3.c++2.0���� type alias and alias template
int main()
{
    fun fn = example; // ����ָ��
    return 0;
}