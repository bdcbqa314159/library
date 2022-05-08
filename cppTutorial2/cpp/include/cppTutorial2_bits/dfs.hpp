#ifndef DFS_H
#define DFS_H

#include "vertex.hpp"
#include <vector>
#include <memory>
#include <iostream>

class DFS
{
    std::vector<std::shared_ptr<Vertex>> vertexList;

public:
    DFS(std::vector<std::shared_ptr<Vertex>> const &vertexList);
    void operator()();
    void printVertices() const;

private:
    void dfs(Vertex *vertex);
};

#endif