#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    int j(); /* 0 */
    int *p;
    int *q(); /* nullptr */

    /* error: narrowing conversion  */
    // int x1{0.5};

    /* ����������initializer_list˽�й���֮ǰ��������׼����array(arrayͷ)��len�����ݸ��ù��죬��û���ں����array */
    /* ָ��ָ��array��copyֻ��ǳcopy�����������������������������ֵ insert() max() min() */

    cout << max({1, 2, 3}) << endl;
    system("pause");
    return 0;
}