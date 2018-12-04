#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <forward_list>
using namespace std;

#define ElemType int

struct Graph
{
    ElemType val;
    forward_list<int> to;
};
//有向无环图
vector<int> topologicalSort(vector<Graph *> &G)
{
    vector<int> ans(G.size());
    int inDegree[G.size()] = {};
    queue<int> Q;
    int count = 0;

    for (auto node : G)
        for (int i : node->to)
            ++inDegree[i];

    for (int i = 0; i < G.size(); ++i)
        if (!inDegree[i])
            Q.push(i);

    while (!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        ans[count++] = t;
        for (int i : G[t]->to)
            if (--inDegree[i] == 0)
                Q.push(i);
    }
    if (count != G.size())
    {
        cerr << "Graph has a cycle.\n";
        return {};
    }
    return ans;
}