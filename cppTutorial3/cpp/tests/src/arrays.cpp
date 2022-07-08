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

void characterArraysTest()
{
    // characterArraysHW();
    giveAlphaDigitsSpaces();
    characterArrays();
}

void testingShortestPath()
{
    cout << "Solution for shortest path:" << endl;
    cout << "Give a path:" << endl;
    shortestPath();
}

void testingLargestSentenceProblem()
{
    cout << "We will give the largest sentence from a group of n sentences and its length:" << endl;
    largestString();
}

int main()
{
    // arrayTest();
    // arrayTestNo2();
    // characterArraysTest();
    // testingShortestPath();
    testingLargestSentenceProblem();
    return 0;
}
