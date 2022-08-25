#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Rectangle{

    int length, breadth;
public:
    int area(){
        return length*breadth;
    }
    
    int perimeter(){
        return 2*(length+breadth);
    }
    
    Rectangle():length(0), breadth(0){
        
    }
    
    Rectangle(int length, int breadth):length(length), breadth(breadth){
        
    }
    
    ~Rectangle(){
        
    }
    
    Rectangle(const Rectangle &other){
        length = other.length;
        breadth = other.breadth;
    }
    
    Rectangle &operator=(const Rectangle &other){
        
        length = other.length;
        breadth = other.breadth;
        
        return *this;
    }
    
    int getLength() const{
        return length;
    }
    
    int getBreadth() const{
        return breadth;
    }
    
    void setLength(int length){
        this->length = length;
    }
    
    void setBreadth(int breadth){
        this->breadth = breadth;
    }
    
};

ostream &operator<<(ostream &os, const Rectangle &rectangle){
    os<<"rectangle - L:"<<rectangle.getLength()<<" - B: "<<rectangle.getBreadth();
    
    return os;
}

class Student{
    
    int roll;
    string name;
    vector<int> marks;
    
public:
    Student():roll(0), name(""), marks(vector<int>(3,0)){}
    
    Student(int roll, string name, int m1, int m2, int m3):roll(roll), name(name), marks(vector<int>(3,0)){
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    
    ~Student(){}
    
    int totalGrades() const{
        int total = 0.;
        for (int i = 0; i<3; i++)
            total += marks[i];
        return total;
    }
    
    char grade() const{
        
        double mean = totalGrades()/3.;
        
        if (mean<=40) return 'C';
        else if (mean<=60) return 'B';
        else return 'A';
        
    }
    
    int getRoll() const{
        return roll;
    }
    
    string getName() const{
        return name;
    }
    
    vector<int> getMarks() const{
        return marks;
    }
    
};

ostream &operator<<(ostream &os, const Student &student){
    os<<"Student no: "<<student.getRoll()<< " - named: "<<student.getName()<<endl;
    os<<"Marks:"<<endl;
    vector<int> marks = student.getMarks();
    for (auto m: marks)
        os<<m<<" ";
    
    os<<"The grade is "<<student.grade()<<endl;
    return os;
        
}

class Test{
    int a, b;
public:
    static int count;
    
    Test():a(0), b(0){
        count++;
    }
    static int getCount(){
        return count;
    }
};

int Test::count = 0;

class Outer{
public:
    int a = 10;
    static int b;
    
    class Inner{
        int c = 0;
    public:
        int z = 10;
        
    };
    
    Inner i;
    void f(){
//        i.c = 10; NO!
        
        
    }
};

int main()
{
    
    cout<<"Hey oops."<<endl;
    
    Rectangle r1(2,3);
    Rectangle r2(r1);
    
    cout<<r1<<endl;
    
    /*
     inline functions: a function coded inside a class is automatically inline. A function outside the class is not inline but if we want make a function outside the class and inline we only need to supply inline within the declaration. Like: inline int doSome(int a, int b); and then just call int Class::doSome(int a, int b){return 0;}
     
     */
    
    Student s(10, "John", 80, 50, 70);
    cout<<s<<endl;
    
    Test t;
    cout<<Test::getCount()<<endl;
    Test y;
    cout<<y.getCount()<<endl;
    
    
    return 0;
}
