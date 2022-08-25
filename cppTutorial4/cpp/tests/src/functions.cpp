#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int *fun(int size){
    int *p = new int[5];
    
    for (int i =0; i<5; i++)
        p[i] = i++;
    return p;
}

int &fun1(int &x){
    return x;
}

void functions(){
    int *ptr = fun(5);
    
    delete []ptr;
    
}

void functions1(){
    int a = 10;
    fun1(a) = 25;
    cout<<a<<endl;
}


int main()
{
    
    cout<<"Hey functions."<<endl;
    //Important: in function overloading the output does not count.
    
    /*
     void swap(int a, int b){
        
     int temp;
     temp = a; a=b; b = temp;
     
     }
     
     //calls with swap(a,b) if int a and int b has been initialized.
     
     void swap(int *a, int *b){
     
     int temp;
     temp = *a;
     *a = *b;
     *b = temp;
     
     //calls swap(&a,&b) if int a and int b has been initialized.
     }
     
     void swap(int &a, int &b){
     
     int temp;
     temp = a;
     a = b;
     b = temp;
     
     //calls swap(a,b) if int a and int b has been initialized.
     AND the function becomes part of the main as inline function.
     
     
     */
    
    /*
     return by references transforms a return value of function as lvalue.
     
     */
    
    /*
     static variable very close to global variables.
     It remains there during the whole life of the program BUT they only can be accessed from the block ie: class/function which from they are called/declared.
     
     */
    
    
    return 0;
}
