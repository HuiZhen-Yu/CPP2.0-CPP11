#include <iostream>

using namespace std;

template <typename T, int MAXNUM>
class Stack
{
private:
    T elems[MAXNUM];
    int cur = -1;

public:
    Stack() = default;
    void init()
    {
        cur = -1;
    }
    bool isfull()
    {
        if (cur >= MAXNUM - 1)
            return true;
        return false;
    }
    bool isempty()
    {
        if (cur == -1)
            return true;
        return false;
    }

    void push(T);
    T pop();
};

template <typename T, int MAXNUM>
void Stack<T, MAXNUM>::push(T e)
{
    if (!isfull())
    {
        elems[++cur] = e;
    }
    else
    {
        cout << "stack is full!! " << endl;
    }
}

template <typename T, int MAXNUM>
T Stack<T, MAXNUM>::pop()
{
    if (!isempty())
    {
        return elems[cur--];
    }
    else
    {
        cout << "stack is empty!!" << endl;
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    Stack<int, 8> s1;
    s1.init();
    int i;
    for (i = 1; i < 11; i++)
        s1.push(i);
    for (i = 1; i < 11; i++)
        cout << s1.pop() << "\t";
    cout << endl;
    system("pause");
    return 0;
}