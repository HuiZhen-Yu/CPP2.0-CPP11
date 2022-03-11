#include <iostream>
#include <cmath>

using namespace std;

/* 时钟类 */
class Clock
{
private:
    int hh, mm, ss;

public:
    Clock(int h = 0, int m = 0, int s = 0)
        : hh(h), mm(m), ss(s)
    {
        if (!(h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60))
        {
            cout << "error!!" << endl;
            hh = 0;
            mm = 0;
            ss = 0;
        }
    }
    void operator()(int h, int m, int s)
    {
        hh = h;
        mm = m;
        ss = s;
    }
    void ShowTime()
    {
        cout << "time is : " << hh << " : " << mm << " : " << ss << endl;
    }

    Clock &operator++();
    Clock operator++(int);
};
/* 前缀++运算符 */
Clock &Clock::operator++()
{
    ++ss < 60 ? ss : (ss = 0, ++mm < 60 ? mm : (mm = 0, ++hh < 24 ? hh : hh = 0));
    return *this;
}

/* 后缀++运算符 */
Clock Clock::operator++(int)
{
    Clock old = *this;
    ++(*this);
    return old;
}

int main(int argc, char **argv)
{
    Clock myClock(23, 59, 59);
    cout << "初始化显示时间为:\t\t";
    myClock.ShowTime();

    cout << "执行myClock++后的时间为:\t";

    //先执行ShowTime()，输出myClock=23:59:59，
    //再执行myClock++，此时myClock=00:00:00
    (myClock++).ShowTime();

    cout << "执行++myClock后的时间为:\t";

    //先执行++myClock，此时myClock=00:00:01
    //再执行ShowTime()，输出myClock=00:00:01
    (++myClock).ShowTime();

    Clock t1(12, 10, 11);
    t1.ShowTime();
    t1.operator()(23, 20, 34);
    t1.ShowTime();
    t1(10, 10, 10);
    t1.ShowTime();
    system("pause");
    return 0;
}
