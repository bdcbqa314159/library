#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


void interfaceSum(){
	int a,b;
	cout<<"Give two numbers a and b"<<endl;
	cout<<"a >>> ";
	cin>>a;
	cout<<"b >>> ";
	cin>>b;

	cout<<"The sum is "<<a+b<<endl;
	cout<<flush;
}

void interfaceName(){
	string name;
	cout<<"May I know your name ?"<<endl;
	// cin>>name;
	cin.ignore();
	getline(cin, name);

	cout<<"Hello "<<name<<endl;
}

double triangleArea(double b, double h){
	return 0.5*b*h;
}

class AreaCalculator{

	double b,h, area;

public:
	AreaCalculator():b(0), h(0){

	}

	~AreaCalculator(){

	}

	AreaCalculator(double b, double h):b(b), h(h){

	}

	AreaCalculator(const AreaCalculator &other):b(other.b), h(other.h){

	}

	const AreaCalculator& operator=(const AreaCalculator &other){

		b = other.b;
		h = other.h;
		return *this;
	}

	double operator()(){
		area = triangleArea(b,h);
		return area;
	}

};

void interfaceArea(){
	cout<<"Triangle Area Calculator"<<endl;
	cout<<"Give b base, h height"<<endl;
	double b,h;
	cout<<"b >>> ";
	cin>>b;
	cout<<"h >>> ";
	cin>>h;

	AreaCalculator calculator(b,h);
	double area = calculator();

	cout<<"Alright, the area is "<<area<<endl;
}

int sumOfFirst(int n){
	return n*(n+1)/2;
}

void interfaceSumN(){
	cout<<"Give an integer N:"<<endl;
	cout<<"N >> ";
	int N;
	cin>>N;

	while (N<0){
		cout<<"Please enter a positive integer"<<endl;
		cout<<"N >> ";
		cin>>N;
	}

	int sumN = sumOfFirst(N);

	cout<<"Alright, the sum from 0 to "<<N<<" is "<<sumN<<endl;
}

class QuadraticSolver{
	double a,b,c,delta;
	vector<double> roots{};

	public:
	QuadraticSolver():a(0), b(0), c(0){

	}

	~QuadraticSolver(){

	}

	QuadraticSolver(double a, double b, double c):a(a), b(b), c(c){

	}

	QuadraticSolver(const QuadraticSolver &other):a(other.a), b(other.b), c(other.c){

	}

	const QuadraticSolver& operator=(const QuadraticSolver &other){

		a = other.a;
		b = other.b;
		c = other.c;
		return *this;
	}

	void operator()(){

		if (a == 0 && b == 0 && c == 0){
			cout<<"R is the solution for this equation."<<endl;

		}

		else if(a == 0 && b == 0 && c != 0){
			cout<<"There is no solution"<<endl;

		}

		else if(a == 0 && b != 0 && c != 0){
			cout<<"There is only one solution"<<endl;
			roots.push_back(-c/b);
		}

		else{
			getDelta();
			if (delta == 0){
				cout<<"There is a double solution"<<endl;
				roots.push_back(-b/(2*a));
			}

			else if (delta>0){
				cout<<"There is two solutions"<<endl;
				roots.push_back( (-b+sqrt(delta)/(2*a)) );
				roots.push_back( (-b-sqrt(delta)/(2*a)));
			}

			else {
				cout<<"There is no solution in R"<<endl;

			}

		}
	}

	void getDelta(){
		delta = b*b-4*a*c;
	}

	void givingSolution(){
		operator()();
		if (roots.size()>0){
			for (double x: roots)
				cout<<x<<" ";
		}
		cout<<endl;
	}

};

void quadraticInterface(){
	cout<<"Give a, b & c for a*x*x + b*x + c = 0"<<endl;
	double a,b,c;
	cout<<" a >> ";
	cin>>a;
	cout<<" b >> ";
	cin>>b;
	cout<<" c >> ";
	cin>>c;

	QuadraticSolver qs(a,b,c);
	qs.givingSolution();

}

void givingAreaOfCercle(){
	float area, r;
	cout<<"Give radius"<<endl;
	cin>>r;
	area = M_PI*r*r;
	cout<<"The area of the cercle is "<<area<<endl;
}

void givingSpeed(){
	float u,v,a, speed;
	cout<<"Give u, v & a:"<<endl;
	cin>>u>>v>>a;

	speed = (v*v -u*u)/(2*a);
	cout<<"Speed is "<<speed<<endl;
}

void increment(){
	int x = 1;
	cout<<"x:"<<x<<endl;
	cout<<"++x:"<<endl;
	cout<<++x<<endl;
	cout<<x<<endl;
	cout<<"x++:"<<endl;
	cout<<x++<<endl;
	cout<<x<<endl;
}

void overflowEx(){
	char x = 127;
	x++;
	cout<<(int)x<<endl;
}

void bitwiseOperations(){

	cout<<"Bitwise operators"<<endl;
	cout<<" & | ^ ~ << and >>"<<endl;

	int x = 11, y = 5, z;
	cout<<"x = 00001011"<<endl;
	cout<<"y = 00000101"<<endl;
	cout<<"Go ahed with the bitwise operations :)"<<endl;
	cout<<"To guess the negative number take the ~ and +1"<<endl;

	cout<<"&"<<endl;
	z = x&y;
	cout<<"z: "<<z<<endl;

	cout<<"|"<<endl;
	z = x|y;
	cout<<"z: "<<z<<endl;

	cout<<"y<<1"<<endl;
	z=y<<1;
	cout<<"z: "<<z<<endl;

	cout<<"x~1"<<endl;
	z=~x;
	cout<<"z: "<<z<<endl;
}

void enumsAndTypedefs(){
	cout<<"Enums & Typedefs"<<endl;

	enum day{
		mon, tue, wed, thu, fri, sat, sun
	};

	cout<<"friday: "<<day::fri<<endl;

	enum department{
		cs = 1, ece, it, civil
	};

	typedef int marks;
	typedef int rollno;

	marks m1, m2, m3;
	rollno r1, r2, r3;
}

void netSalary(){

	cout<<"We are going to find the net salary from your input."<<endl;
	double baseSalary, allowances, deductions;

	cout<<"Please give your base salary:"<<endl;
	cin>>baseSalary;
	cout<<"Please enter the percentage of allowances:"<<endl;
	cin>>allowances;
	cout<<"And finally, give the percentage of deductions:"<<endl;
	cin>>deductions;

	double netSalary = baseSalary*(1 + allowances - deductions);
	cout<<"Here, your net salary is "<<netSalary<<endl;



}



int main()
{
	// interfaceSum();
	// interfaceName();
	// interfaceArea();
	// interfaceSumN();
	// quadraticInterface();
	// givingAreaOfCercle();
	// givingSpeed();

	netSalary();



    return 0;
}
