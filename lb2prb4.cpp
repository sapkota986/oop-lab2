#include<iostream>
using namespace std;
class time{
    int hours, minutes, seconds;
    public:
    time(){
        hours=0;
        minutes=0;
        seconds=0;

    }
    time(int hr, int min,int sec){
        hours=hr;
        minutes=min;
        seconds=sec;

    }
    time operator +(time &t){
        int totalSec = (hours + t.hours) * 3600 + (minutes + t.minutes) * 60 + (seconds + t.seconds);
        int h = totalSec / 3600;
        totalSec %= 3600;
        int m = totalSec / 60;
        int s = totalSec % 60;
        return time(h, m, s);
    }
    time operator -(time &t){
           int totalSec1 = hours * 3600 + minutes * 60 + seconds;
        int totalSec2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diffSec = totalSec1 - totalSec2;
        if(diffSec<0)
        {
            diffSec=-diffSec;
        }

        int h = diffSec / 3600;
        diffSec %= 3600;
        int m = diffSec / 60;
        int s = diffSec % 60;
        return time(h, m, s);
    }
    bool operator>(time t){
        if(hours>t.hours)
        return true;
        if(hours==t.hours&&minutes>t.minutes)
        return true;
    
      if (hours == t.hours && minutes == t.minutes && seconds > t.seconds)
            return true;
        return false;
    }
void display(){
    cout<<hours<<"::"<<minutes<<"::"<<seconds<<endl;
}

};
int main(){
    time time1(2,40,25);
    cout<<"the first time is:";
    time1.display();
    time time2(2,50,35);
    cout<<"the second time is:";

    time2.display();
    time time3=time1+time2;
    cout<<"the addition of two times are:";
    
    time3.display();
    time time4=(time2-time1);
    cout<<"the subtraction of two times are:";

         time4.display();
    cout<<" Is Time1>Time2:"<<(time1>time2?"yes":"No")<<endl;
    return 0;


}