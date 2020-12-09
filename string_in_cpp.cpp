// 
// Implement a string class suporting these functionalities:
// String s1("aaa");
// String s2 = "bbb";
// String s3(s2);
// String s4;
// s4 = s2;
// s3[2] = 'k';
//

#include <string.h>
#include <iostream>

using namespace std;

class String
{
public:
    String(const char *str = "Default");
    ~String()
    {
        delete[] m_str;
    }
    String(const String& other);
    String& operator=(const String& other);
    String& operator=(const char *str);

    char& operator[](size_t index)
    {
        return (m_str[index]);
    }

    char *Cstr() const
    {
        return (m_str);
    }

    size_t GetLength() const
    {
        return (m_length);
    }

private:
    char *m_str;
    size_t m_length;
};

String::String(const char *str)
{
    m_length = strlen(str);
    m_str = new char[m_length + 1];
    memcpy(m_str, str, m_length + 1);
}

String::String(const String& other)
{
    m_length = other.m_length;
    m_str = new char[m_length + 1];
    memcpy(m_str, other.m_str, m_length + 1);
}

String& String::operator=(const String& other)
{
    char *buffer = new char[other.m_length + 1];
    memcpy(buffer, other.m_str, other.m_length + 1);

    delete[] m_str;
    m_length = other.m_length;
    m_str = buffer;
    
    return (*this);
}

String& String::operator=(const char *str)
{
    char *buffer = new char[strlen(str) + 1];
    memcpy(buffer, str, strlen(str) + 1);

    delete[] m_str;
    m_length = strlen(str) + 1;
    m_str = buffer;

    return (*this);
}

ostream& operator<<(ostream &out, const String& other)
{
    return (out << other.Cstr());
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
    system("clear");
    cout << "\n" << endl;

    String s1("aaa");
    cout << "s1 should be 'aaa': " << s1 << endl;

    String s2 = "bbb";
    cout << "s2 should be 'bbb': " << s2 << endl;

    String s3(s2);
    cout << "s3 should be 'bbb' as well: " << s3 << endl;

    String s4;
    cout << "s4 should be 'Default': " << s4 << endl;

    s4 = s2;
    cout << "After the change s4 should be 'bbb': " << s4 << endl;

    s3[2] = 'k';
    cout << "After the change s3 should be 'bbk': " << s3 << endl;

    return (0);
}