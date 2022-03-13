#include <iostream>
#include <cstring>

using namespace std;
class Sales
{
private:
    char name[10];
    char id[18];
    int age;

public:
    Sales(const char *Name, const char *ID, int Age);
    friend Sales &operator<<(ostream &os, Sales &s);
    friend Sales &operator>>(istream &is, Sales &s);
};

Sales::Sales(const char *Name, const char *ID, int Age)
{
    strcpy(name, Name);
    strcpy(id, ID);
    age = Age;
}

Sales &operator<<(ostream &os, Sales &s)
{
    os << s.name << "\t"; //输出姓名
    os << s.id << "\t";   //输出身份证号
    os << s.age << endl;  //输出年龄
    return s;
}
Sales &operator>>(istream &is, Sales &s)
{
    cout << "输入雇员的姓名，身份证号，年龄" << endl;
    is >> s.name >> s.id >> s.age;
    return s;
}
int main(int argc, char **argv)
{
    Sales s1("杜康", "214198012111711", 40); // L1
    cout << s1;                              // L2
    cout << endl;                            // L3
    cin >> s1;                               // L4
    cout << s1;                              // L5
    system("pause");
    return 0;
}
