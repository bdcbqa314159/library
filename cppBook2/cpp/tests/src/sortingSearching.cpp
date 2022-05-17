#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
Bubble Sort:
for(int i = 0; i<n; i++){
    for (int j = 0; j<n-1; j++){
        if (array[j] > array[j+!])
            swap(array[j], array[j+1]);
    }
}
Comparison based sorting algorithms are low bounded by O(nlogn)
We can achieve O(n) with counting sort in some particular cases of sorting.


bool comp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;

    else
        return a.size() < b.size();
}

// Another usage:
    vector<string> k;
    sort(k.begin(), k.end(), comp);



// Bad practice for checking double occurences
bool ok = true;
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
        if (array[i] == array[j])
            ok = false;
}
//Better approach:
bool ok = true;
for (int i = 0; i < n; i++)
{       if (array[i] == array[i+1]);           ok = false;
}

Solving problems by sorting.
Other algorithms: c.f. Sweep Algorithms.
Scheduling Events.
Tasks and Deadlines.


Binary Search: Two methods.
int a = 0, b = n-1;
while (a<=b){
    int k = (a+b)/2;
    if (array[k]==x) return k;
    else if(array[k]<x) a = k+1;
    else b = k-1;
}

int k = 0;
for (int b = n/2; b>=1; b/=2){
    while (k+b<n && array[k+b] <=x) k+=b;
}

if (array[k]==x)return k;

Optimal solution in scheduling:
int x = -1;
for (int b = z; b>=1; b/=2){
    while(!valid(x+b)) x+=b;
}
int k = x+1;



*/
int main()
{
    // Usage of stl sorting:
    vector<int> v = {4, 12, 5, 1, 3, 7, 12, 9, 2};
    sort(v.begin(), v.end());   // Increasing order;
    sort(v.rbegin(), v.rend()); // Decreasing order;

    int n = 7;
    int a[] = {4, 3, 2, 5, 6, 4, 5};
    sort(a, a + n);

    string s = "monkey";
    sort(s.begin(), s.end());

    // Usage of the comparison when dealing with udf;

    struct point
    {
        int x, y;
        bool operator<(const point &p)
        {
            if (x == p.x)
                return y < p.y;
            else
                return x < p.x;
        }
    };

    return 0;
}