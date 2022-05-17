#include <iostream>
#include <vector>

using namespace std;

/*
// Maximum subarray sum
// O(n^3):
int best = 0;
for (int a = 0; a < n; a++)
{
    for (int b = a; b < n; b++)
    {
        int sum = 0;
        for (int k = a; k <= b; k++)
            sum += array[k];
        best = max(best, sum);
    }
}
return best;

// O(n^2)
int best = 0;
for (int a = 0; a < n; a++)
{
    int sum = 0;
    for (int b = a; b < n; b++)
    {
        sum += array[b];
        best = max(best, sum);
    }
}
return best;
// O(n)
int best = 0, sum = 0;
for (int k = 0; k<n; k++){
    sum = max(array[k], array[k]+sum);
    best = max(sum, best);
}
return best;*/

int main()
{
    cout << "Basics with O notations, examples and implementation of maximum subarray problem with 3 O complexities: n^3, n^2 -> n.\n";

    return 0;
}