#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
void testingGraphs()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.printAdjList();

    cout << endl;
    cout << "BFS with this graph:" << endl;

    g.bfs(1);

    cout << "DFS with this graph:" << endl;

    g.dfs(1);

    cout << "Topological sort of the graph:" << endl;
    g.topological_sort();

    cout << "With class Node" << endl;

    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    GraphN g1(cities);

    g1.addEdge("Delhi", "London");
    g1.addEdge("New York", "London");
    g1.addEdge("Delhi", "Paris");
    g1.addEdge("Paris", "New York");

    g1.printAdjList();

    cout << "=========Dijkstra's Algorithm==========" << endl;

    GraphW g2(5);
    g2.addEdge(0, 1, 1);
    g2.addEdge(1, 2, 1);
    g2.addEdge(0, 2, 4);
    g2.addEdge(0, 3, 7);
    g2.addEdge(3, 2, 2);
    g2.addEdge(3, 4, 3);

    int origin = 0, destination = 4, minDist = g2.dijkstra(origin, destination);
    cout << "Dijkstra's between " << origin << " and " << destination << " is " << minDist << endl;

    return;
}

int main()
{
    testingGraphs();
    return 0;
}