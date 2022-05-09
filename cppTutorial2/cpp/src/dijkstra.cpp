#include "../include/cppTutorial2_bits/dijkstra.hpp"
#include <set>
#include <iostream>

namespace dijkstra
{
    void DijkstraAlgorithm::computePaths(std::shared_ptr<Vertex> sourceVertex)
    {
        auto fCompare = [&](std::shared_ptr<Vertex> const &l, std::shared_ptr<Vertex> const &r)
        {
            return *l < *r;
        };

        sourceVertex->setMinDistance(0.);
        // queue data structure
        std::multiset<std::shared_ptr<Vertex>, decltype(fCompare)> queue(fCompare);
        // insert the starting vertex
        queue.insert(sourceVertex);

        while (!queue.empty())
        {
            auto iBegin = queue.begin();
            auto actualVertex = *iBegin;
            queue.erase(iBegin);

            for (const Edge *edge : actualVertex->getAdjacenciesList())
            {
                std::shared_ptr<Vertex> from = edge->getStartVertex();
                std::shared_ptr<Vertex> to = edge->getTargetVertex();

                double newDistance = actualVertex->getMinDistance() + edge->getWeight();

                if (newDistance < to->getMinDistance())
                {

                    for (auto it = queue.begin(); it != queue.end(); ++it)
                    {
                        if ((*it)->getName() == to->getName())
                        {
                            queue.erase(it);
                            break;
                        }
                    }

                    to->setMinDistance(newDistance);
                    to->setPredecessor(actualVertex.get());
                    queue.insert(to);
                }
            }
        }
    }

    std::vector<Vertex *> DijkstraAlgorithm::getShortestPath(std::shared_ptr<Vertex> vertex) const
    {
        std::cout << "Min distance: " << vertex->getMinDistance() << std::endl;

        std::vector<Vertex *> path;
        for (dijkstra::Vertex *it = vertex.get(); it != nullptr; it = it->getPredecessor())
            path.push_back(it);

        std::reverse(path.begin(), path.end());
        return path;
    }

}