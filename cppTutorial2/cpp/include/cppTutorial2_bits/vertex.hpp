#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>
#include <ostream>
#include <memory>
#include <numeric>
#include "edge.hpp"

class Vertex
{

private:
    int data = 0;
    bool visited = false;
    std::vector<Vertex *> neighbours;

public:
    Vertex(int data);
    ~Vertex();
    int getData() const;
    void setData(int data);

    bool isVisited() const;
    void setVisited(bool visited);
    const std::vector<Vertex *> &getNeighbourList() const;
    void addNeighbour(Vertex *neighbour);

    friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
};

namespace dijkstra
{
    using namespace dijkstra;
    class Edge;

    const int MAX_VALUE = 10e7;

    class Vertex
    {
        std::string name;
        std::vector<dijkstra::Edge *> adjacenciesList;
        Vertex *predecessor = nullptr;
        double minDistance = MAX_VALUE;

    public:
        Vertex(std::string const &name);

        std::string getName() const;

        void addNeighbour(dijkstra::Edge *edge);
        const std::vector<dijkstra::Edge *> &getAdjacenciesList();

        Vertex *getPredecessor() const;
        void setPredecessor(Vertex *predecessor);

        double getMinDistance() const;
        void setMinDistance(double distance);

        friend std::ostream &operator<<(std::ostream &strm, const Vertex &vert);

        bool operator<(const Vertex &other) const;
    };
}

namespace bellmanFord
{

    const int MAX_VALUE = 10e7;
    class Vertex
    {

    private:
        std::string id;
        bool visited;
        int minDistance = MAX_VALUE;
        Vertex *previousVertex = nullptr;

    public:
        Vertex(std::string id);

        int getMinDistance() const;

        void setMinDistance(int minDistance);

        Vertex *getPreviousVertex() const;

        void setPreviousVertex(Vertex *previousVertex);

        bool isVisited() const;

        void setVisited(bool visited);

        friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
    };

}

#endif
