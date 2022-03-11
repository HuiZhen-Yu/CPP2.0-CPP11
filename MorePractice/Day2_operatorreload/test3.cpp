#include <iostream>
using namespace std;

class Circle
{
private:
    double x, y, r;

public:
    Circle(double x1, double y1, double z1)
        : x(x1), y(y1), r(z1)
    {
    }
   /*  ����ǿ������ת�������ʱ������Ҫָ������ֵ���ͣ���Ϊ����ֵ������ȷ���ģ������������������������ */
    operator int() { return int(r); }
    operator double() { return 2 * 3.14 * r; }
    operator float() { return (float)3.14 * r * r; }
};

int main()
{
    Circle c(2.3, 3.4, 2.5);
    int r = c;              //����operator int()����Circle����ת����int
    double length = c;      //����operator double()��ת����double
    float area = c;         //����operator float()����Circle����ת����float
    double len = (double)c; //��Cirlce���Ͷ���ǿ��ת����double
    cout << r << endl;
    cout << length << endl;
    cout << len << endl;
    cout << area << endl;
    system("pause");
}