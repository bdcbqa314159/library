#include "../include/cppTutorial2_bits/bellmanFord.hpp"
#include <set>
#include <iostream>

namespace bellmanFord
{
    void BellmanFord::operator()(size_t sourceVertexIndex, size_t targetVertexIndex) const
    {

        if (sourceVertexIndex >= vertexList.size() || targetVertexIndex >= vertexList.size())
            return;

        bellmanFord::Vertex &sourceVertex = vertexList[sourceVertexIndex];
        bellmanFord::Vertex &targetVertex = vertexList[targetVertexIndex];

        sourceVertex.setMinDistance(0);

        for (int i = 0; i < vertexList.size() - 1; i++)
        {

            for (auto const &edge : edgeList)
            {

                int newDistance = edge.getStartVertex()->getMinDistance() + edge.getWeight();

                if (newDistance < edge.getTargetVertex()->getMinDistance())
                {

                    edge.getTargetVertex()->setMinDistance(newDistance);

                    edge.getTargetVertex()->setPreviousVertex(edge.getStartVertex());
                }
            }
        }

        for (bellmanFord::Edge edge : edgeList)
        {
            if (edge.getStartVertex()->getMinDistance() != MAX_VALUE)
            {
                if (hasCycle(edge))
                {
                    std::cout << "Negative edge weight cycles detected!\n";
                    return;
                }
            }
        }

        if (targetVertex.getMinDistance() != MAX_VALUE)
        {
            std::cout << "There is a shortest path from source to target, with cost: " << targetVertex.getMinDistance() << '\n';

            bellmanFord::Vertex *actualVertex = &targetVertex;
            while (actualVertex != nullptr)
            {
                std::cout << *actualVertex << '-';
                actualVertex = actualVertex->getPreviousVertex();
            }

            std::cout << '\n';
        }
        else
        {
            std::cout << "There is no path from source to target...\n";
        }
    }

    bool BellmanFord::hasCycle(Edge const &edge) const
    {
        return edge.getTargetVertex()->getMinDistance() > edge.getStartVertex()->getMinDistance() + edge.getWeight();
    }
}