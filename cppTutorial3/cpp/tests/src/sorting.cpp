#include <cppTutorial3>
#include <iostream>

using namespace std;

void sortingTest()
{
    cout << "Testing Bubble Sort" << endl;
    testingBubbleSort();

    cout << "\nTesting Insertion Sort" << endl;
    testingInsertionSort();

    cout << "\nTesting Selection Sort" << endl;
    testingSelectionSort();

    cout << "\nTesting Counting Sort" << endl;
    testingCountingSort();
}

int main()
{
    // arrayTest();
    sortingTest();
    return 0;
}