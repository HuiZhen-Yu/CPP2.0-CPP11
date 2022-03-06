#include <iostream>

using namespace std;

// non-explicit-one-argument ctor
class Fraction
{
public:
    // non-explicit-one-argument ctor ���԰ѱ�Ķ���ת��ΪFraction����
    Fraction(int num, int den = 1)
        : m_numerator(num), m_denominator(den) {}

    Fraction operator+(const Fraction &f)
    {
        return Fraction(this->m_numerator + f.m_numerator);
    }

    void getNumAndDen()
    {
        cout << m_numerator << " " << m_denominator << endl;
    }

private:
    int m_numerator;   // ����
    int m_denominator; // ��ĸ
};

// explicit-one-argument ctor
class Fraction1
{
public:
    // explicit-one-argument ctor �����԰ѱ�Ķ���ת��ΪFraction����
    explicit Fraction1(int num, int den = 1)
        : m_numerator(num), m_denominator(den) {}

    Fraction1 operator+(const Fraction1 &f)
    {
        return Fraction1(this->m_numerator + f.m_numerator);
    }

    void getNumAndDen()
    {
        cout << m_numerator << " " << m_denominator << endl;
    }

private:
    int m_numerator;   // ����
    int m_denominator; // ��ĸ
};

class P
{
public:
    P(int a, int b)
    {
        cout << "P(int a,int b)\n";
    }

    P(int a, int b, int c)
    {
        cout << "non-explicit P(int a,int b,int c)\n";
    }
    explicit P(int a, int b, int c, int d)
    {
        cout << "explicit P(int a,int b,int c,int d)\n";
    }
};

void fp(const P &)
{
}

int main()
{
    Fraction f(3, 5);
    Fraction ff = f + 3; // �Ὣ3ת��Ϊ(3,1)   ��ʽת��
    ff.getNumAndDen();

    // ������������������ʽת��,������ǰ�����explicit�ؼ���

    // c++2.0֮ǰexplicitֻ��ֹ"���ڵ�һʵ��"ת��
    // c++2.0֮��explicit���Խ���"���ʵ��"ת��
    //  Fraction1 f1(3,5);
    //  Fraction1 f2 = f1+3; // �Ὣ3ת��Ϊ(3,1)   ������ʽת��    error: no match for ��operator+�� (operand types are ��Fraction1�� and ��int��)
    //    f2.getNumAndDen();
    P p1 = {77, 5};
    P p2 = {77, 5, 89};
    //  P p3 = {77, 5, 89,99}; //error: converting to ��P�� from initializer list would use explicit constructor ��P::P(int, int, int, int)��
    system("pause");
    return 0;
}
