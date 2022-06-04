#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Basics Techniques
/*
// Tree Traversal
A tree has no cycles -> easy to traverse.
IMPORTANT = DFS.
void dfs(int s, int e){
    for (auto u: adj[s]){
        if (u!=e) dfs(u,s);
    }
}
The traversal works dfs(x,0);

Dynamic Programming can be coupled with dfs.
void dfs(int s, int e){
    count[s] = 1;
    for (auto u: adj[s]){
        if (u == e) continue;
        dfs(u,s);
        count[s] += count[u];
    }
}

// Calculating Diameters
First Algo and general hint: always start from an arbitrary node and try to solve the problem going to the left and then to the right.
we need to compute the max length from x to any leaf.
we need to calculate the max length of a path whose highest is x.
->We can use dynamic programming to calculate the above values for all nodes in O(n) time.
Second Algo: two dfs -> choose an arbitrary node a and found the farthest node b from b. Then find the farthest node c from b and the the diameter would be the distance from b to c.
*/
// All longest Paths
/*
It is calculate the maximum lenght of a path that begins at node x for each x.
First: for every node x calculate the max length of a path that goes downwards through a child of x.
We would need to use dynamic programming and be O(n).
Second: the same but max length of a path upwards through its parent p again in O(n).
*/

// Tree Queries
/*
// Finding Ancestors
Kth ancestor of x -> ancestor(x,k) : node present k levels above x.
It could be done in O(k) but luckily we can reach O(logk).
A node always has less than n ancestors -> O(logn) and preprocessing takes O(nlogn), after this ancestor(x,k) can be calculated in O(logk).

// Subtrees and Paths.
Lowest common ancestor of two nodes is the lowest node whose subtree contains both nodes.
First Method: same technique used for kth ancestor. Now we use two pointers, we starting by pointing to the original nodes then we make them go upwards. If one of them is not at the same level we fixed the most high and keep moving up the lower one until they reach the same level and keep going upwards until reach the common ancestor in O(logn).
Second Method: Euler Tour Tree, we go through using dfs and add into an array when we walk through the node not only the first time. The common ancestor of a and b is the node with minimum depth between these nodes.

// Calculating Distances.
Query of calculate the distance between two nodes (lowest common ancestor)
depth(a)+depth(b)-2*depth(c) where c is the lowest common ancestor.

// Merging Data Structures
Considering offline algorithms.
*/
// Advanced Techniques
/*
// Centroid Decomposition
See as the mediane of the tree.
// Heavy Light Decomposition
IMPORTANT to check them out later.
*/

int main()
{

    return 0;
}