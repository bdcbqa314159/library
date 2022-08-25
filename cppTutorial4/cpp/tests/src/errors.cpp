#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class myException:public exception{
    
public:
    const char *what(){
        
        return "myException";
        
    }
};

class myException1:public myException{
public:
    const char *what(){
        return "myNewException";
    }
};

/*
 In the try catch we need to catch first the child and then the parent because if not the error will be catch by children because a children is a parent.
 */





int division(int a, int b){
    if (b == 0) throw 1;
    return a/b;
}

int main()
{
    cout<<"Error handling."<<endl;
    
    int x = 1, y = 0;
    try{
        int z = division(x,y);
        cout<<z<<endl;
    }
    catch(int e){
        cout<<"Error with dividing by zero with code : "<<e<<endl;
    }
    
    
    
    return 0;
}


