/*
拓扑排序
使用栈+递归DFS遍历节点，只有所有邻接点入栈，该顶点入栈
随之完成拓扑排序的顺序
*/
#include <iostream>
#include <list>
#include <stack>
#include <string.h>
using namespace std;

// 邻接表
class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[],
                             stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    for (auto adjcent : adj[v])
        if (!visited[adjcent])
            topologicalSortUtil(adjcent, visited, Stack);
    Stack.push(v); // 当所有邻接点都进入栈中，才将该顶点置入栈中
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    bool visited[V];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);

     while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}