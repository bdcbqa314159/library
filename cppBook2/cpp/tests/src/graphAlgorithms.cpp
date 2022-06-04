#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Graph representation
/*
Adjacency Lists:
vector<int> adj[N];
adj[1].push_back(2); =>from 1 to 2; if is undirected we need to add:adj[2].push_back(1);
adj[2].push_back(3);
adj[2].push_back(4);
adj[3].push_back(4);
adj[4].push_back(1);

for weighted:
vector<pair<int, int>> adj[N];
adj[1].push_back({2,5}); =>from 1 to 2 with weight 5; if is undirected we need to add:adj[2].push_back({1,5});
adj[2].push_back({3,7});
adj[2].push_back({4,6});
adj[3].push_back({4,5});
adj[4].push_back({1,2});

looping through the nodes:
for (auto u: adj[s]){
    // process node u;
}

Adjacency Matrix:
int adj[N][N]; adj[0][1] = 1 => from 0 to 1 with weight 1;

Edge List:
vector<pair<int,int>> edges;
edges.push_back({1,2}); =>link between from 1 to 2;
edges.push_back({2,3});
edges.push_back({2,4});
edges.push_back({3,4});
edges.push_back({4,1});

if weighted:
vector<tuple<int,int,int>> edges;
edges.push_back({1,2,5}); =>link between from 1 to 2 with weight 5;
edges.push_back({2,3,7});
edges.push_back({2,4,6});
edges.push_back({3,4,5});
edges.push_back({4,1,2});
*/

// Graph Traversal
/*
Depth-First Search (DFS) O(n+m) n: nodes, m:edges
We assume adj list
vector<int> adj[N];
bool visited[N]; =>very important

void dfs(int s){
    if (visited[s]) return;
    visited[s] = true;

    for (auto u : adj[s]){
        dfs(u);
    }
}

Breadth-First Search (BFS) O(n+m) n: nodes, m:edges

queue<int> q;
bool visited[N];
int distance[N]; =>useful for minimum distance path algorithms;
from node x:
visited[x] = true;
distance[x] = 0;
q.push(x);
while(!q.empty()){
    int s = q.front(); q.pop();
    // process node s;
    for (auto u: adj[s]){
        if (visited[u]) continue;
        visited[u] = true;
        distance[u] = distance[s]+1;
        q.push(u);
    }
}

Applications:
DFS is easier to implement in practice => important to remember.

Connectivity Check.
Cycle Detection even if can rely to the fact that components with c nodes has c-1 edges (if no connection) else we have cycle.
Bipartite graph: using X&Y colors and switching from X in one node to Y to all its neighbours.
*/

// Shortest Paths
/*
Bellman-Ford Algorithm
for (int i = 1; i<=n; i++){
    distance[i] = INT_MAX;
}
distance[x] = 0;
for (int i = 1; i<=n-1; i++){
    for (auto e: edge){
        int a,b,w;
        tie(a,b,w) = e;
        distance[b] = min(distance[b], distance[a]+w);
    }
}
Note: Bellman-Ford Algorithm can be also used to detect negative cycles.

Dijkstra's Algorithm
priority_queue<pair<int,int>>q;
for (int i = 1; i<=n; i++){
    distance[i] = INT_MAX;
}

distance[x] = 0;
q.push({0,x});

while (!q.empty()){
    int a = q.top().second; q.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (auto u: adj[a]){
        int b = u.first, w = u.second;
        if (distance[a]+w < distance[b]){
            distance[b] = distance[a]+w;
            q.push({-distance[b],b});
        }

    }

}
Note: This Algorithm does not support negative weights.

Floyd-Warshall Algorithm
for (int i = 1; i<=n; i++){
    for (int j = 1; j<= n; j++){
        if (i==j) dist[i][j] = 0;
        else if (adj[i][j]) dist[i][j] = adj[i][j];
        else dist[i][j] = INT_MAX;
    }
}

for (int k = 1; k<=n; k++){
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}

Only a good choice if the dataset is small because this O(n^3);
*/

// Directed Acyclic Graphs
/*
DAG in short -> no cycles inside.

Topological Sorting -> if there is a path from a to b in that order => there is no cycle because the ordering.

Dynamic Programming
DP useful regarding paths in DAG:
What is the longest/shortest path from a to b;
How many different paths are there;
What is the minimum/maximum number of edges in a path;
Which nodes appear in every possible path.
Attention these questions are hard for general graphs -> we need DAG.

Two problems to think about: processing shortest path & coin problem revisited.
*/

// Successor Graphs
/*
Successor is seen as a function from node a to node b: succ(a) = b.
Cycle detection:
a = succ(x);
b = succ(succ(x));
while (a != b){
    a = succ(a);
    b = succ(succ(b));
}
a = x;
while (a!=b){
    a = succ(a);
    b = succ(b);
}
first = a;

b = succ(a);
lenght = 1;
while (a != b){
    b = succ(b);
    lenght++;
}

*/

// Minimum Spanning Trees
/*
Spanning Tree: It is the reduced connection between all the edges.
Minimum Spanning Tree: It is a spanning tree with the minimal cost of weights.

Kruskal's Algorithm
Better with edge list representation.

for (...){
    if (!same(a,b)) unite(a,b);
}

Union-Find Structure.
A way to create disjoint sets.

for (int i = 1; i<=n; i++) link[i] = i;
for (int i = 1; i<=n; i++) size[i] = 1;

int find(int x){
    while (x!=link[x]) x = link[x];
    return x;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (size[a]<size[b]) swap(a,b);
    size[a] += size[b];
    link[b] = a;
}

int find(int x){
    if (link[x]) return x;
    return link[x] = find(link[x]);
}

Prim's Algorithm: Very similar to Dijkstra's.

*/

int main()
{

    return 0;
}