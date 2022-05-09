#include "../include/cppTutorial2_bits/vertex.hpp"
#include "../include/cppTutorial2_bits/edge.hpp"
#include <iostream>
#include <cassert>

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

namespace dijkstra
{
    Vertex::Vertex(std::string const &name)
    {
        this->name = name;
    }

    std::string Vertex::getName() const
    {
        return name;
    }

    void Vertex::addNeighbour(Edge *edge)
    {
        if (edge)
        {
            assert(edge->getStartVertex().get() == this);
            adjacenciesList.push_back(edge);
        }
    }

    const std::vector<Edge *> &Vertex::getAdjacenciesList()
    {
        return adjacenciesList;
    }

    Vertex *Vertex::getPredecessor() const
    {
        return predecessor;
    }

    void Vertex::setPredecessor(Vertex *predecessor)
    {
        this->predecessor = predecessor;
    }

    double Vertex::getMinDistance() const
    {
        return minDistance;
    }

    void Vertex::setMinDistance(double distance)
    {
        minDistance = distance;
    }

    std::ostream &operator<<(std::ostream &strm, const Vertex &vert)
    {
        strm << vert.name;
        return strm;
    }

    bool Vertex::operator<(const Vertex &other) const
    {
        return minDistance < other.minDistance;
    }

}

namespace bellmanFord
{
    Vertex::Vertex(std::string id)
    {
        this->id = id;
    }

    int Vertex::getMinDistance() const
    {
        return minDistance;
    }

    void Vertex::setMinDistance(int minDistance)
    {
        this->minDistance = minDistance;
    }

    Vertex *Vertex::getPreviousVertex() const
    {
        return previousVertex;
    }

    void Vertex::setPreviousVertex(Vertex *previousVertex)
    {
        this->previousVertex = previousVertex;
    }

    bool Vertex::isVisited() const
    {
        return visited;
    }

    void Vertex::setVisited(bool visited)
    {
        this->visited = visited;
    }

    std::ostream &operator<<(std::ostream &strm, const Vertex &vertex)
    {
        strm << vertex.id;
        return strm;
    }

}
