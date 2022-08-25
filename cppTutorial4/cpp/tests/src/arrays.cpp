#include <cppTutorial4>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


void arraysBasics(){


	int A[5] = {2,4,6,8,10};

	int N = sizeof(A)/sizeof(int);

	for (int i = 0; i<N; i++)
		cout<<A[i]<<" ";
	cout<<endl;

	for (int x: A)
		cout<<x<<" ";
	cout<<endl;
}

void sumInArray(){
	int A[7] = {4,8,6,9,5,2,7};
	int N = sizeof(A)/sizeof(int);

	int sum = 0;
	for (int i = 0; i<N; i++)
		sum+=A[i];

	cout<<"The array: "<<endl;
	for (int a: A)
		cout<<a<<" ";
	cout<<endl<<"The sum of all its elements: "<<sum<<endl;
}

void maxInArray(){
	int A[7] = {4,8,6,9,5,2,7};
	int N = sizeof(A)/sizeof(int);

	int max = A[0];
	for (int i = 1; i<N; i++){
		if (A[i]>max) max = A[i];
	}

	cout<<"The array: "<<endl;
	for (int a: A)
		cout<<a<<" ";
	cout<<endl<<"The max element: "<<max<<endl;
}

void linearSearch(){
	int A[7] = {4,8,6,9,5,2,7};
	int N = sizeof(A)/sizeof(int);

	int number = 0;
	cout<<"Give an integer >> ";
	cin>>number;

	for (int i = 0; i<N; i++){
		if (number == A[i]){
			cout<<"Number found! - at range "<<i<<endl;
		}
	}
	cout<<"The number is not here."<<endl;

	cout<<"The array: "<<endl;
	for (int a: A)
		cout<<a<<" ";
	cout<<endl;
}


void binarySearch(){
	int A[7] = {4, 6, 14, 19, 20, 45, 90};
	int N = sizeof(A)/sizeof(int);

	int number = 0;
	cout<<"Give an integer >> ";
	cin>>number;

	int l = 0, r = N-1;

	while (l<r){
		int m = l+(r-l)/2;

		if (number < A[m]) r = m-1;
		else if (number > A[m]) l = m+1;
		else{
			cout<<"Found at index "<<m<<endl;
			break;
		}
	}

	cout<<"The number is not here."<<endl;

	cout<<"The array: "<<endl;
	for (int a: A)
		cout<<a<<" ";
	cout<<endl;
}

void draw1(){

	int count = 1;
	for (int i = 0; i<4; i++){
		for (int j = 0; j<4; j++){
			cout<<count<<" ";
			count++;
		}
		cout<<endl;
	}

}

void draw2(){

	for (int i = 0; i<4; i++){
		for (int j = 0; j<4; j++){
			if (i>=j) cout<<"* ";
		}
		cout<<endl;
	}

}

void draw3(){

	for (int i = 0; i<5; i++){
		for (int j = 0; j<5; j++){
			if (i>j) cout<<"  ";
			else cout<<" *";
		}
		cout<<endl;
	}

}

void draw4(){

	for (int i = 0; i<5; i++){
		for (int j = 0; j<5; j++){
			if(i+j > 4) cout<<" *";
			else cout<<"  ";
		}
		cout<<endl;
	}
}

double average(const vector<int> &elements){
	int n = elements.size();
	int sum = 0;
	for (int i = 0; i<n; i++){
		sum += elements[i];
	}
	double mean = 1.*sum/n;
	return mean;
}


int main()
{

	cout<<"Hey arrays"<<endl;

	// sumInArray();
	// maxInArray();

	// linearSearch();
	// binarySearch();
	 draw1();
	 cout<<endl;
	 draw2();
	 cout<<endl;
	 draw3();
	 cout<<endl;
	draw4();


    return 0;
}
