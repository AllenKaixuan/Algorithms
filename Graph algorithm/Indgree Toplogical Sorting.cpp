/*
1.一个有向无圈图总有一个拓扑排序
2.一个DAG一定存在一个没有入边的点
找到没有入度的点排在第一位，删除；然后递归找其它没有入度的节点
*/
// C++ program to print all topological sorts of a graph
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;

    list<int> *adj;

    vector<int> indegree;

    void alltopologicalSortUtil(vector<int> &res,
                                bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void alltopologicalSort();
};


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    for (int i = 0; i < V; i++) // 初始化入度
        indegree.push_back(0);
}


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    indegree[w]++; // 添加时就维护入度节点
}


void Graph::alltopologicalSortUtil(vector<int> &res,
                                   bool visited[])
{
    
    bool flag = false;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0 && !visited[i]) // 入度为0
        {
            list<int>::iterator j;
            for (j = adj[i].begin(); j != adj[i].end(); j++) // i的所有邻接点入读-1
                indegree[*j]--;

            
            res.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(res, visited); // 递归调用

            // 当递归函数全部实现后，为后面的寻找所有拓扑排序重置visited、indgree
            visited[i] = false;
            res.erase(res.end() - 1);
            for (j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]++;

            flag = true;
        }
    }

    if (!flag)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}

// 找到所有的拓扑排序
void Graph::alltopologicalSort()
{
    
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    vector<int> res;
    alltopologicalSortUtil(res, visited);
}


int main()
{
  
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "All Topological sorts\n";

    g.alltopologicalSort();

    return 0;
}
