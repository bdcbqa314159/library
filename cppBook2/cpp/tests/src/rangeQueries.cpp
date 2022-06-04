#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Sum Queries
/*
sum_q(a,b) -> look for prefix sum array.
sum_q(a,b) = sum_q(0,b)-sum_q(0,a-1)
It is possible to generalis to higher dimensions.
*/

// Minimum Queries
/*
min_q(a,b) -> sparse table algorithm.
min_q(a,b) = min(min_q(a, a+w-1), min_q(a+w, b))
where b-a+1 is a power of 2 and w = (b-a+1)/2;
then min_q(a,b) = min(min_q(a, a+k-1), min_q(b-k+1, b))
where k max of i such as 2^i<b-a+1
*/

// Tree Structure
/*
// Binary Indexed Trees (Fenwick Tree)
Could be see it as a variant of prefix sum array.
p(k) max of 2^i such as 2^i|k
tree[k] = sum_q(k-p(k) + 1-k)
sum_q(a,b) = sum_q(1,b)-sum_q(1,a-1)
Essential p(k) = k&-k

int sum(int k){
    int s = 0;
    while (s>=1){
        s+=tree[k];
        k-=k&-k;
    }
    return s;
}

void add(int k, int x){
    while (k<=n){
        tree[k]+=x;
        k += k&-k;
    }
}
*/

// Segment Trees
/*
It is a binary tree where the bottom elements are the elements of the array and the
elements above are the elements needed for processing range queries.
sum_q(a,b):
int sum(int a, int b){
    a +=n; b += n;
    int s = 0;
    while (a<=b){
        if (a%2 == 1) s+=tree[a++];
        if (b%2 == 0) s+=tree[b--];
        a/=2; b/2;
    }
    return s;
}

void add (int k, int x){
    k += n;
    tree[k] += x;
    for (k/=2; k>=1; k/=2){
        tree[k] = tree[2*k]+tree[2*k+1];
    }
}
*/
// Additional Techniques
/*
Topics: Index compression & Range updates
*/

int main()
{

    return 0;
}