#include <iostream>
#include <cstring>
using namespace std;

class STRING
{
private:
    char *str;
    int len;

public:
    STRING() : str(nullptr), len(0) {}

    STRING(char *s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    STRING(const STRING &other)
    {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }

    ~STRING()
    {
        delete[] str;
    }

    STRING operator=(STRING &other)
    {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
        return *this;
    }

    STRING operator+(STRING other)
    {
        STRING temp;
        temp.len = len + other.len;
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        return temp;
    }

    bool operator==( STRING &other) 
    {
        return strcmp(str, other.str) == 0;
    }

    void display() 
    {
        if (str)
        {
            cout << str << endl;
        }
        else
        {
            cout << "Empty string" << endl;
        }
    }
};

int main()
{
    STRING s1("Hello");
    STRING s2(" World");
    STRING s3 = s1 + s2;

    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();
    cout << "s1 + s2: ";
    s3.display();

    STRING s4;
    s4 = s1;

    cout << "s4 after assignment: ";
    s4.display();

    if (s1 == s4)
    {
        cout << "s1 is equal to s4" << endl;
    }
    else
    {
        cout << "s1 is not equal to s4" << endl;
    }

    return 0;
}