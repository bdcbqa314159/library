#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    typedef long long int lli;
    lli n;
    cin >> n;
    lli arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    lli total = 0, m = arr[0];
    for (int i = 1; i < n; i++)
    {
        total += max(0LL, m - arr[i]);
        m = max(m, arr[i]);
    }
    cout << total << endl;

    return 0;
}