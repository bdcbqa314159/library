#ifndef EDGE_H
#define EDGE_H

#include "vertex.hpp"

namespace dijkstra
{
    using namespace dijkstra;
    class Vertex;
    class Edge
    {
        double weight;
        std::shared_ptr<Vertex> startVertex;
        std::shared_ptr<Vertex> targetVertex;

    public:
        Edge(double weight, const std::shared_ptr<Vertex> &startVertex, const std::shared_ptr<Vertex> &targetVertex);

        double getWeight() const;
        std::shared_ptr<Vertex> getStartVertex() const;
        std::shared_ptr<Vertex> getTargetVertex() const;
    };
}

namespace bellmanFord
{

    using namespace bellmanFord;
    class Vertex;

    class Edge
    {

        int weight;
        Vertex *startVertex;
        Vertex *targetVertex;

    public:
        Edge(Vertex *startVertex, Vertex *targetVertex, int weight);

        int getWeight() const;

        void setWeight(int weight);

        Vertex *getStartVertex() const;

        void setStartVertex(Vertex *startVertex);

        Vertex *getTargetVertex() const;

        void setTargetVertex(Vertex *targetVertex);
    };

}

#endif