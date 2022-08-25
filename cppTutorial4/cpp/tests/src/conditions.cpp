#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int findMax(int x, int y){
	if (x>y) return x;
	else return y;
}

void interfaceMax(){
	cout<<"Give 2 integers:"<<endl;
	int x, y;
	cin>>x>>y;

	int max = findMax(x,y);
	cout<<"Well the max is : "<<max<<endl;
}

void dynamicDeclaration(){
	int a, b, c;
	cout<<"Give a, b & c"<<endl;
	cout<<" a >> b >> c >> ??"<<endl;
	cin>>a>>b>>c;

	// Only from c++17
	if (int k = b*b-a<c){
		cout<<"Hey it works";
	}
	else{
		cout<<"k = b*b - a >= c"<<endl;
	}
}

double discount(double amount){
	if (amount<100) return amount;
	else if(amount <= 500) return amount*0.9;
	else return amount*0.8;
}

void interfaceDiscount(){
	cout<<"Hello, please give the total bill amount and we will see if you can have a discount."<<endl;
	cout<<"Amount >>> ";
	double amount;
	cin>>amount;
	double answer = discount(amount);
	if (amount < 100) cout<<"You have no discount your amount reamains at "<<answer<<endl;
	else if (amount<=500) cout<<"Yay, you have 10% of discount, you pay only "<<answer<<endl;
	else cout<<"OMG you have 20% of discount, you will pay "<<answer<<endl;
}

bool isLeap(int year){
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0){
				return true;
			}
			else
				return false;
		}
		else{
			return true;
		}
	}
	else
		return false;
}

void interfaceLeapYear(){
	cout<<"Hey, give a year."<<endl;
	cout<<"year >>> ";
	int year = 0;
	cin>>year;

	if (isLeap(year)) cout<<year<<" is a leap year"<<endl;
	else cout<<year<<" is not a leap year."<<endl;
}

int main()
{

	cout<<"Hey conditions"<<endl;

	// interfaceMax();

	// interfaceDiscount();
	interfaceLeapYear();


    return 0;
}
