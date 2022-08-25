#include <cppTutorial4>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Student{
public:
    Student():name(""),roll(0),branch(""){}
    Student(string name, int roll, string branch):name(name), roll(roll), branch(branch){
        
    }
    
    string name;
    int roll;
    string branch;
    
    friend ofstream &operator<<(ofstream &ofs, Student &s);
    friend ifstream &operator>>(ifstream &ofs, Student &s);
    friend ostream &operator<<(ostream &os, Student &s);
};

ofstream &operator<<(ofstream &ofs, Student &s){
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;
    return ofs;
}

ostream &operator<<(ostream &os, Student &s){
    os<<s.name<<" "<<s.roll<<" "<<s.branch<<endl;
   
    return os;
}

ifstream &operator>>(ifstream &ifs, Student &s){
    ifs>>s.name>>s.roll>>s.branch;
    return ifs;
}

int main()
{
    
    cout<<"ios"<<endl;
    
    ofstream ofs("My.txt", ios::app);
    ofs<<"John"<<endl;
    ofs<<25<<endl;
    ofs<<"cs"<<endl;
    
    ofs.close();
    
    ifstream infile;
    infile.open("My.txt");
    
    //ios::in , ios::out
    
    if (!infile.is_open()){
        cout<<"file cannot be open"<<endl;
    }
    
    string str;
    int x;
    
    infile>>str;
    infile>>x;
    cout<<str<<" "<<x<<endl;
    
    if (infile.eof()){
        cout<<"end of file reached"<<endl;
    }
    
    infile.close();
    
    
    Student s("John", 290, "CS");
    ofs.open("Student.txt",ios::trunc);
    ofs<<s;
    
    ofs.close();
    
    Student s1;
    infile.open("Student.txt");
    infile>>s1;
    
    cout<<s1<<endl;
    
    
    return 0;
}
