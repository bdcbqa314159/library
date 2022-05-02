#include <iostream>
#include <string>

using namespace std;

void manipulate(int value);
void realManipulate(int *value);
void pointersBasics()
{

    cout << "Some basic stuff with pointers" << endl;

    int n = 0;
    int *p = nullptr;

    cout << n << endl;
    cout << p << endl;

    cout << "Give a number for n: >>";
    cin >> n;

    cout << "This is n: " << n << endl;
    cout << "This is the address of n: " << &n << endl;

    p = &n;
    cout << "Value for the pointer: " << endl;
    cout << p << endl;
    cout << "And the value: " << endl;
    cout << *p << endl;
    cout << "Modification of n by address:" << endl;
    *p = 56;
    cout << "Value n: " << n << endl;
    cout << "Address n: " << &n << endl;
    cout << "Pointer p: " << p << endl;
    cout << "Value of *p: " << *p << endl;
    n = 10;
    cout << "Value n: " << n << endl;
    cout << "Address n: " << &n << endl;
    cout << "Pointer p: " << p << endl;
    cout << "Value of *p: " << *p << endl;

    cout << "=============" << endl;
    cout << "Shallow copy: " << endl;
    int Val = 90;
    cout << "Val: " << Val << endl;
    manipulate(Val);
    cout << "Val: " << Val << endl;
    cout << "Deep copy with addresses: " << endl;
    cout << "Val: " << Val << endl;
    realManipulate(&Val);
    cout << "ValAfter: " << Val << endl;
}
void pointerArrays()
{
    cout << "Pointers & arrays" << endl;
    string texts[] = {"one", "two", "three"};

    int N = sizeof(texts) / sizeof(string);
    cout << N << endl;

    for (int i = 0; i < N; i++)
    {
        cout << texts[i] << " " << flush;
    }
    cout << endl;

    string *pTexts = texts;
    for (int i = 0; i < N; i++, pTexts++)
    {
        cout << *pTexts << " " << flush;
    }
    cout << endl;

    string *pElement = texts;
    string *pEnd = &texts[N - 1];

    while (true)
    {

        cout << *pElement << " " << flush;
        if (pElement == pEnd)
            break;
        pElement++;
    }
    cout << endl;
}

void exercise()
{
    cout << "Exercise..." << endl;
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int N = sizeof(nums) / sizeof(int);

    cout << "Size of nums: " << N << endl;

    cout << "Elements of nums with array:" << endl;
    for (int i = 0; i < N; i++)
        cout << nums[i] << " " << flush;

    cout << endl;

    int *p = nums;

    cout << "Elements of nums with pointers & deferencing:" << endl;
    for (int i = 0; i < N; i++, p++)
        cout << *p << " " << flush;

    cout << endl;

    p = &nums[0];
    int *pEnd = &nums[N - 1];

    cout << "Elements of nums with two pointer technique:" << endl;
    while (true)
    {
        cout << *p << " " << flush;
        if (p == pEnd)
            break;
        p++;
    }
    cout << endl
         << "Happy coding" << endl;
}

int main()
{
    // pointersBasics();
    cout << "==========" << endl;
    cout << "Pointers & arithmetic" << endl;

    const int N = 5;
    string texts[N] = {"one", "two", "three", "four", "five"};

    for (int i = 0; i < N; i++)
    {
        cout << texts[i] << " " << flush;
    }
    cout << endl;

    string *pTexts = texts;
    pTexts += N - 1;
    cout << *pTexts << endl;
    pTexts--;
    cout << *pTexts << endl;

    string *pEnd = &texts[N];
    pTexts = &texts[0];

    while (pTexts != pEnd)
    {
        cout << *pTexts << " " << flush;
        pTexts++;
    }
    cout << endl;

    pTexts = &texts[0];
    int test = pEnd - pTexts; // could be long
    cout << test << endl;

    pTexts = &texts[0];

    pTexts += N / 2;
    cout << *pTexts << endl;

    return 0;
}

void manipulate(int value)
{
    cout << "Value: " << value << endl;
    value = 10;
    cout << "Value : " << value << endl;
}

void realManipulate(int *value)
{
    *value = 60;
}