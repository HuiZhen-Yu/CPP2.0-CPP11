#include <iostream>
#include <cstring>

using namespace std;

/* Ա��������Ϣ */
struct Person
{
    double salary;
    char *Name;
};

class SalaryManage
{
private:
    Person *employ; /* ���Ա����Ϣ������ */
    int max;        /* �����±��Ͻ�궨 */
    int cur;        /* �����е�ʵ������ */
public:
    SalaryManage(int Max = 0)
        : max(Max), cur(0), employ(new Person[max])
    {
    }
    /* ȡ���е�һ��ֵ��ֵ������������ */
    /*     double &operator[](const char *Name)
        {
            Person *p;
            for (p = employ; p < employ + cur; p++)
            {
                if (strcmp(p->Name, Name) == 0)
                    return p->salary;
            }
            p = employ + cur++;
            p->Name = new char[strlen(Name) + 1];
            strcpy(p->Name, Name);
            p->salary = 0;
            return p->salary;
        }
     */
    double &operator[](const char *Name)
    {
        Person *employ = nullptr;
        for (employ = this->employ; employ < this->employ + cur; employ++)
            if (strcmp(employ->Name, Name) == 0)
                return employ->salary;
        employ = this->employ + cur++;
        employ->Name = new char[strlen(Name) + 1];
        strcpy(employ->Name, Name);
        employ->salary = 0;
        return employ->salary;
    }

    Person &operator[](unsigned n)
    {
        if (n < this->cur)
            return employ[n];
        else
            throw 2;
    }
    
    void display()
    {
        for (int i = 0; i < this->cur; i++)
        {
            cout << employ[i].Name << " " << employ[i].salary << endl;
        }
    }
    ~SalaryManage()
    {
        for (Person *p = employ; p < employ + cur; p++)
            delete [] p->Name;
        delete [] employ;
    }
};

int main(int argc, char **argv)
{
    try
    {
        SalaryManage s(3);
        s["����"] = 12;
        s["����"] = 34;
        s["��������"] = 56;
        cout << s[3].salary << endl;
    }
    catch (int a)
    {
        if (a == 2)
            cout << "���ݳ�����Χ" << endl;
    }

    system("pause");
    return 0;
}