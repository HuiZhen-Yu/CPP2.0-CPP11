#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
    char s[20] = "this is a string";
    double digit = -36.96656;

    cout << setw(30) << left << setfill('*') << s << endl;
    cout << setw(30) << right << setfill('*') << s << endl;
    cout << dec << setprecision(5) << digit << endl;
    cout << dec << 15 << endl;

    // setbase(int x)���ý��ƺ󣬺������в������ǰ���������������㣡
    cout << setbase(10)<< setprecision(5) << 15 << endl;
    //��������,������2λ��Ч����
    float x = 6.6937;
    cout << float(int(x * 1000 + 0.5) / 1000.0) << endl;
    system("pause");
    return 0;
}