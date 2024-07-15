#include<iostream>
using namespace std;
class  time{
    int hr,min,sec;
    public: 
    friend istream &operator >>(istream&,time &);
        friend ostream &operator <<(ostream&,time &);
    time operator+(time t3){
        time temp;
        temp.sec=sec+t3.sec;

        temp.min=min+t3.min+temp.sec/60;
        temp.sec=temp.sec%60;
        temp.hr=hr+t3.hr+temp.min/60;
        temp.min=temp.min%60;
        return temp;

    }
    float operator<<(time t){
        float first=sec+min*60+hr*60*60;
        float second=t.sec+t.min*60+hr*60*60;
        return first<second;
    }

};
     istream &operator >>(istream &input,time &t){
        cout<<"Enter hours,minutes and seconds"<<endl;
        input>>t.hr>>t.min>>t.sec;
        return input;
     }
ostream& operator<<(ostream& output, time& t) {
    output << t.hr << ":" << t.min << ":" << t.sec;
    return output;
}
     int main(){
        time t1,t2,t3;
        cin>>t1;
        cin>>t2;
        if(t1<<t2)
        cout<<"First time is less than second time"<<endl;
        else
        cout<<"first time is greater than second time"<<endl;
        t3=t1+t2;
        cout<<"After addition:"<<endl;
        cout<<t3;
        return 0;
     }
    

