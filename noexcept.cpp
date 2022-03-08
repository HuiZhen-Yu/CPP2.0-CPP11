#include <iostream>
#include <vector>

using namespace std;

/**
 * noexcept()�п��Լ�����
 * �쳣�ɴ��� a����b b�׳��쳣 aû����,�ͻ��׳��쳣
 * 1.�쳣�Ļش�����:����foo����׳��쳣��foo��������ϲ��׳��쳣��
 * ������ϲ�û�д���������terminate������terminate�����ڲ�����abort��ʹ�����˳�
 *
 * 2.��ʹ��vector deque���������ƶ�������ƶ���ֵ��ʱ��
 * ����ƶ�������ƶ���ֵû�м���noexcept��������������ʱ�򲻻����move constructor��
 * Ч�ʾͻ�ƫ�ͣ����Ժ�����Ҫ����noexcept������ʹ�á�
 */

class MemoryBlock
{
public:
    // Simple constructor that initializes the resource.
    explicit MemoryBlock(size_t length)
        : _length(length), _data(new int[length])
    {
        std::cout << "In MemoryBlock(size_t). length = "
                  << _length << "." << std::endl;
    }
    MemoryBlock()
    {
        _length = 0;
        _data = nullptr;
    }
    // Destructor.
    ~MemoryBlock()
    {
        std::cout << "In ~MemoryBlock(). length = "
                  << _length << ".";

        if (_data != nullptr)
        {
            std::cout << " Deleting resource.";
            // Delete the resource.
            delete[] _data;
        }

        std::cout << std::endl;
    }

    // Copy constructor.
    MemoryBlock(const MemoryBlock &other)
        : _length(other._length), _data(new int[other._length])
    {
        std::cout << "In MemoryBlock(const MemoryBlock&). length = " << other._length << ". Copying resource." << std::endl;

        std::copy(other._data, other._data + _length, _data);
    }
    // Move constructor.
    MemoryBlock(MemoryBlock &&other)
        : _data(nullptr), _length(0)
    {
        std::cout << "In MemoryBlock(MemoryBlock&&). length = "
                  << other._length << ". Moving resource." << std::endl;

        // Copy the data pointer and its length from the
        // source object.
        _data = other._data;
        _length = other._length;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other._data = nullptr;
        other._length = 0;
    }

    // Copy assignment operator.
    MemoryBlock &operator=(const MemoryBlock &other)
    {
        std::cout << "In operator=(const MemoryBlock&). length = "
                  << other._length << ". Copying resource." << std::endl;
        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;

            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
        }
        return *this;
    }
    MemoryBlock &operator=(MemoryBlock &&other)
    {
        std::cout << "In operator=(MemoryBlock&&). length = "
                  << other._length << "." << std::endl;

        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;

            // Copy the data pointer and its length from the
            // source object.
            _data = other._data;
            _length = other._length;

            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }

    // Retrieves the length of the data resource.
    size_t Length() const
    {
        return _length;
    }

private:
    size_t _length; // The length of the resource.
    int *_data;     // The resource.
};

class Test
{
public:
    Test(const string &s = "hello world") : str(new string(s)) { cout << "Ĭ�Ϲ��캯��" << endl; };
    Test(const Test &t);
    Test &operator=(const Test &t);
    Test(Test &&t) noexcept;
    Test &operator=(Test &&t) noexcept;
    ~Test();

public:
    string *str;
};

Test::Test(const Test &t)
{
    str = new string(*(t.str));
    cout << "�������캯��" << endl;
}
Test &Test::operator=(const Test &t)
{
    cout << "������ֵ�����" << endl;
    return *this;
}
Test::Test(Test &&t) noexcept
{
    str = t.str;
    t.str = nullptr;
    cout << "�ƶ����캯��" << endl;
}
Test &Test::operator=(Test &&t) noexcept
{
    cout << "�ƶ���ֵ�����" << endl;
    return *this;
}
Test::~Test()
{
    cout << "��������" << endl;
}

MemoryBlock foo() noexcept(true)
{
    MemoryBlock c(2);
    return c;
}

int main()
{
    MemoryBlock a(20);
    MemoryBlock b(a);
    MemoryBlock c(std::move(a));
    MemoryBlock d;
    d = a;
    d = foo();
    MemoryBlock e = foo();

    // foo();
    // vector<int> vec;

    system("pause");
    return 0;
}
