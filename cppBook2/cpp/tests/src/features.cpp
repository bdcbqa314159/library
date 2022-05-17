#include <iostream>
#include <vector>

using namespace std;

/*
void search1(int k)
{
    int n;
    vector<int>
        subset(n, 1);
    if (k == n + 1)
    {
        // process subset;
    }
    else
    {
        subset.push_back(k);
        search1(k + 1);
        subset.pop_back();
        search1(k + 1);
    }
}

void search2()
{
    vector<int> permutation;
    int n;
    bool chosen[n + 1];

    if (permutation.size() == n)
    {
        // process permutation
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            search2();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        permutation.push_back(i);
    }
    do
    {
        // process permutation
    } while (next_permutation(permutation.begin(), permutation.end()));
}

void search3(int y){

    if (y == n){
        count++;
        return;
    }
    for (int x = 0; x<n; x++){
        if (col[x] || diag1[x+y]||diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search3(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }

}


*/

int main()
{
    cout << "Some tips: " << endl;
    cout << "bits/stdc++.h is only in gcc compiler but really useful." << endl;
    cout << "The usage of cout & cin ir fundamental in cp." << endl;
    cout << "ios::sync_with_stdio(0)\ncin.tie(0)\nat the top of the code can speedup cin & cout." << endl;
    cout << "the new line '\\n' is faster than endl because of the flush in endl." << endl;
    cout << "printf & scanf can speedup as well." << endl;
    cout << "check the usage in cppreference.com" << endl;
    cout << "usage of getline(cin, s) rather of cin for string" << endl;
    cout << "usage of while(cin>>x){...}" << endl;
    cout << "usage of freopen(input.txt, r, stdin)." << endl;
    cout << "usage of freopen(output.txt, r, stdout)." << endl;

    // Factorial n mod m:
    long long x = 1;
    long long m = 4;
    long long n = 25;
    for (int i = 1; i <= n; i++)
    {
        x = (x * i) % m;
    }
    cout << x << "\n";

    cout << "Modulo in c++ can give negative numbers!" << endl;
    x = x % m;
    if (x < 0)
        x += m;
    cout << x << "\n";

    cout << "Formating\n";

    float y = 127. / 13.;
    printf("%.9f\n", y);

    double z = 0.3 * 3 + 0.1;
    printf("%.20f\n", z);

    cout << "Warning: the threshold for equality between floating numbers is 1e-9!\n";

    cout << "Shortening names\n";

    cout << "typedef long long ll\n";
    cout << "typedef vector<int> vi\n";
    cout << "typedef pair<int,int> pi\n";

    cout << "Macros\n";
    cout << "#define F first\n#define S second\n#define PB push_back\n#define MP make_pair\n";
    cout << "#define REP(i,a,b) for (int i = a; i<=b; i++)\n";

    cout << "Bit manipulation\n";
    int p = -43;
    unsigned int q = p;
    cout << p << endl;
    cout << q << endl;

    int x1 = 2147483647;
    cout << x1 << endl;
    x1++;
    cout << x1 << endl;

    cout << "x divisible by 2^k exactly when x&(2^k-1)=0\n";
    cout << "kth bit of a number x is one exactly when x&(1<<k) = 0\n";

    for (int k = 31; k >= 0; k--)
    {
        if (x & (1 << k))
            cout << "1";
        else
            cout << "0";
    }

    int x = 5328;                          // 00000000000000000001010011010000
    cout << __builtin_clz(x) << "\n";      // 19
    cout << __builtin_ctz(x) << "\n";      // 4
    cout << __builtin_popcount(x) << "\n"; // 5
    cout << __builtin_parity(x) << "\n";   // 1

    cout << "Sets\n";
    int x2 = 0;
    x2 |= (1 << 1);
    x2 |= (1 << 3);
    x2 |= (1 << 4);
    x2 |= (1 << 8);

    cout << __builtin_popcount(x2) << endl;
    for (int i = 0; i < 32; i++)
    {
        if (x & (1 << i))
            cout << i << " ";
    }

    int u = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    int v = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int w = u | v;

    cout << __builtin_popcount(w) << endl;

    // Going through the subsets of {0,1,...n-1}:
    for (int b = 0; b < (1 << n); b++)
    {
        // Some stuff
    }

    // Going through the subsets of {0,1,...n-1} with exactly k elements:
    int k;
    for (int b = 0; b < (1 << n); b++)
    {
        if (__builtin_popcount(b) == k)
        {
            // some stuff
        }
    }

    // Going through the subsets of a set x
    int h = 0;
    do
    {
        // processing subset h;
    } while (h = (h - x) & x);

    cout << "Bitset" << endl;
    bitset<10> s;
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;

    cout << s[4] << " " << s[5] << endl;
    cout << s.count() << endl;

    bitset<10> a, b;
    bitset<10> c = a & b;
    bitset<10> d = a | b;
    bitset<10> e = a ^ b;

    return 0;
}