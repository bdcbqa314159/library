#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void basicsWithPointers(){
	int a[5] = {1,2,3,4,5};
	int *p = nullptr;
	p = new int[5];

	// we can't do p = nullptr; before delete []p; but the converse is ok.

	p[3] = 15;


	int *q = new int[20];

	//work.

	delete []q;

	q = new int [40];


	delete []p;
	delete []q;
}

void pointersArithmetic(){
	int a[5] = {1,2,3,4,5};
	int *p = a;

	for (int x : a)
		cout<<x<<" ";

	cout<<endl;

	cout<<"*p:"<<endl;

	cout<<*p;
	cout<<"p++:"<<endl;
	p++;
	cout<<*p;

	cout<<"p--:"<<endl;
	p--;
	cout<<*p;

	cout<<"p+=2:"<<endl;
	p+=2;
	cout<<*p;

	cout<<"p-=1:"<<endl;
	p-=1;
	cout<<*p;

	int *q = &a[3];

	cout<<"p-q"<<endl;
	int d = p-q;
	cout<<d<<endl;


	for (int i = 0; i<5; i++){
		cout<<a[i]<<endl;
	}

	for (int i = 0; i<5; i++){
		cout<<i[a]<<endl;
	}

	int *u = a;
	for (int i = 0; i<5; i++){
		cout<<*(a+i)<<endl;
	}

	for (int i = 0; i<5; i++){
		cout<<*(u+i)<<endl;
	}

	for (int i = 0; i<5; i++){
		cout<<u[i]<<endl;
	}
}


int main()
{

	cout<<"Hey pointers"<<endl;

	// Problems with pointers
	/*
	1.unitialized pointer int *p; p using is a problem!

	int x = 10;
	int *p;
	p = &x;
	=>OK

	int *p = new int(5);

	2.memory leak every allocated needs to be deallocated.

	int *p = new int[5];

	delete []p;
	then either;

	p = NULL;
	p = 0;
	p = nullptr;

	3.dangling pointers
	a pointer accessed in the main which has been eliminated within a intermediate function.

	*/

	int x = 10;
	int &y = x;

	int a;

	a = x;
	x = 25;

	//rvalue is a data
	//lvalue is an address

	/*
	int &y = x; x is an lvalue;
	There is no memory consumed.
	Once a reference is created it can't be reassigned to another variable.
	*/

    int *const ptr = &x;
    (*ptr)++;
    cout<<x<<endl;
    
    


    return 0;
}
