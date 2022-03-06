#include <iostream>
#include <array>
using namespace std;

// ��������Object��˵:
// const��δ���ֳ������ڳ���(��������Ĵ�С���ڳ�������ڼ����Ҫȷ��)�������ڳ���(�ڳ������й����в��ܱ��޸ĵĳ���)
// constexpr�޶����˱����ڳ���
// constexpr���ã��Ż�!Ч��!
// constexpr���εĺ���������ֵ��һ���Ǳ����ڳ�����It is not a bug, it is a feature.
// const���ε������ͣ�constexpr���ε����������ֵ���Ƕδ��롣
/**
 * constexpr���εĺ������򵥵���˵������䴫��Ĳ��������ڱ���ʱ�ڼ����������ô��������ͻ��������ʱ�ڵ�ֵ��
 * ���ǣ�����Ĳ�����������ڱ���ʱ�ڼ����������ôconstexpr���εĺ����ͺ���ͨ����һ���ˡ���
 * @param i
 * @return i + 10
 */
/* �����йر����������������ڳ��������ݿ��Բ��գ�https://zhuanlan.zhihu.com/p/250238866 */
constexpr int foo(int i)
{
    return i + 10;
}

int main()
{
    int i = 10;
    /* OK */
    std::array<int, foo(2)> arr;

    /* Call is Ok */
    foo(i);
    /* error: the value of ��i�� is not usable in a constant expression */
    // std::array<int, foo(i)> arr1;
    system("pause");
    return 0;
}