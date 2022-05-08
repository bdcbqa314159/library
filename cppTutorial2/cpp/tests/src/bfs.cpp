#include <cppTutorial2>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    BFS bfs;
    shared_ptr<Vertex> vertex1 = make_shared<Vertex>(1);
    shared_ptr<Vertex> vertex2 = make_shared<Vertex>(2);
    shared_ptr<Vertex> vertex3 = make_shared<Vertex>(3);
    shared_ptr<Vertex> vertex4 = make_shared<Vertex>(4);

    shared_ptr<Vertex> vertex5 = make_shared<Vertex>(5);
    shared_ptr<Vertex> vertex6 = make_shared<Vertex>(6);
    shared_ptr<Vertex> vertex7 = make_shared<Vertex>(7);
    shared_ptr<Vertex> vertex8 = make_shared<Vertex>(8);

    vertex1->addNeighbour(vertex2.get());
    vertex1->addNeighbour(vertex3.get());
    vertex1->addNeighbour(vertex4.get());

    vertex2->addNeighbour(vertex5.get());
    vertex5->addNeighbour(vertex8.get());

    vertex3->addNeighbour(vertex6.get());
    vertex4->addNeighbour(vertex7.get());

    bfs(vertex1);

    cout << endl;

    // BFS bfs1;

    // shared_ptr<Vertex> vertex1 = make_shared<Vertex>("A");
    // shared_ptr<Vertex> vertex2 = make_shared<Vertex>("B");
    // shared_ptr<Vertex> vertex3 = make_shared<Vertex>("C");
    // shared_ptr<Vertex> vertex4 = make_shared<Vertex>("D");
    // shared_ptr<Vertex> vertex5 = make_shared<Vertex>("E");
    // shared_ptr<Vertex> vertex6 = make_shared<Vertex>("F");
    // shared_ptr<Vertex> vertex7 = make_shared<Vertex>("G");
    // shared_ptr<Vertex> vertex8 = make_shared<Vertex>("H");

    // vertex1->addNeighbour(vertex2.get());
    // vertex1->addNeighbour(vertex6.get());
    // vertex1->addNeighbour(vertex7.get());

    // vertex7->addNeighbour(vertex8.get());

    // vertex2->addNeighbour(vertex3.get());
    // vertex2->addNeighbour(vertex4.get());

    // vertex4->addNeighbour(vertex5.get());

    // bfs1(vertex1);

    return 0;
}