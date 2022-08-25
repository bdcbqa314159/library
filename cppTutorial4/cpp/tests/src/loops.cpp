#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void multiplicationTable(int n){
	for (int i = 1;i<=10; i++){
		cout<<n<<" * "<<i<<" = "<<n*i<<endl;
	}
}

void interfaceMultiplicationTable(){
	int number;
	cout<<"Please give a number: "<<endl;
	cin>>number;

	cout<<"Alright, there you have the multiplication table for "<<number<<": "<<endl;
	multiplicationTable(number);
}

int sumOf(int n){
	int sum = 0;
	for (int i = 1;i<=n; i++)
		sum+=i;
	return sum;
}

void interfaceSumOfN(){
	cout<<"Give an integer: "<<endl;
	int N;
	cin>>N;
	cout<<"Alright, the sum of 0 + 1 + ... + "<<N<<" is: "<<endl;
	cout<<sumOf(N)<<endl;
}

long int factOf(int n){
	int fact = 1;
	for (int i = 1;i<=n; i++)
		fact*=i;
	return fact;
}

void interfaceFactOfN(){
	cout<<"Give an integer: "<<endl;
	int N;
	cin>>N;
	cout<<"Alright, the factorial of 1 * 2 * 3 ... + "<<N<<" is: "<<endl;
	cout<<factOf(N)<<endl;
}

void loopsBasics(){
	/*
	IMPORTANT:
	There is 4 types of loops, while, do while, for and for each.
	*/

	int n = 100, m = 100;

	while (n>0){
		cout<<n%10<<endl;
		n/=10;
	}

	do{
		cout<<m%10<<endl;
		m/=10;
	}while(m>10);

	for (int i = 0; i<10; i++)
		cout<<i<<endl;

}

void giveFactors(int n){
	if (n == 0) return;
	for (int i = 1; i<=n; i++){
		if (n%i == 0) cout<<i<<endl;
	}
}

void interfacePrintingFactors(){
	cout<<"Please give a number: "<<endl;
	int N;
	cin>>N;
	cout<<"if you gave zero you won't have an answer, else the factors of "<<N<< " are: "<<endl;
	giveFactors(N);
}

bool perfectNumber(int n){
	int sum = 0;
	if (n == 0) return false;
	for (int i = 1; i<=n; i++){
		if (n%i == 0) sum += i;
	}
	return (sum == 2*n);
}

void interfacePerfectNumber(){
	cout<<"Give a number, different of zero:"<<endl;
	int N;
	cin>>N;
	if (perfectNumber(N)) cout<<N<<" is perfect."<<endl;
	else cout<<N<<" is not perfect."<<endl;
}

bool isPrime(int n){
	int count = 0;

	for (int i = 1; i<=n; i++){
		if (n%i == 0) count++;
	}
	return (count == 2);
}

void interfacePrimeNumber(){
	cout<<"Give a number, different of zero and one:"<<endl;
	int N;
	cin>>N;
	if (isPrime(N)) cout<<N<<" is prime."<<endl;
	else cout<<N<<" is not prime."<<endl;
}

void printingDigits(int n){
	while(n>0){
		cout<<n%10<<endl;
		n/=10;
	}
}

void interfacePrintingDigits(){
	cout<<"Give a number:"<<endl;
	int N;
	cin>>N;
	printingDigits(N);
}

bool isArmstrong(int n){
	int sum = 0, m = n;
	while(n>0){
		int i = n%10;
		sum+=i*i*i;
		n/=10;
	}
	return (m==sum);
}

void interfaceArmstrong(){
	cout<<"Give a number"<<endl;
	int N;
	cin>>N;
	if (isArmstrong(N)) cout<<N<<" is armstrong."<<endl;
	else cout<<N<<" is not armstrong."<<endl;
}

int reverse(int n){
	int r = 0;
	while(n>0){
		r = 10*r+n%10;
		n/=10;
	}
	return r;
}

void interfaceReverse(){
	cout<<"Give a number"<<endl;
	int N;
	cin>>N;
	cout<<"The reverse number of "<<N<<" is "<<reverse(N)<<endl;
}

int giveGDC(int a, int b){
	while (a!=b){
		if (a>b) a -= b;
		else b -= a;
	}
	return a;
}

void givingGDC(){
	cout<<"Please give two numbers: "<<endl;
	cout<<"a >>> ";
	int a; cin>>a;
	cout<<"b >>> ";
	int b; cin>>b;
	cout<<"The GDC is "<<giveGDC(a,b)<<endl;
}

bool isPalindrome(int N){
	int r = reverse(N);
	return (r==N);
}

void interfacePalindrome(){
	cout<<"Give a number"<<endl;
	int N;
	cin>>N;
	if (isPalindrome(N)) cout<<N<<" is a palindrome."<<endl;
	else cout<<N<<" is not palindrome."<<endl;
}

int main()
{

	// interfaceMultiplicationTable();
	// interfaceSumOfN();

	// interfaceFactOfN();
	// interfacePrintingFactors();
	// interfacePerfectNumber();
	// interfacePrimeNumber();
	// interfacePrintingDigits();
	// interfaceArmstrong();
	// interfaceReverse();
	// givingGDC();
	interfacePalindrome();

    return 0;
}
