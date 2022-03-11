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
   /*  重载强制类型转换运算符时，不需要指定返回值类型，因为返回值类型是确定的，就是运算符本身代表的类型 */
    operator int() { return int(r); }
    operator double() { return 2 * 3.14 * r; }
    operator float() { return (float)3.14 * r * r; }
};

int main()
{
    Circle c(2.3, 3.4, 2.5);
    int r = c;              //调用operator int()，将Circle类型转换成int
    double length = c;      //调用operator double()，转换成double
    float area = c;         //调用operator float()，将Circle类型转换成float
    double len = (double)c; //将Cirlce类型对象强制转换成double
    cout << r << endl;
    cout << length << endl;
    cout << len << endl;
    cout << area << endl;
    system("pause");
}