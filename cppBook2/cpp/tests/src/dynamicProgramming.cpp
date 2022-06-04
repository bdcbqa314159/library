#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Coins problem
// int solve(int x){
//     if (x<0) return INT_MIN;
//     if (x == 0) return 0;
//     int best = INT_MAX;
//     for (auto c: coins){
//         best = min(best, solve(x-c)+1);
//     }
//     return best;
// }

// Memoization
// int solve(int x)
// {
//     int N;
//     bool ready[N];
//     int value[N];

//     if (x < 0)
//         return INT_MIN;
//     if (x == 0)
//         return 0;
//     if (ready[x])
//         return value[x];

//     int best = INT_MAX;
//     for (auto c : coins)
//     {
//         best = min(best, solve(x - c) + 1);
//     }

//     ready[x] = true;
//     value[x] = best;
//     return best;
// }

// Iterative approach
// value[0] = 0;
// for (int i = 1; x<=n; x++){
//     value[x] = INT_MAX;
//     for (auto c: coins){
//         if (x-c>=0)
//             value[x] = min(value[x], value[x-c]+1);
//     }
// }

// Constructing a solution
// int first[N];
// value[0] = 0;
// for (int x = 1; x <= n; i++)
// {
//     value[x] = INT_MAX;
//     for (auto c : coins)
//     {
//         if (x - c >= 0 && value[x - c] + 1 < value[x])
//         {
//             value[x] = value[x - c] + 1;
//             first[x] = c;
//         }
//     }
// }

// while (n>0){
//     cout<<first[n]<<endl;
//     n-=first[n];
// }

// Counting Solutions.
// count[0] = 1;
// for (int x = 1; x<=n; x++){
//     for (auto c: coins){
//         if (x-c>=0){
//             count[x] += count[x-c];
//             count[x]%=m;
//         }

//     }
// }

// Longest Increasing Subsequence
// for (int k = 0; k<n; k++){
//     length[k] = 1;
//     for (int i = 0; i<k; i++){
//         if (array[i]<array[k]){
//             length[k] = max(length[k], length[i]+1);
//         }
//     }
// }

// Paths in a Grid
// int sum[N][N];
// for (int y =1; y<=n; y++){
//     for (int x= 1; x<=1; x++)
//         sum[y][x] = max(sum[y][x-1], sum[y-1][x])+value[y][x];
// }

// Knapsack Problem
// possible[0][0] = true;
// for (int k = 1; k <= n; k++)
// {
//     for (int x = 0; x <= m; x++)
//     {
//         if (x - w[k] >= 0)
//             possible[x][k] |= possible[x - w[k]][k - 1];
//         possible[x][k] |= possible[x][k - 1];
//     }
// }

// // better way
// possible[0] = true;
// for (int k = 1; k <= n; k++)
// {
//     for (int x = m - w[k]; x >= 0; x--)
//     {
//         possible[x + w[k]] |= possible[x];
//     }
// }

// From permutations to subsets
// pair<int,int> best[1<<N];
// best[0] = {0,0};

// for (int s =1 ; s<(1<<N); s++){
//     best[s]=  {n+1,0};
//     for (int p = 0; p<n; p++){
//         if (s&(1<<p)){
//             auto option = best[s^(1<<p)];
//             if (option.second+weight[p]<=x){
//                 option.second += weight[p];
//             }
//             else{
//                 option.first++;
//                 option.second = weight[p];
//             }
//             best[s] = min(best[s], option);
//         }
//     }
// }

int main()
{

    return 0;
}