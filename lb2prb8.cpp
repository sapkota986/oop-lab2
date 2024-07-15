#include <iostream>
#include <cmath>
using namespace std;

class DateTime
{
    int hours, min, sec, year, month, day;

public:
    DateTime(int y, int mth, int d, int h, int m, int s) : hours(h), min(m), sec(s), year(y), month(mth), day(d) {}

    int TimeDifference(DateTime &dt)
    {
        int yearDiff, monthDiff, dayDiff, hourDiff, minDiff, secDiff;

        yearDiff = abs(year - dt.year);
        if (month < dt.month && year > dt.year)
        {
            yearDiff--;
            monthDiff = 12 + month - dt.month;
        }
        else
            monthDiff = abs(month - dt.month);
        if (day < dt.day && month > dt.month)
        {
            monthDiff--;
            dayDiff = 30 + day - dt.day;
        }
        else
            dayDiff = abs(day - dt.day);
        if (hours < dt.hours && day > dt.day)
        {
            dayDiff--;
            hourDiff = 24 + hours - dt.hours;
        }
        else
            hourDiff = abs(hours - dt.hours);
        if (min < dt.min && hours > dt.hours)
        {
            hourDiff--;
            minDiff = 60 + min - dt.min;
        }
        else
            minDiff = abs(min - dt.min);
        if (sec < dt.sec && min > dt.min)
        {
            minDiff--;
            secDiff = 60 + sec - dt.sec;
        }
        else
            secDiff = abs(sec - dt.sec);

        return yearDiff * 365 * 24 * 60 * 60 + monthDiff * 30 * 24 * 60 * 60 + dayDiff * 24 * 60 * 60 + hourDiff * 60 * 60 + minDiff * 60 + secDiff;
    }

    void inputDateTime()
    {
        cout << "Enter the date and time in the format (yy mm dd hh min ss): ";
        cin >> year >> month >> day >> hours >> min >> sec;
    }
};

class ParkingManagement
{
    const float chargePerHour = 0.5;
    const float chargePerDay = 8;
    const float minCharge = 2;

    DateTime entry, exit;
    static int carCount;

public:
    ParkingManagement(DateTime &e, DateTime &ex) : entry(e), exit(ex)
    {
    }

    float calculateFee()
    {
        int timeDiff = entry.TimeDifference(exit);
        float fee = 0;
        if (timeDiff <= 3 * 60 * 60)
            fee = minCharge;
        else if (timeDiff <= 24 * 60 * 60)
            fee = minCharge + ceil((timeDiff - 3 * 60 * 60) / (60 * 60)) * chargePerHour;
        else
            fee = chargePerDay * floor(timeDiff / (24 * 60 * 60));
        return fee;
    }

    void displayFee()
    {
        cout << "The parking fee is: " << calculateFee() << endl;
    }

    void operator++()
    {
        carCount++;
    }

    void operator--()
    {
        carCount--;
    }

    static void getCarCount()
    {
        cout << "Number of cars in the garage: " << carCount << endl;
    }
};

int ParkingManagement::carCount = 0;

int main()
{

    DateTime entry(2024, 10, 20, 11, 30, 0);
    DateTime exit(2024, 10, 19, 18, 35, 0);
    // cout<<entry.TimeDifference(exit);

    ParkingManagement car1(entry, exit);
    car1.displayFee();
    ++car1;
    ParkingManagement::getCarCount();
    return 0;
}