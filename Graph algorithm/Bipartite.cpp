/*
判别一个图是否为二部图，利用BFS给相邻节点染不同的色
1.BFS染色的同时查看相邻节点是否有相同颜色，有的话说
明不能用两种颜色染色，不是二部图
2.同一层节点间不能有连线（自循环也不行），否则会产生奇圈，
有奇圈就不满足二色
*/
#include <iostream>
#include <queue>
#include <string.h>
#define V 4
using namespace std;

bool isBipartite(int G[][V], int src, int colorArr[])
{
    // -1表示无色，0为第一种类，1为第二种
    memset(colorArr, -1, V * 4);
    colorArr[src] = 0;
    queue<int> q;
    q.push(src);
    int end = src;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        if (G[s][s] == 1)
            return false;
        for (int i = 0; i < V; i++)
        {
            if (colorArr[i] == -1 && G[s][i]) // 没访问过
            {
                colorArr[i] = 1 - colorArr[s]; // 利用相邻点的值赋值，nice idea
                q.push(i);
            }
            else if (colorArr[i] == colorArr[s] && G[s][i])
                return false;
        }
    }
}

bool isBipartiteUtil(int G[][V]) // 针对非连通图，从每个顶点出发，考虑所有顶点
{
    
    int colorArr[V];
    memset(colorArr, -1, V * 4);

    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartite(G, i, colorArr) == false)
                return false;

    return true;
}

int main()
{
    int G[][V] = {{0, 1, 0, 1},
                  {1, 0, 1, 0},
                  {0, 1, 0, 1},
                  {1, 0, 1, 0}};
    int color[V];

    //isBipartite(G, 0, color) ? cout << "Yes" : cout << "No";
    isBipartiteUtil(G) ? cout << "Yes" : cout << "No";

    return 0;
}