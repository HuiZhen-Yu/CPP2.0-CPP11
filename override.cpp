#include <iostream>

using namespace std;

class Base
{
public:
    Base();
    virtual void func() {}
};

class Derivered : public Base
{
    /* error: virtual void Derivered::func(int) marked override, but does not override */
    // virtual void func(int) override {}
};

/**
 * override�����麯���������virtual void func(int)ʵ���ϲ�����д������麯�������Ƕ���һ���µ��麯����
 * ���ǵı�������д�麯����������overrride��ʱ��,����д���������ᱨ��
 * ��������������override�Ļ�����ᱨ����ʾ�����˱���������ȷʵҪ��д����д���ˣ�û����д�����Ǿͱ�����,
 * �������ܸ����Ƕ��麯������д�����!
 */
int main(int argc, const char **argv)
{
    system("pause");
    return 0;
}
