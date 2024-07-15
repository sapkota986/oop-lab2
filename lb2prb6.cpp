#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 100;

class STRING {
private:
    char str[MAX_LENGTH];
    int length;

public:
    STRING() : length(0) {
        str[0] = '\0';
    }

    STRING(const char* s) {
        strncpy(str, s, MAX_LENGTH - 1);
        str[MAX_LENGTH - 1] = '\0';
        length = strlen(str);
    }

    STRING(const STRING& other) {
        strncpy(str, other.str, MAX_LENGTH);
        str[MAX_LENGTH - 1] = '\0';
        length = strlen(str);
    }

    STRING& operator = (STRING other) {
        strncpy(str, other.str, MAX_LENGTH);
        str[MAX_LENGTH - 1] = '\0';
        length = strlen(str);
        return *this;
    }

    STRING operator + (STRING other) {
        STRING temp;
        strncpy(temp.str, str, MAX_LENGTH - 1);
        temp.str[MAX_LENGTH - 1] = '\0';
        strncat(temp.str, other.str, MAX_LENGTH - strlen(temp.str) - 1);
        temp.length = strlen(temp.str);
        return temp;
    }

    bool operator == (STRING other)  {
        return strcmp(str, other.str) == 0;
    }

    void display()  {
        cout << str << endl;
    }
};

int main() {
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

    if (s1 == s4) {
        cout << "s1 is equal to s4" << endl;
    } else {
        cout << "s1 is not equal to s4" << endl;
    }

    return 0;
}