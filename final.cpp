#include <iostream>

using namespace std;

/* final�ؼ������������ط�����һ�������࣬����˵�������Ǽ̳���ϵ������һ���࣬��Ҫ������̳��ң����̳�ʱ�ͻᱨ�� */

class Base final{
    public:
    Base(){}
    virtual void func(){}
};

/* error: cannot derive from 'final'base 'base' in derived type 'Derivered' */
/* class Derivered:public Base{

}; */

/* �ڶ��������麯������ʾ����麯�������ڱ�override����override�ͻᱨ�� */
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