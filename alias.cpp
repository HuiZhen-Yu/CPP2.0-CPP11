#include <iostream>
#include <vector>

using namespace std;

// �����Զ�alias template��ƫ�ػ���ȫ�ػ�
template <typename T>
using Vec = vector<T, allocator<T>>; // alias template using���÷�
//# define Vec<T> template<typename T> vector<T, allocator<T>> // ʹ�ú겻��

int main()
{
    Vec<int> col;
    // ���ʹ�ú������ᱻ�滻Ϊtemplate<typename int> vector<int, allocator<int>>  error ����������Ҫ��
    // typedef vector<int, allocator<int>> Vec;   // typedefҲ�޷�����,û��ָ��ģ�����
    system("pause");
    return 0;
}