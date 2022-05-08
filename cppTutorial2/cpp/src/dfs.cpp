#include "../include/cppTutorial2_bits/dfs.hpp"

DFS::DFS(std::vector<std::shared_ptr<Vertex>> const &vertexList) : vertexList(vertexList)
{
}

void DFS::operator()()
{
    for (auto vertex : vertexList)
    {
        if (!vertex->isVisited())
            dfs(vertex.get());
    }
    std::cout << std::endl;
}

void DFS::dfs(Vertex *vertex)
{
    std::cout << *vertex << std::endl;
    for (Vertex *v : vertex->getNeighbourList())
    {
        if (!v->isVisited())
        {
            v->setVisited(true);
            dfs(v);
        }
    }
}

void DFS::printVertices() const
{
    for (auto vertex : vertexList)
    {
        std::cout << *vertex << std::endl;
    }
}
