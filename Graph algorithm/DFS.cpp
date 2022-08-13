/*
深度优先遍历（Depth First Traverse）
图的遍历相较于树的遍历，在于有圈，需要用一个数组保存是否visit
*/
#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
public:
    map<int, bool> visited; // bool默认为0
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS(int v);
    void DFSUtil(int v); // 对于非连通图
};

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
    for(auto adjcent: adj) // 遍历一遍所有节点
        if(!visited[adjcent.first])
            DFS(adjcent.first);
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
    //g.DFS(2);
    g.DFSUtil(2); // 遍历顺序可能与DFS不一样

 
    return 0;
}
