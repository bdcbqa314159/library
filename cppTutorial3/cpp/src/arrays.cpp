#include "../include/cppTutorial3_bits/arrays.hpp"
using namespace std;

void showArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int linearSearch(int *arr, int n, int key)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int binarySearch(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return -1;
}

void reverse(int *arr, int n)
{

    int s = 0, e = n - 1;
    while (s < e)
    {

        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void printingPairs(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
}

void printingSubarrays(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

int maxSubarrayVersion1(int *arr, int n)
{
    int maxSub = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum = 0;
            for (int k = i; k <= j; k++)
                currSum += arr[k];

            maxSub = max(currSum, maxSub);
        }
    }
    return maxSub;
}

int maxSubarrayVersion2(int *arr, int n)
{
    int curr = arr[0], total = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr = max(curr + arr[i], arr[i]);
        total = max(total, curr);
    }

    return total;
}

int maxSubarrayVersion3(int *arr, int n)
{
    int maxSub = INT_MIN;
    int *ps = new int[n];
    ps[0] = arr[0];
    for (int i = 1; i < n; i++)
        ps[i] = ps[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum;
            if (i > 0)
                currSum = ps[j] - ps[i - 1];
            else
                currSum = ps[j];

            maxSub = max(currSum, maxSub);
        }
    }
    delete[] ps;
    return maxSub;
}

int maxSubarrayVersion4(int *arr, int n)
{
    int curr = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr < 0)
            curr = 0;

        total = max(total, curr);
    }

    return total;
}

void characterArraysHW()
{
    char sentence[1000];
    char temp = cin.get();

    int len = 0;

    while (temp != '#' && len < 1000)
    {
        sentence[len++] = temp;
        temp = cin.get();
    }
    sentence[len] = '\0';
    cout << "\nLength: " << len << endl;
    cout << sentence << endl;
}

void giveAlphaDigitsSpaces()
{
    cout << "Give a sentence with digits, spaces and letters: " << endl;

    char ch;
    ch = cin.get();
    int alpha = 0, space = 0, digit = 0;
    while (ch != '\n')
    {
        if (ch >= '0' && ch <= '9')
            digit++;
        else if ((ch >= 'a' && ch <= 'z') or (ch >= 'A' && ch <= 'Z'))
            alpha++;
        else if (ch == ' ' or ch == '\t')
            space++;

        ch = cin.get();
    }

    cout << "\t1.Total alphabets: " << alpha << endl;
    cout << "\t2.Total spaces: " << space << endl;
    cout << "\t3.Total digits: " << digit << endl;
}

void characterArrays()
{
    cout << "Usage by default:" << endl;
    char sentence[1000];
    cin.getline(sentence, 1000);
    cout << sentence << endl;
    cout << "With character termination . => cin.getline(paragraph,100,'.')" << endl;
    char paragraph[1000];
    cin.getline(paragraph, 1000);
    cout << paragraph << endl;
}

void shortestPath()
{
    char route[1000];
    cin.getline(route, 1000);

    int x = 0, y = 0;

    for (int i = 0; route[i] != '\0'; i++)
    {
        switch (route[i])
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'W':
            x--;
            break;
        case 'E':
            y++;
            break;
        }
    }
    cout << "Final x and y is: " << x << "," << y << "." << endl;

    if (x >= 0 and y >= 0)
    {
        while (y--)
        {
            cout << "N";
        }
        while (x--)
        {
            cout << "E";
        }
    }

    else if (x <= 0 and y <= 0)
    {
        while (x++)
        {
            cout << "O";
        }
        while (y++)
        {
            cout << "S";
        }
    }

    else if (x <= 0 and y >= 0)
    {
        while (x++)
            cout << "O";
        while (y--)
            cout << "N";
    }
    else
    {
        while (x--)
            cout << "E";
        while (y++)
            cout << "N";
    }
}

/*
C-style arrays: 3 IMPORTANT functions:

char a[1000] = "apple";
char b[1000];

cout<<strlen(a)<<endl; //(always +1 because of '\0')
strcpy(b,a); //in b put the content of a
cout<<b<<endl;

cout<<strcmp(a,b)<<endl; //give 0

char web[] = "www.";
char domain[] = "codingminutes.com";

strcpy(b,strcat(web,domain));
cout<<b;

cout<<strcmp(a,b)<<endl; //<0;
cout<<strcmp(b,a)<<endl; //>0;
*/

void largestString()
{
    int n;
    cin >> n;
    cin.get();
    char sentence[1000];
    char largest[1000];

    int largest_len = 0;
    while (n--)
    {
        cin.getline(sentence, 1000);
        int len = strlen(sentence);
        if (len > largest_len)
        {
            largest_len = len;
            strcpy(largest, sentence);
        }
    }

    cout << "The largest sentence is: " << largest << "\n and its length is :" << largest_len << endl;
}