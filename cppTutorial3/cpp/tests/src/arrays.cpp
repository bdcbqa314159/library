#include <cppTutorial3>
#include <iostream>

using namespace std;

void arrayTest()
{
    cout << "Testing Linear Search" << endl;
    testingLinearSearch();
    cout << "\nTesting Binary Search" << endl;
    testingBinarySearch();
    cout << "\nTesting reverse function" << endl;
    testingReverse();
    cout << "\nTesting printingPairs function" << endl;
    testingPrintingPairs();
    cout << "\nTesting printingSubarray function" << endl;
    testingPrintingSubarrays();
}

void arrayTestNo2()
{
    cout << "Testing Max Subarray problem:" << endl;
    testingMaxSubarrays();
}

int main()
{
    // arrayTest();
    arrayTestNo2();
    return 0;
}
