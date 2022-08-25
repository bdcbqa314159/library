#include <cppTutorial4>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

void chars()
{

	// chars array.

	char a[10] = "Hello";
	char b[] = "Hello";

	// Important the '\0' character is automaticly set at the end of the array.
	// 0 is considered as '\0'

	// Not allowed from c++11:
	// char *c = "Hello";

	char s[20];
	cin >> s;
	// Problem if there is a space within the reading.

	char t[50];
	cin.get(t, 50);
	cin.getline(t, 50);

	// IMPORTANT cin.get does not include cin.ignore in getline it is included.
}

void charFunctions()
{

	char s[200] = "Junk";
	char s3[200] = "Good";

	cout << strlen(s) << endl;
	strcat(s, s3);
	cout << "New s:" << endl;
	cout << s << endl;

	strncat(s, s3, 4);
	cout << "New s:" << endl;
	cout << s << endl;

	char z[100] = "";
	strcpy(z, s);
	cout << z << endl;

	strncpy(z, s, 10);
	cout << z << endl;
}

void charFunctions1()
{

	cout << "Hey strings" << endl;

	char s1[20] = "Programming";
	char s2[20] = "gram";

	if (strstr(s1, s2) != nullptr)
	{
		cout << strstr(s1, s2) << endl;
	}

	else
	{
		cout << "not found" << endl;
	}

	cout << strchr(s1, 'r') << endl;
	cout << strrchr(s1, 'r') << endl;

    cout<<strcmp(s1, s2)<<endl;
	/*
	<0 if s1<s2
	=0 if s1=s2
	>0 if s1>s2
	*/
}

void charFunctions2()
{
	char s1[10] = "235";
	char s2[10] = "54.78";

	long int x = strtol(s1, nullptr, 10);
	float y = strtof(s2, nullptr);

	char s3[100] = "x=10;y=20;z=35";

	// cout << strtok(s3, "=;"); it only gives x;

	char *token = strtok(s3, "=;");

	while (token)
	{
		cout << token << endl;
		token = strtok(nullptr, "=;");
	}
}

void stringsFunctions(){
    string s1 = "Hello";
    string s2 = "ALLEZ";

    string s;
    getline(cin, s);

    cout << s.length() << endl;
    cout << s.size() << endl;

    cout << s.capacity() << endl;

    s.resize(30);

    s.max_size(); // gives the maximum of size per string allowed by the compiler.
    
    s.clear();
    
    bool isEmpty = s.empty();
}

void stringFunctions1(){
    string s1 = "Hello";
    string s2 = "ALLEZ";

    string s;
    getline(cin, s);

    s.append("Bye");
    s.insert(3,"kk");
    
    s.replace(3,5, "aa");
    
    s.erase();
    s.push_back('f');
    
    s.pop_back();
    
    s1.swap(s2);
    
}

void stringFunctions2(){
    string s1 = "Hello";
    string s2 = "ALLEZ";

    string s;
    getline(cin, s);
    
    char c[100];
    s1.copy(c,s1.length());
    //The '\0' is not added!
    cout<<c<<endl;
    
    cout<<s1.find('l')<<endl;
    cout<<s1.rfind('l')<<endl;
    //Sanity check: compare with s1.size();
    
    cout<<s1.find_first_of('l')<<endl;
    cout<<s1.find_last_of('l')<<endl;
    
    cout<<s1.substr(3,4)<<endl; //from place 3 give 4 chars.
    cout<<s1.compare(s2)<<endl;
    
    /*
    <0 if s1<s2
    =0 if s1=s2
    >0 if s1>s2
    */
    
    cout<<s1.at(2)<<endl; //With sanity check in case we are out of bounds.
    
    cout<<s1.front()<<endl;
    cout<<s1.back()<<endl;
    
    cout<<s1[3]<<endl;
    string s4 = s2;
    s4 = s1+s2;
}

int counterLength(string &s){
    int count = 0;
    for (int i = 0; s[i]!='\0'; i++){
        count++;
    }
    
    return count;
}

void interface1(){
    string s;
    cout<<"Give a piece of text"<<endl;
    getline(cin,s);
    
    cout<<"In built size: "<<s.size()<<endl;
    cout<<"Benchmark size: "<<counterLength(s)<<endl;
}

void lowerCase(string &s){
    for (auto &c : s){
        if (c>=65 && c<=90)
            c+=32;
    }
}

void upperCase(string &s){
    for (auto &c : s){
        if (c>=97 && c<=122)
            c-=32;
    }
}

void interface2(){
    string s;
    cout<<"Give a piece of text"<<endl;
    getline(cin,s);
    lowerCase(s);
    cout<<"In built lower case: "<<s<<endl;
}

void interface3(){
    string s;
    cout<<"Give a piece of text"<<endl;
    getline(cin,s);
    upperCase(s);
    cout<<"In built upper case: "<<s<<endl;
}

void specialCounter(string &s){
    
    int words = 0, vowels = 0, consonants = 0;
    
    for (int i = 0; i<s.size(); i++){
        if (s[i] == ' ' || i==s.size()-1) words++;
        if (s[i]>=65 && s[i]<=90){
            if (s[i] == 'A'||s[i] == 'E'||s[i] == 'I'||s[i] == 'O'||s[i] == 'U')
                vowels++;
            else consonants++;
        }
        
        if (s[i]>=97 && s[i]<=122){
            if (s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u')
                vowels++;
            else consonants++;
        }
    }
    
    cout<<"words: "<<words<<endl;
    cout<<"vowels: "<<vowels<<endl;
    cout<<"consonants: "<<consonants<<endl;
    
    
}

void interface4(){
    string s;
    cout<<"Give a piece of text"<<endl;
    getline(cin,s);
    specialCounter(s);
}

void stringFunctions3(){
    
    string s1 = "Hello";
    string s2 = "ALLEZ";

    string s;
    getline(cin, s);
    
    string::iterator it = s.begin();
    
    it = s.end();
    
    for (it = s.begin(); it!=s.end(); it++)
        cout<<*it<<endl;
    
    string::reverse_iterator it1 = s.rbegin();
    
    for (; it1!=s.rend(); it1++)
        cout<<*it1<<endl;
}

bool isPalindrome(string &s){
    int i = 0, j = s.size()-1;
    while (i<j){
        if (s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

void interface5(){
    
    string s;
    for (int i = 0; i<3; i++){
        cout<<"Give a piece of text"<<endl;
        getline(cin,s);
        if (isPalindrome(s))
            cout<<"palindrome"<<endl;
        else
            cout<<"not a palindrome"<<endl;
    }
}

string giveUserName(string &s){
    int i = (int)s.find('@');
    

    return s.substr(0,i);
    
}

void interface6(){
    string s;
    for (int i = 0; i<3; i++){
        cout<<"Give a piece of text"<<endl;
        getline(cin,s);
        
        string out =giveUserName(s);
        if (out.size()==s.size()){
            cout<<"no username found."<<endl;
        }
        else
            cout<<"user: "<<out<<endl;
    }
}

int main()
{
    
//    interface1();
//    interface2();
//    interface4();
//    interface5();
    interface6();

	return 0;
}
