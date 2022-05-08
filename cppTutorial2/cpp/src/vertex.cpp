#include "../include/cppTutorial2_bits/vertex.hpp"
#include <iostream>

Vertex::Vertex(int data) : data(data)
{
}

Vertex::~Vertex()
{
}

int Vertex::getData() const
{
    return data;
}

void Vertex::setData(int data)
{
    this->data = data;
}

bool Vertex::isVisited() const
{
    return visited;
}

void Vertex::setVisited(bool visited)
{
    this->visited = visited;
}

const std::vector<Vertex *> &Vertex::getNeighbourList() const
{
    return neighbours;
}

void Vertex::addNeighbour(Vertex *neighbour) { neighbours.push_back(neighbour); }

std::ostream &operator<<(std::ostream &strm, const Vertex &vertex)
{
    strm << vertex.data;
    return strm;
}
