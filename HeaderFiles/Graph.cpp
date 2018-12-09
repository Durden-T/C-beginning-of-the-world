#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <forward_list>
#include <climits>
#include <list>
#include <set>
using namespace std;

#define ElemType int
#define NONE -1
using Graph = vector<Vertex *>;
struct Edge
{
    int start;
    int end;
    int weight;
    Edge(int _start, int _end, int _weight) : start(_start), end(_end), weight(_weight){};
};

struct Vertex
{
    ElemType val;
    forward_list<Edge *> to;
};

void addEdge(Graph &G, int start, int end, int weight = 1)
{
    G[start]->to.push_front(new Edge(start, end, weight));
}
void undirAddEdge(Graph &G, int start, int end, int weight = 1)
{
    addEdge(G, start, end, weight);
    addEdge(G, end, start, weight);
}
//有向无环图
vector<int> topologicalSort(Graph &G)
{
    vector<int> ans(G.size());
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
    if (count != G.size())
        cerr << "Graph has a cycle.\n";
        return {};
    return ans;
}

//single-source
//vector<int> len(G.size(), INT_MAX),path(G.size(),NONE);
void unweightedShortestPaths(Graph &G, int start, vector<int> &len, vector<int> &path)
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
void dijkstra(Graph &G, int start, vector<int> &len, vector<int> &path)
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
/*
//undirected
void prim(Graph &G, Graph &NG)
{
    
}*/


//有向
//连通 度均为偶数
//先确定有欧拉回路才能用
list<int> eulerCircuit(Graph &G)
{
    list<int> ans, t;
    set<Edge *> visited;
    t.push_back(0);
    helper(G, t, ans, visited);
    return ans;
}

void helper(Graph &G, list<int> &t, list<int> &ans, set<Edge *> &visited)
{
    if (t.size() > 1 && t.back() == t.front())
    {
        if (ans.empty())
            ans = t;
        else
        {
            auto it = find(ans.begin(), ans.end(), t.front());
            t.pop_back();
            ans.splice(it, t);
        }
        return;
    }

    for (auto e : G[t.back()]->to)
    {
        if (!visited.count(e))
        {
            visited.insert(e);
            int tmp = t.back();
            t.push_back(e->end);
            helper(G, t, ans, visited);
            t.pop_back();
            t.clear();
            t.push_back(tmp);
        }
    }
}
