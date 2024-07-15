// To write a C++ program to overload all relational operators to compare
// US currency with Nepalese currency. Use conversion rate $1=NRs
// 101.36(Note: make two classes to represent each currency)

#include <iostream>
using namespace std;
#define exchangerate 101.36

class nepalcurrency
{
    float amount;

public:
    nepalcurrency(float amt = 0) {
         amount = amt; 
         }

    void read()
    {
        cout << "Enter nrp amount: " << endl;
        cin >> amount;
    }

    float displayamount() {
         return amount;
          }
};

class uscurrency
{
    float amount;

public:
    uscurrency(float amt = 0) { amount = amt; }

    void inputAmount()
    {
        cout << "Enter usd amount: " << endl;
        cin >> amount;
    }

    int operator==(nepalcurrency n1)
    {
        
        if (n1.displayamount() == amount * exchangerate)
            return 1;
        else
            return 0;
    }

    int operator>(nepalcurrency n1)
    {
        if (amount * exchangerate > n1.displayamount())
            return 1;
        else
            return 0;
    }

    int operator>=(nepalcurrency n1)
    {
        if (amount * exchangerate >= n1.displayamount())
            return 1;
        else
            return 0;
    }

    int operator<(nepalcurrency n1)
    {
        if (amount * exchangerate < n1.displayamount())
            return 1;
        else
            return 0;
    }

    int operator<=(nepalcurrency n1)
    {
        if (amount * exchangerate <= n1.displayamount())
            return 1;
        else
            return 0;
    }

    int operator!=(nepalcurrency n1)
    {
        if (amount * exchangerate != n1.displayamount())
            return 1;
        else
            return 0;
    }
};

int main()
{
    nepalcurrency n1(107.36);
    uscurrency u1(2.5);

    if (u1 >= n1)
        cout << "USD is greater than npr";
    else
        cout << "npr is greater than usd";
    

    return 0;
}