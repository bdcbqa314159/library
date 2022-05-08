#include "../include/cppTutorial2_bits/bfs.hpp"

void BFS::operator()(std::shared_ptr<Vertex> root) const
{
    std::deque<Vertex *> queue;
    root->setData(true);
    queue.push_back(root.get());

    while (!queue.empty())
    {
        Vertex *actualVertex = queue.front();
        queue.pop_front();
        std::cout << *actualVertex << ' ';

        for (Vertex *v : actualVertex->getNeighbourList())
        {
            if (!v->isVisited())
            {
                v->setVisited(true);
                queue.push_back(v);
            }
        }
    }
}
