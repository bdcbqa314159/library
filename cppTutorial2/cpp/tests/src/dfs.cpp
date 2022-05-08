#include <cppTutorial2>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    vector<shared_ptr<Vertex>> graph;
    graph.resize(8);

    graph[0] = make_shared<Vertex>(1);
    graph[1] = make_shared<Vertex>(2);
    graph[2] = make_shared<Vertex>(3);
    graph[3] = make_shared<Vertex>(4);
    graph[4] = make_shared<Vertex>(5);
    graph[5] = make_shared<Vertex>(6);
    graph[6] = make_shared<Vertex>(7);
    graph[7] = make_shared<Vertex>(8);

    graph[0]->addNeighbour(graph[1].get());
    graph[0]->addNeighbour(graph[2].get());
    graph[0]->addNeighbour(graph[3].get());

    graph[1]->addNeighbour(graph[4].get());
    graph[4]->addNeighbour(graph[5].get());

    graph[2]->addNeighbour(graph[6].get());

    graph[3]->addNeighbour(graph[7].get());

    DFS dfs(graph);

    dfs();
    cout << endl;

    return 0;
}