#include <cppTutorial2>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;
using namespace bellmanFord;

int main()
{
    vector<bellmanFord::Vertex> vertexList;

    vertexList.push_back(bellmanFord::Vertex("A"));
    vertexList.push_back(bellmanFord::Vertex("B"));
    vertexList.push_back(bellmanFord::Vertex("C"));
    vertexList.push_back(bellmanFord::Vertex("D"));
    vertexList.push_back(bellmanFord::Vertex("E"));
    vertexList.push_back(bellmanFord::Vertex("F"));
    vertexList.push_back(bellmanFord::Vertex("G"));
    vertexList.push_back(bellmanFord::Vertex("H"));

    vector<bellmanFord::Edge> edgeList;
    edgeList.push_back(bellmanFord::Edge(&vertexList[0], &vertexList[1], 5));
    edgeList.push_back(bellmanFord::Edge(&vertexList[0], &vertexList[4], 9));
    edgeList.push_back(bellmanFord::Edge(&vertexList[0], &vertexList[7], 8));
    edgeList.push_back(bellmanFord::Edge(&vertexList[1], &vertexList[3], 12));
    edgeList.push_back(bellmanFord::Edge(&vertexList[1], &vertexList[4], 15));
    edgeList.push_back(bellmanFord::Edge(&vertexList[1], &vertexList[7], 4));
    edgeList.push_back(bellmanFord::Edge(&vertexList[2], &vertexList[3], 3));
    edgeList.push_back(bellmanFord::Edge(&vertexList[2], &vertexList[6], 11));
    edgeList.push_back(bellmanFord::Edge(&vertexList[3], &vertexList[6], 9));
    edgeList.push_back(bellmanFord::Edge(&vertexList[4], &vertexList[5], 4));
    edgeList.push_back(bellmanFord::Edge(&vertexList[4], &vertexList[6], 20));
    edgeList.push_back(bellmanFord::Edge(&vertexList[4], &vertexList[7], 5));
    edgeList.push_back(bellmanFord::Edge(&vertexList[5], &vertexList[2], 1));
    edgeList.push_back(bellmanFord::Edge(&vertexList[5], &vertexList[6], 13));
    edgeList.push_back(bellmanFord::Edge(&vertexList[7], &vertexList[2], 7));
    edgeList.push_back(bellmanFord::Edge(&vertexList[7], &vertexList[5], 6));

    BellmanFord bellmannFordAlgorithm = BellmanFord(vertexList, edgeList);
    size_t start = 0, end = 6;
    bellmannFordAlgorithm(start, end);

    return 0;
}