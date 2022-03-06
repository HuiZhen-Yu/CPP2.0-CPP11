#include <iostream>

using namespace std;

/* final关键字用于两个地方，第一个用在类，用于说明该类是继承体系下最后的一个类，不要其他类继承我，党继承时就会报错 */

class Base final{
    public:
    Base(){}
    virtual void func(){}
};

/* error: cannot derive from 'final'base 'base' in derived type 'Derivered' */
/* class Derivered:public Base{

}; */

/* 第二个用在虚函数，表示这个虚函数不能在被override，用override就会报错 */
class Base1{
    public:
    Base1(){}
    virtual void func() final{}
};

class Derivered1:public Base1{
    /* error: overriding final function 'virtual void Base1::func()' */
    /* virutal void func(){} */
};

int main(int argc,char **argv)
{
    system("pause");
    return 0;
}