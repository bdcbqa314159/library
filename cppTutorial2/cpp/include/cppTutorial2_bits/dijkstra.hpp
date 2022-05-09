#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "vertex.hpp"
#include "edge.hpp"

namespace dijkstra
{
    class DijkstraAlgorithm
    {
    public:
        void computePaths(std::shared_ptr<Vertex> sourceVertex);
        std::vector<Vertex *> getShortestPath(std::shared_ptr<Vertex> vertex) const;
    };

}

#endif