#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Complex{
    
    int re, im;
    
public:
    Complex():re(0), im(0){
        
    }
    
    Complex(int re, int im):re(re), im(im){
        
    }
    
    Complex(const Complex &other):re(other.re), im(other.im){
        
    }
    
    Complex& operator=(const Complex &other){
        
        re = other.re;
        im = other.im;
        
        return *this;
    }
    
    int Re() const{
        return re;
    }
    
    int Im() const{
        return im;
    }
    
    ~Complex(){
        
    }
    
    Complex operator+(const Complex& rhs){
        Complex temp(re+rhs.re, im+rhs.im);
        return temp;
    }
    
    friend Complex operator+(Complex &c1, Complex &c2);
    
};

ostream &operator<<(ostream &os, const Complex& complex){
    os<<complex.Re()<<"+"<<complex.Im()<<"i"<<endl;
    return os;
}

//we can use void for operator<< but we won't be able to continue with <<endl;

Complex operator+(Complex &c1, Complex &c2){
    Complex temp = c1.operator+(c2);
    return temp;
}

class Rational{

    int num, den;
public:
    Rational():num(0), den(1){}
    
    Rational(int num, int den):num(num){
        if (den == 0){
            num = 0;
            den = 1;
        }
        else this->den = den;
    }
    
    Rational operator+(const Rational &r){
        Rational temp(num*r.den+den*r.num,den*r.den);
        return temp;
        
    }
    
    friend ostream &operator<<(ostream &os,Rational &r);
};

ostream &operator<<(ostream &os, Rational &r){
    os<<r.num<<"/"<<r.den;
    return os;
}

void workingWithComplex(){
    Complex a(1,1), b(3,9);
    Complex c = a+b;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    
    Complex d = a.operator+(b);
    cout<<d<<endl;
    Complex e = operator+(a,b);
    cout<<e<<endl;
}


int main()
{
    
    cout<<"Hey overloading"<<endl;
    
    
    
    Rational a(1,2), b(3,4);
    Rational c = a+b;
    
    cout<<c<<endl;
    
    return 0;
}
