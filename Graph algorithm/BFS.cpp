/*
宽度优先遍历（Breadth First traverse）
与树的宽度优先遍历类似，但图中可能存在圈，再次回到之前的节点
因此可以设置一个Bool数组标记是否已经到达过节点 ，简单起见可
以使用队列来遍历，利用先入先出的特性储存上级节点，依层遍历
*/
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
// 有向连通图（所有节点都可以从任一节点开始达到）
class Graph
{
    int V;
    vector<list<int>> adj; // 利用邻接表表示图
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s); // s为给定源节点
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // 本例以有向图为例子
}

void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V, false);
    list<int> queue; // BFS
    visited[s] = true;
    queue.push_back(s);
    while (!queue.empty())
    {
        s = queue.front(); // 先入先出，只有上级节点全部访问完后才会访问下级节点
        cout << s << " ";
        queue.pop_front();
        for (auto adjecent : adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

// 有向（无向非连通图）
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> bfs_traversal;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        { // 增加一个所有节点遍历，保证非连通图也可以全部访问
            queue<int> q;
            vis[i] = true;
            q.push(i);
            while (!q.empty())
            {
                int g_node = q.front();
                q.pop();
                bfs_traversal.push_back(g_node);
                for (auto it : adj[g_node])
                {
                    if (!vis[it])
                    {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}