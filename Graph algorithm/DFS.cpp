/*
深度优先遍历（Depth First Traverse）
图的遍历相较于树的遍历，在于有圈，需要用一个数组保存是否visit
本例使用递归的方法，当然也可以使用栈的结构
*/
#include <iostream>
#include <map>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    map<int, bool> visited; // bool默认为0
    map<int, list<int>> adj;

public:
    Graph(){};
    Graph(const Graph &);
    void addEdge(int v, int w);
    void DFS(int v);
    void DFSUtil(int v);  // 对于非连通图
    void DFSStack(int v); // 使用栈不使用递归
};
Graph::Graph(const Graph &G)
{

    this->adj = G.adj; // 相当于刷新visited数组
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    for (auto adjcent : adj[v])
    {
        if (!visited[adjcent]) // 递归调用，找到
            DFS(adjcent);
    }
}
void Graph::DFSUtil(int v)
{
    for (auto adjcent : adj) // 遍历一遍所有节点
        if (!visited[adjcent.first])
            DFS(adjcent.first);
}

void Graph::DFSStack(int v)
{
    visited[v] = true;
    stack<int> s;
    s.push(v); // 利用先进后出的结构
    cout << v << " ";
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        for (auto adjcent : adj[temp])
        {
            if (!visited[adjcent])
            {
                s.push(adjcent);
                visited[adjcent] = true;
                cout << adjcent << " ";
            }
        }
    }
}

int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    cout << endl
         << "非连通图也可以使用：";
    Graph h = g; // 拷贝构造函数，刷新visted数组
    h.DFSUtil(2); // 遍历顺序可能与DFS不一样
    cout << endl
         << "使用栈： ";
    Graph l = g;
    l.DFSStack(2);
    return 0;
}
