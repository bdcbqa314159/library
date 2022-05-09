#include "../include/cppTutorial2_bits/edge.hpp"
#include <iostream>
#include <iomanip>

namespace dijkstra
{
    Edge::Edge(double _weight, const std::shared_ptr<Vertex> &_startVertex, const std::shared_ptr<Vertex> &_targetVertex)
        : weight(_weight), startVertex(_startVertex), targetVertex(_targetVertex)
    {
    }

    double Edge::getWeight() const
    {
        return weight;
    }

    std::shared_ptr<Vertex> Edge::getStartVertex() const
    {
        return startVertex;
    }

    std::shared_ptr<Vertex> Edge::getTargetVertex() const
    {
        return targetVertex;
    }
}

namespace bellmanFord
{

    Edge::Edge(Vertex *startVertex, Vertex *targetVertex, int weight)
    {
        this->weight = weight;
        this->startVertex = startVertex;
        this->targetVertex = targetVertex;
    }

    int Edge::getWeight() const
    {
        return weight;
    }

    void Edge::setWeight(int weight)
    {
        this->weight = weight;
    }

    Vertex *Edge::getStartVertex() const
    {
        return startVertex;
    }

    void Edge::setStartVertex(Vertex *startVertex)
    {
        this->startVertex = startVertex;
    }

    Vertex *Edge::getTargetVertex() const
    {
        return targetVertex;
    }

    void Edge::setTargetVertex(Vertex *targetVertex)
    {
        this->targetVertex = targetVertex;
    }

}