#ifndef BFS_H
#define BFS_H

#include "vertex.hpp"
#include <deque>
#include <memory>
#include <iostream>

class BFS
{
public:
    void operator()(std::shared_ptr<Vertex> root) const;
};

#endif