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
    os << s.name << "\t"; //�������
    os << s.id << "\t";   //������֤��
    os << s.age << endl;  //�������
    return s;
}
Sales &operator>>(istream &is, Sales &s)
{
    cout << "�����Ա�����������֤�ţ�����" << endl;
    is >> s.name >> s.id >> s.age;
    return s;
}
int main(int argc, char **argv)
{
    Sales s1("�ſ�", "214198012111711", 40); // L1
    cout << s1;                              // L2
    cout << endl;                            // L3
    cin >> s1;                               // L4
    cout << s1;                              // L5
    system("pause");
    return 0;
}
