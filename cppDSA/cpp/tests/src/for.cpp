#include <cppDSA>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i =0; i<10; i++){
        cout<<GenerateRandomNumber(0, 100)<<" ";
    }
    cout<<endl;
    return 0;
}
