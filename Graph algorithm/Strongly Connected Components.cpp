/*
利用Kosaraju算法找到图中的强连通分量
首先DFS/BFS，用stack保存顶点，然后反转方向，按stack反向DFS/BFS
输出SCC
*/
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V; 
	list<int> *adj; 

	void fillOrder(int v, bool visited[], stack<int> &Stack);
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void printSCCs();
	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) // 按顺序将顶点填充栈
{
	
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			fillOrder(*i, visited, Stack);

	// All vertices reachable from v are processed by now, push v
	Stack.push(v);
}


void Graph::printSCCs()
{
	stack<int> Stack;

	
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Fill vertices in stack according to their finishing times
	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			fillOrder(i, visited, Stack);

	// Create a reversed graph
	Graph gr = getTranspose();

	// 刷新visited，为第二次DFS做准备
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Now process all vertices in order defined by Stack
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// Print Strongly connected component of the popped vertex
		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	cout << "Following are strongly connected components in "
			"given graph \n";
	g.printSCCs();

	return 0;
}
