#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Strong Connectivity
/*
Directed Graph can be strongly connected graph.
A directed graph can always be divided into strongly connected components.
Link with topological sort and dynamic programming.

Kosaraju's Algorithm
Searchs the strongly connected components and proceed with 2 dfs.

2SAT Problem & 3SAT Problem

*/

// Complete Paths
/*
Eulerian & Hamiltonian paths: the first visits each edge exactly once wether the other does it with the nodes.

// Eulerian paths -> Hierholzer's algorithm for constuct it. We can also have an Eulerian circuit.
// Hamiltonian paths -> We can also have Hamiltonian circuit. Problems related with it are NP-hard.
*/

// Applications
/*
De Bruijin Sequences (Eulerian)
Knight's Tours (Hamiltonian) -> Warnsdorf.

*/

// Maximum Flows
/*
In principle: directed weighted graph with two special nodes - the source and the sink.
This problem is closely related to the minimum cut problem.

// Ford-Fulkerson algorithm.
We can use dfs for finding a path but also the Edmonds-Karp algorithm with a bfs.
We can also use the capacity scaling algorithm with dfs.
This algorithm can give as well an answer for the minimum cuts problem.

// Disjoint Paths
Same configuration: source & sink nodes - we want to find the maximum number of disjoint paths from the source to the sink.

Two problems that could be see as maximum flows problem.
Edge-Disjoint Path.
Node-Disjoint Path.

// Maximum Matchings
A maximum matching of a graph is a maximum-size set of node pairs where each pair is connected with an edge and each node belongs to at most one pair.
The problem is easier if we assume that the graph is bipartite.

Hall's Theorem.
König's Theorem.

// Path Covers
A path cover is a set of pahs in a graph such that each node of the graph belongs to at least on path.

Node-Disjoint Path Covers.
General Path Covers.

Dilworth's Theorem.

// DFS trees
Biconnectivity - A connected graph is called biconnected if it remains connected after removing any single node (and its edges) from the graph.

Eulerian Subgraphs - An Eulerian subgraph of a graph contains the nodes of the graph and a subset of the edges such that the degree of each node is even.

*/

int main()
{

    return 0;
}