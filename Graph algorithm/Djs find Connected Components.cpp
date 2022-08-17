/*
使用并查集寻找无向连通图中的连通分量,（有待分析）
*/
#include <bits/stdc++.h>
using namespace std;
int find(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    return find(parent, parent[x]);
}
int connectedcomponents(int n, vector<vector<int>> &edges)
{
    int parent[n];
    for (int i = 0; i < n; i++) // 初始化根节点/集合
    {
        parent[i] = i;
    }
    for (auto x : edges)
    {
        parent[find(parent, x[0])] = find(parent, x[1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (parent[i] == i);
    }
    for (int i = 0; i < n; i++)
    {
        parent[i] = find(parent, parent[i]);
    }
    map<int, list<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[parent[i]].push_back(i);
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        list<int> l = it->second;
        for (auto x : l)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<int> e1 = {0, 1};
    vector<int> e2 = {2, 3};
    vector<int> e3 = {3, 4};
    vector<vector<int>> e;
    e.push_back(e1);
    e.push_back(e2);
    e.push_back(e3);
    int a = connectedcomponents(n, e);
    cout << "total no. of connected components are: " << a
         << endl;
    return 0;
}
