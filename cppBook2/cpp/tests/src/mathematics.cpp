#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Number Theory
/*
// Primes and Factors
bool prime(int n){
    if (n<2) return false;
    for (int x = 2; x*x<=n ; x++){
        if (n%x == ) return false;
    }
    return true;
}

vector<int> factors(int n){
    vector<int> f;
    for (int x = 2; x*x<=n; x++){
        while (n%x==0){
            f.push_back(x);
            n/=x;
        }
    }
    if (n>1) f.push_back(n);
    return f;
}
// Sieve of Eratosthenes
for (int x = 2; x<=n; x++){
    if (sieve[x]) continue;
    for (int u = 2*x; u<=n; u+=x){
        sieve[u] = 1;
    }
}
// Euclid's Algorithm
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b,a%b);
}

tuple<int,int,int> gcd(int a, int b){
    if (b==0){
        return {1,0,a};
    }
    else{
        int x,y,g;
        tie(x,y,g) = gcd(b,a%b);
        return {y,x-(a/b)*y,g};
    }
}
int x,c,g;
tie(x,y,g) = gcd(30,12);
cout<<x<<" "<<y<<" "<<g<<"\n";

// Modular Eponentiation
int modpow(int x, int n, int m){
    if (n==0) return 1%m;
    long long u = modpow(x, n/2, m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

// Euler's Theorem
// Fermat's litlle Theorem
// Modular Multiplicative Inverses
// Diophantine Equations
// Chinese Remainder Theorem
*/

// Combinatorics
/*
// Binomial Coefficients
// Multinomial Coefficients
// Boxes and Balls
// Catalan Numbers
// Inclusion-Exclusion
// Burnside's Lemma
// Cayley's Formula
*/

// Matrices
/*
// Matrix operations
// Product of matrices:
for (int i = 1; i<=n; i++){
    for (int j = 1; j<=n; j++){
        for (int j = 1; k<=n; k++)
            C[i][j]+=A[i][k]*B[k][j];
    }
}
Strassen found an efficient algorithm for matrix product O(n^2.81)<<O(n^3)
// Linear Recurrences
Fibonacci Numbers
// Grpahs & Matrices
// Gaussian Elimination
*/

// Probability
/*
// Working with Events
// Random Variables
// Markov Chains
// Randomized Algorithms
Monte Carlo & Las Vegas
*/

// Game Theory
/*
// Game States
// Nim Game (See also Misère Game)
// Sprague-Grundy Theorem (See also Grundy Numbers)
mex({g1, g2, ... gn}) is the smallest nonnegative number that is not in the set.
SubGames - Grundy's Game
*/

// Appendix - End of the Book.
/*
// Sum Formulas
    Arithmetic Progression
    Geometric Progression
    Harmonic Sum

// Sets
    All the classical operations meet in a Maths course.
    Common Sets of Numbers from IN to IR.

// Logic
    All classical operations meet in a Maths course.

// Functions
    Ceil & Floor
    Factorial
    Max & Min
    Fibonacci Numbers -> Binet's Formulas.

// Logarithms
    All the common properties meet in a Maths course.

// Number Systems
    Base 10, 2, general b.
    Conversion from a system to another.

*/

int main()
{

    return 0;
}