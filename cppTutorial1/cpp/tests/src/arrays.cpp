#include <iostream>
#include <string>

using namespace std;

void arraysIntro()
{
    int input = 0;
    int values[3] = {};

    cout << "Right after initialisation with {}" << endl;
    for (int i = 0; i < 3; i++)
        cout << values[i] << " ";

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Set values[" << i << "] = ";
        cin >> input;
        values[i] = input;
    }

    cout << "There are the elements you just put in." << endl;
    for (int i = 0; i < 3; i++)
        cout << values[i] << " ";

    double numbers[4] = {1.8, 3.5, 90.342, 1.234};

    cout << "There are the elements in numbers: " << endl;
    for (int i = 0; i < 4; i++)
        cout << numbers[i] << " ";
    cout << endl;

    cout << "There are the elements in text: " << endl;
    string text[] = {"app", "ere", "alakdf"};
    for (int i = 0; i < 3; i++)
        cout << text[i] << " ";
    cout << endl;

    cout << "WARNING: if we assign int table[3]" << endl;
    cout << "we can do ask table[4] without any warning!" << endl;

    cout << "Small exercise: 12 times table." << endl;
    int ex[13] = {};
    for (int i = 0; i < 13; i++)
    {
        ex[i] = 12 * i;
    }

    cout << "Result:" << endl;
    for (int i = 0; i < 13; i++)
        cout << "12 * " << i << " = " << ex[i] << endl;

    cout << endl;
}

void show1(const int nElements, string texts[])
{
    for (int i = 0; i < nElements; i++)
    {
        cout << texts[i] << endl;
    }
}

void show2(const int nElements, string *texts)
{
    for (int i = 0; i < nElements; i++)
    {
        cout << texts[i] << endl;
    }
}

void show3(string (&texts)[3])
{
    for (int i = 0; i < sizeof(texts) / sizeof(string); i++)
    {
        cout << texts[i] << endl;
    }
}

char *getMemory()
{
    char *pNew = new char[100];
    return pNew;
}

void freeMemory(char *pMem)
{
    delete[] pMem;
}

int main()
{
    cout << "=============" << endl;
    cout << "Working with arrays & chars" << endl;
    char text[] = "hello";
    int N = sizeof(text) / sizeof(char);

    for (int i = 0; i < N; i++)
        cout << text[i] << " " << flush;
    cout << endl;

    int k = 0;
    while (true)
    {
        if (text[k] == '\0')
            break;
        cout << text[k] << flush;
        k++;
    }
    cout << endl;
    cout << "=============" << endl;
    cout << "Reversing a primitive string in place" << endl;

    char textToReverse[] = "myNameIsC++";
    int n = sizeof(textToReverse) / sizeof(char);
    cout << "Before reversing:" << endl;
    k = 0;
    while (true)
    {
        if (textToReverse[k] == '\0')
            break;
        cout << textToReverse[k] << flush;
        k++;
    }
    cout << endl;

    int l = 0;
    int r = n - 2;
    while (l < r)
    {
        char temp = textToReverse[l];
        textToReverse[l] = textToReverse[r];
        textToReverse[r] = temp;
        l++;
        r--;
    }

    cout << "After reversing:" << endl;
    k = 0;
    while (true)
    {
        if (textToReverse[k] == '\0')
            break;
        cout << textToReverse[k] << flush;
        k++;
    }
    cout << endl;

    int nChars = sizeof(textToReverse) - 1;
    char *pStart = textToReverse;
    char *pEnd = textToReverse + nChars - 1;

    while (pStart < pEnd)
    {
        char save = *pStart;
        *pStart = *pEnd;
        *pEnd = save;
        pStart++;
        pEnd--;
    }

    cout << "Reversing with pointers:" << endl;
    k = 0;
    while (true)
    {
        if (textToReverse[k] == '\0')
            break;
        cout << textToReverse[k] << flush;
        k++;
    }
    cout << endl;

    cout << "=============" << endl;
    cout << "Arrays and functions" << endl;

    string texts[] = {"apple", "orange", "banana"};
    cout << "If we pass an array in a function we only will have it as a pointer -> we lose the array size information." << endl;
    show1(3, texts);
    show2(3, texts);
    show3(texts);

    cout << "Don't return pointers to local variables! the address is within the scope of the function and it will disappear." << endl;

    cout << "Allocate & deallocate" << endl;
    char *pMem = getMemory();
    freeMemory(pMem);

    return 0;
}