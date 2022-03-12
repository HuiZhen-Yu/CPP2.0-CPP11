#include <iostream>
#include <cstring>

using namespace std;

struct mystr
{
    friend ostream &operator<<(ostream &os, const mystr &str);

private:
    char *str;

public:
    mystr(const char *strl)
        : str(new char[strlen(strl + 1)])
    {
        strncpy(str, strl, strlen(strl));
    }
    ~mystr()
    {
        delete[] str;
    }
};

ostream &operator<<(ostream &os, const mystr &str)
{
    os << str.str << endl;
    return os;
}

int main(int argc, char **argv)
{
    char *sPtr;
    const char *s = "hello";
    sPtr = new char[strlen(s) + 1];
    strncpy(sPtr, s, strlen(s));
    cout << sPtr << endl;
    delete[] sPtr;

    mystr str1(s);
    cout << str1;

    system("pause");
    return 0;
}