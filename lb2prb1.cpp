#include<iostream>
using namespace std;
class second;
class first{
    int x;
    public:
    first (){}
    friend int swap (first,second);
};
class second{
    int y;
    public:
    second (){}
     friend int swap (first,second);
};
void swap (first f,second s){
    int temp;
    temp=f.x;
    f.x=s.y;
    s.y=temp;
    
}
int main(){
    int a(5),b(4);
    cout<<"before swapping a= "<<a<<"b= "<<b<<endl;
     swap(a,b);
    cout<<"After swapping a= "<<a<<"b= "<<b<<endl;
    return 0;
   
}