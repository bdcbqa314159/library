#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
#include "nodes.hpp"

using namespace std;

class Graph
{
public:
    int v;
    list<int> *l;

    Graph(int v) : v(v)
    {
        l = new list<int>[v];
    }

    ~Graph()
    {
        delete[] l;
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
            l[j].push_back(i);
    }

    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " -> ";
            for (auto x : l[i])
            {
                cout << x << ", ";
            }
            cout << endl;
        }
        return;
    }

    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[v]{0};
        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        return;
    }

    void helper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << endl;
        for (int nbr : l[node])
        {
            if (!visited[nbr])
                helper(nbr, visited);
        }
        return;
    }

    void dfs(int source)
    {
        bool *visited = new bool[v]{0};
        helper(source, visited);
        return;
    }

    void topological_sort()
    {
        vector<int> indegree(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return;
    }
};

class GraphN
{
public:
    unordered_map<string, NodeGraph *> m;
    GraphN(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new NodeGraph(city);
        }
    }

    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }

    ~GraphN()
    {
    }

    void printAdjList()
    {
        for (auto cityPair : m)
        {
            auto city = cityPair.first;
            NodeGraph *node = cityPair.second;
            cout << city << ": --> ";

            for (auto nbr : node->nbrs)
            {
                cout << nbr << ", ";
            }
            cout << endl;
        }
        return;
    }
};

class GraphW
{

public:
    int v;
    list<pair<int, int>> *l;
    GraphW(int v) : v(v)
    {
        l = new list<pair<int, int>>[v];
    }
    ~GraphW()
    {
    }

    void addEdge(int u, int v, int wt, bool undir = true)
    {
        l[u].push_back({wt, v});
        if (undir)
        {
            l[v].push_back({wt, u});
        }
    }

    int dijkstra(int src, int dest)
    {
        vector<int> dist(v, INT_MAX);
        set<pair<int, int>> s;

        dist[src] = 0;
        s.insert({0, src});

        cout << "here" << endl;
        while (!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int currDist = it->first;

            s.erase(it);

            for (auto nbrPair : l[node])
            {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (currDist + currentEdge < dist[nbr])
                {
                    auto f = s.find({dist[nbr], nbr});

                    if (f != s.end())
                        s.erase(f);

                    dist[nbr] = currDist + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < v; i++)
            cout << "Node : " << i << " Dist " << dist[i] << endl;

        return dist[dest];
    }
};

#endif