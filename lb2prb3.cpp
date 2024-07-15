#include<iostream>
using namespace std;
class complex{
    float real, img;
    public:
    complex(){
        real=0.0;
        img=0.0;
    }
    complex(float r,float i){
        real=r;
        img=i;
    }
     complex operator /( complex& c2) {
        float denominator = c2.real * c2.real + c2.img * c2.img;
        float realPart = (real * c2.real + img * c2.img) / denominator;
        float imgPart = (img * c2.real - real * c2.img) / denominator;
        return complex(realPart, imgPart);
    }

    // Overloading the << operator for output
    friend ostream& operator<<(ostream& output, complex& c) {
        output << c.real;
        if (c.img >= 0) 
            output << " + " << c.img << "i";
        else 
            output << " - " << -c.img << "i";
        return output;
    }
};

int main(){
    complex c1(2.5,5.5),c2(3.4,4.4),c3;
  
     cout<<"the first complex number is:"<<c1<<endl;
     cout<<" the second complex number:"<<c2<<endl;
    c3=c1/c2;
    cout<<"the quotient is:"<<c3<<endl;
return 0;
    
}