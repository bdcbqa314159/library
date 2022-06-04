#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Square Root Techniques
/*
Poor man's Algorithm.
// Data Structures -> Check this out
// Subalgorithms
    Letter Distances
    Black Squares
    Tunning Parameters
// Integer Partitions
    Knapsack Problem
    Mo's Algorithm
*/

// Segment Trees Revisited
/*
Old Example:
int sum(int a, int b){
    a += n; b+=n;
    int s=0;
    while (a<=b){
        if (a%2==1) s+=tree[a++];
        if (b%2==0) s+=tree[b--];
        a/=2; b/=2;
    }
    return s;
}

Better:
int sum(int a, int b, int k, int x, int y){
    if (b<x||a>y) return 0;
    if (a<=x && y<=b) return tree[k];
    int d = (x+y)/2;
    return sum(a,b,2*k,x,d)+sum(a,b,2*k+1,d+1,y);
}
int s = sum(a,b,1,0,n-1);

// Lazy Propagation
    Polynomials Updates
// Dynamic Trees

struc node {

    int value;
    int x,y;
    node *left, *right;
    node(int v, int x, int y):value(v), x(x), y(y){

    }
};

node *x = new node(2,0,7);

x->value = 5;

    Sparese Segment Trees
    Persistent Segment Trees
// Data Structures in Nodes

// Two Dimensional Trees
*/

// Treaps
/*
// Splitting and Merging
    Splitting
    Merging

// Implementation
struct node{
    node *left, *right;
    int weight, size, value;
    node(int v){
        left = right = NULL;
        weight = rand();
        size = 1;
        value = v;
    }
};

int size(node *treap){
    if (!treap) return 0;
    return treap->size;
}

void split(node *treap, node *&left, node *&right, int k){
    if (!treap)
        left = right = NULL;
    else{
        if (size(treap->size)<k){
            split(treap->right, treap->right, right, k-size(treap->left)-1);
            left = treap;
        }
        else{
            split(treap->left, left, treap->left, k);
            right = treap;
        }
        treap->size = size(treap->left)+size(treap->right)+1;
    }
}

void merge(node *&treap, node *left, node *right){
    if (left == NULL) treap = right;
    else if (right == NULL) treap = left;
    else{
        if (left->right<right->weight){
            merge(left->right, left->right, right);
            treap = left;
        }

        else{
            merge(right->left, left, right->left);
            treap = right;
        }
        treap->size = size(treap->left)+size(treap->right)+1;
    }
}

// Example of call:
node *treap = NULL;
merge(treap, treap, new node(1));
merge(treap, treap, new node(2));
merge(treap, treap, new node(3));
merge(treap, treap, new node(4));
node *left, *right;
split(treap, left, right, 2);
merge(treap, right, left);

// Additional Techniques
We can use treaps almost like we use segment trees.
Very efficient for reverse an array.
*/

// Dynamic Programming Optimization
/*

// Convex Hull Trick
We using the concept of cost functions and linear functions to catch the structure of the convex set.

Example: Problem with n consecutive concerts, tickets, discounts. We want to attend the last concerts and can also attend other concerts. What is the minimum price for this? Check the full description of the problem in the book.

// Divide and Conquer Optimization

cost(a,c)+cost(b,d)<=cost(a,d)+cost(d,c)
for all a<=b<=c<=d.

// Knuth's Optimization
Applicable if:
cost(b,c)<=cost(a,d)
and
cost(a,c)+cost(b,d)<=cost(a,d)+cost(b,c)
for all a<=b<=c<=d
*/

// Miscellaneous
/*
// Meet in the Middle
// Counting Subsets
    Implementation:
    int sum[1<<N];
    for (int s = 0; s<(1<<n); s++){
        sum[s] = value[s];
    }

    for (int k = 0; k<n; k++){
        for (int s = 0; s<(1<<n); s++){
            if (s&(1<<k)) sum[k]+=sum[s^(1<<k)];
        }
    }

//Parallel Binary Search

// Dynamic Connectivity
*/

int main()
{

    return 0;
}