#include <cppTutorial3>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void testingProduct()
{
    ProductTest camera;
    ProductTest cam2(101, "goPro", 100, 90);

    camera.showDetails();
    cout << "=====" << endl;
    cam2.showDetails();
}

int main()
{

    cout << "Hey oops" << endl;
    testingProduct();

    return 0;
}