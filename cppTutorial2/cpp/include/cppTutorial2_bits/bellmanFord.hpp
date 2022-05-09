#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>
#include "vertex.hpp"
#include "edge.hpp"

namespace bellmanFord
{
    class BellmanFord
    {
        std::vector<bellmanFord::Vertex> &vertexList;
        std::vector<bellmanFord::Edge> &edgeList;

    public:
        BellmanFord(std::vector<bellmanFord::Vertex> &_vertexList, std::vector<bellmanFord::Edge> &_edgeList)
            : vertexList(_vertexList), edgeList(_edgeList)
        {
        }

        void operator()(size_t sourceVertexIndex, size_t targetVertexIndex) const;

    private:
        bool hasCycle(bellmanFord::Edge const &edge) const;
    };
}

#endif