#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <forward_list>
#include <climits>
using namespace std;

#define ElemType int
#define NONE -1
struct Edge
{
    int end;
    int weight;
};

struct Vertex
{
    ElemType val;
    forward_list<Edge *> to;
};
//有向无环图
void topologicalSort(vector<Vertex *> &G,vector<int>&ans)
{
    int inDegree[G.size()] = {};
    queue<int> Q;
    int count = 0;

    for (auto v : G)
        for (auto e : v->to)
            ++inDegree[e->end];

    for (int i = 0; i < G.size(); ++i)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        ans[count++] = t;
        for (auto e : G[t]->to)
            if (--inDegree[e->end] == 0)
                Q.push(e->end);
    }
    /*if (count != G.size())
        cerr << "Graph has a cycle.\n";
    */
}

//single-source
//vector<int> len(G.size(), INT_MAX),path(G.size(),NONE);
void unweightedShortestPaths(vector<Vertex *> &G, int start, vector<int> &len, vector<int> &path)
{
    len[start] = 0;
    queue<int> Q;
    Q.push(start);
    while (!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        for (auto e : G[t]->to)
            if (len[e->end] == INT_MAX)
            {
                len[e->end] = len[t] + 1;
                path[e->end] = t;
                Q.push(e->end);
            }
    }
}

//single-source
//can progress with negative weight
//no negative-circuit
//priority_queue
//vector<int> len(G.size(), INT_MAX),path(G.size(),NONE);
void Dijkstra(vector<Vertex *> &G, int start, vector<int> &len, vector<int> &path)
{
    len[start] = 0;
    auto cmp = [&len](const int a, const int b) { //extern vector<int> len;
        return len[a] > len[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> PQ;
    PQ.push(start);
    while (!PQ.empty())
    {
        int t = PQ.top();
        PQ.pop();
        for (auto e : G[t]->to)
            if (len[e->end] > len[t] + e->weight)
            {
                len[e->end] = len[t] + e->weight;
                path[e->end] = t;
                PQ.push(e->end);
            }
    }
}

