#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <ostream>

class Vertex
{

private:
    int data = 0;
    bool visited = false;
    std::vector<Vertex *> neighbours;

public:
    Vertex(int data);
    ~Vertex();
    int getData() const;
    void setData(int data);

    bool isVisited() const;
    void setVisited(bool visited);
    const std::vector<Vertex *> &getNeighbourList() const;
    void addNeighbour(Vertex *neighbour);

    friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
};

#endif
